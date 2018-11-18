const express = require('express')
const app = express()

//Muestra el número de veces que aparece cada tratamiento con los valores enviados
app.get('/prueba', (req, res) => {
  console.log("R 1");
  const { spawn } = require('child_process');
  let t = 10
  let b = 5
  let k = 4
  const child = spawn('Rscript', ['projectsAssign.R', t, b, k]);

  let out = ''
  let err = ''
  console.log("R 2");
  child.stdout.on('data', (chunk) => {
    out += chunk 
  });

  console.log("R 3");   
  child.stderr.on('data', (chunk) => {
    err += chunk
  })

  console.log("R 4");
  child.on('close', (code) => {
    if (err) console.log('STDERR:\n', err.toString())
    //res.json(JSON.parse(out.toString()))
    let assign = JSON.parse(out.toString());
    let numbers = []
    for(let i = 0; i < t; i++)
      numbers.push(0);

    console.log(assign)
    assign.forEach(current => {
      current.forEach(value => {
        numbers[value - 1]++;
      })
    })

    console.log("numbers");
    console.log(numbers);
    console.log("numbers");

    // console.log(out.toString())
    console.log(`child process exited with code ${code}`);
    res.send(out.toString())
  });
})

app.get('/', (req,res) => {
  const { spawn } = require('child_process');
  let asaltos = [679,453,692,462,733,489,835,702,790,526,805,537,920,613,843,562,450,430,912,608]
  let mes = [12,12,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9]
  let tipo = [0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1]
  const child = spawn('Rscript', ['args.R',JSON.stringify(asaltos),JSON.stringify(mes),JSON.stringify(tipo)]);

  let out = ''
  let err = ''
  child.stdout.on('data', (chunk) => {
    out += chunk
  });

  child.stderr.on('data', (chunk) => {
    err += chunk
  })

  child.on('close', (code) => {
    if (err) console.log('STDERR:\n', err)
    //res.json(JSON.parse(out.toString()))
     res.send(out.toString())
    console.log(out)
    console.log(`child process exited with code ${code}`);
  });
})

app.get('/BIB', (req,res) => {
  const { spawn } = require('child_process');
  let grades = [9, 8, 10, 9, 9, 9, 7, 6, 6, 8, 7, 7, 3, 6, 4, 6, 5, 5, 2, 2, 1, 0, 3, 2, 8, 7, 8, 8, 8, 8];
  const child = spawn('Rscript', ['qualifyProjects.R', 10, 5, 6, JSON.stringify(grades)]);

  let out = ''
  let err = ''
  child.stdout.on('data', (chunk) => {
    out += chunk
  });

  child.stderr.on('data', (chunk) => {
    err += chunk
  })

  child.on('close', (code) => {
    if (err) console.log('STDERR:\n', err)
    //res.json(JSON.parse(out.toString()))
     res.send(out.toString())
    console.log(out)
    console.log(`child process exited with code ${code}`);
  });
})

app.get('/R', (req, res) => {
  console.log("R 1");
  const { spawn } = require('child_process');
  const child = spawn('Rscript', ['projectsAssign.R', 12, 6, 5]);

  let out = ''
  let err = ''
  console.log("R 2");
  child.stdout.on('data', (chunk) => {
    out += chunk
  });

  console.log("R 3");
  child.stderr.on('data', (chunk) => {
    err += chunk
  })

  console.log("R 4");
  child.on('close', (code) => {
    if (err) console.log('STDERR:\n', err.toString())
    //res.json(JSON.parse(out.toString()))
  let assign = JSON.parse(out.toString());

  console.log("**************");
  console.log(assign[0][0]);
  console.log("**************");
    // console.log(out.toString())
    console.log(`child process exited with code ${code}`);
    res.send(out.toString())
  });
})
app.listen(3000, () => { console.log('Listening') })