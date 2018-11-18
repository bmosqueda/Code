const express = require('express');
const app = express();
const bodyParser = require('body-parser')
const axios = require('axios');
const path = require('path');
const session = require('express-session');

app.use(session({
    secret: 'ultra secret word',
    resave: true,
    saveUninitialized: true
}));

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: false }))

//Google API    -   Not working
// const {OAuth2Client} = require('google-auth-library');
// const client = new OAuth2Client('IyzW6MBzvRnVwkviANds-aIH');

//Models
const userModel = require('./models/user.model.js');
const postModel = require('./models/post.model.js');

//Classes
const User = new userModel();
const Post = new postModel();

app.set('view engine', 'html');

app.use('/static', express.static('views'))

app.get('/', async (req, res) => {
  res.sendFile(path.join(__dirname, '/views/index.html'));
  console.log('req.session.userId: ', req.session.userId);
});

app.get('/signIn/:id', (req, res) => {
  req.session.userId = req.params.id;
  req.session.name = 'Brandon Mosqueda';
  console.log('req.session.userId: ', req.session.userId);
  res.send('sigIn');
});

app.get('/logout', (req, res) => {
  req.session.destroy();
  // console.log(req.session.userId);
  res.send('logout');
});

app.get('/user', async (req, res) => {
  let user = {
    name: 'Brandon',
    token: 'asdfkhasdlfhkjsdafsd6f5sd4f654sda4f65454s6adf1sd6a51fd'
  };

  let users = await User.create(user);
  console.log(users.info.insertId);
  console.log('req.session.userId: ', req.session.userId);
  res.json(users);
});

app.get('/user/all', async (req, res) => {
  let users = await User.getAll();
  console.table(users[0]);
  console.log('req.session.userId: ', req.session.userId);
  res.json(users);
});

app.get('/user/delete/:id', async (req, res) => {
  let id = req.params.id;
  console.log(id);
  console.log(isNaN(id));

  if(!isNaN(id)) {
    try {
      let isDeleted = await User.deleteById(id);
      console.log(isDeleted);

      //Tener cuidado porque es string 
      console.log(typeof isDeleted.info.affectedRows);

      if(Number(isDeleted.info.affectedRows)) {
        res.sendStatus(204); //Succes, no data
        console.log('if');
      }
      else{
        res.sendStatus(400); //id doesn't exist
        console.log('else');
      }
    }
    catch(err){
      console.log(err.message);
      res.sendStatus(500);
    }
  }
  else{
    res.sendStatus(400);
  }
});

app.post('/token', async (req, res) => {
  const token = req.body.idToken;
  //Verify the token with google servers
  axios.get(`https://www.googleapis.com/oauth2/v3/tokeninfo?id_token=${token}`)
    .then(async ({data}) => {
      /*
        {
          'aud': this app client id,
          'name': 'Branodn',
          'picture': 'url',
          'email': 'bmosqueda@ucol.mx',
          'email_verified': true,
          'sub': idCliente (use instead of email (because this can change)) 
        }
      */
      // console.log(data);
      try {
        let userStored = await User.getByEmail(data.email);
        console.log(userStored.info.affectedRows);
        console.log(userStored[0]);
        if(userStored[0]) {
          //If the user is not in the database, register him
          //else return 200 code
          res.json(userStored[0]);
        }
        else {
          let user = {
            name: data.name,
            token: token,
            urlImage: data.picture,
            email: data.email
          };

          let result = await User.createGoogleUser(user);

          console.log(result);

          if(result) {
            user.id = result.info.insertId;
            res.json(user);
          }
          else
            res.sendStatus(500);
        }
      }
      catch(err) {
        console.log(err);
        res.status(400).json({err: err.message});
      }

    })
    .catch(err => { //Erro al conectarse o el token enviado no es válido
      console.log(err);
      res.sendStatus(400);
    });
}); 

app.use(express.static(path.join(__dirname,'/public')))
app.use(express.static(path.join(__dirname,'/views')))

app.listen(3000);
