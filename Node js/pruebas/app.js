var express = require('express');
var app = express();
var mongoose = require('mongoose');
var User = require('./models/user').User
var md5 = require('md5');
var bodyParser = require('body-parser')
var formidable = require('express-form-data');
mongoose.connect('mongodb://localhost/pruebas')

app.use(express.static(__dirname + '/views'))
app.use(bodyParser.json()); //Para peticiones aplication/json

app.use(formidable.parse({keepExtensions: true}));
app.use(bodyParser.urlencoded({extended: true}));

app.use(/*'estatico',*/express.static('public'));

app.get('/', function (req, res) {

	//deleteAll();

	User.find(function(err, doc) {
		res.send(doc);
	})

});

function deleteAll(){
	User.find(function(err, docs) {
		for(var doc in docs)
		{
			User.findOneAndRemove({id: doc["_id"]}, function(err) {
				if(err) console.log(err);
			})
		}
	})
}

app.get('/home', function(req, res) {
  res.sendFile(__dirname + "/views/index1.html");
})

app.post('/user', function(req, res) {
	var user = new User({
		name: req.body.user,
		password: req.body.password,
		passwordConfirmation: req.body.passwordConfirmation
	});

	console.log(user);

	user.save().then(function(us) {
		//Si todo sale bien
		res.send("Guardamos el usuario exitosamente");
	}, function(err) {
		//Si hay algún error
		console.log(String(err));
		res.send("Hubo un error al guardar el usuario");
	});

});

app.post("/signIn", function(req, res) {
	User.findOne({name: req.body.user/*, passwordConfirmation: req.body.password*/}, function(err, user) {
		if(user != null) {
			console.log(user.passwordConfirmation);
			res.send(user);
		}
		else {
			res.send("Usuario incorrecto")
		}
	})
})

app.post("/files", (req, res) => {
	var files = req.files;
	console.log(files);
	res.send(files);
})

app.listen(8081, function () {
  console.log('Example app listening on port 8081!');
});