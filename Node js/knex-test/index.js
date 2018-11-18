const knex = require('./knex_connection.js');  
const express = require('express');
const app = express();
const __PORT = 3000;
let names = [{name:"Pedro Salinas"},{name:"Marina Villa"},{name:" Julio César Montes"},{name:"José Sánchez"},{name:"Yolanda Cázares"},{name:"Graciela de los Santos"},{name:"Abel Magaña"},{name:"Raymundo Acosta"},{name:"Jesús Pacheco"},{name:"Ricardo Serrano"}];  
let oficios = ['Electricista', 'Fontanero', 'Albañil', 'Carpintero'];
let tipo_oficio = ['Oficina', 'Comercio', 'Almacén', 'Residencia'];
let direcciones = [{direccion:"92 Mendota Road"}, {direccion:"16 Glendale Court"}, {direccion:"0649 Pankratz Alley"}, {direccion:"41 Hooker Place"}, {direccion:"13857 Maple Wood Hill"}, {direccion:"285 Mariners Cove Trail"}, {direccion:"3 Northland Trail"}, {direccion:"4 Corscot Hill"}, {direccion:"865 Ridgeview Road"}, {direccion:"472 Bartelt Hill"} ]; 
let edificios = [];

function randomInRange(min, max) {
  return Math.random() * (max-min) + min;
}

app.get('/', (req, res) => {
  res.send('Hola mundo :D');
});

app.get('/trabajadores', (req, res) => {
  var trabajadoresPromises = [];
  for (var i = names.length - 1; i >= 0; i--) {
    let trabajador = {
      nombre: names[i].name, 
      tarifa_hora: randomInRange(50, 100),
      tipo_oficio: oficios[Math.round(Math.random() * 3)]
    };

    trabajadoresPromises.push(knex('trabajadores').insert(trabajador).returning('id'));
  }

  Promise.all(trabajadoresPromises)
    .then(data => {
      res.json(data);
    })
    .catch(err => {
      res.json(err);
    });
});

app.get('/edificios', (req, res) => {
  var edificiosPromises = [];
  for (var i = names.length - 1; i >= 0; i--) {
    let edificio = {
      direccion: direcciones[i].direccion, 
      tipo: tipo_oficio[Math.round(Math.random() * 3)],
      nivel_calidad: Math.round(Math.random() * 3),
      categoria: Math.round(Math.random() * 5)
    };

    edificiosPromises.push(knex('edificios').insert(edificio).returning('id'));
  }

  Promise.all(edificiosPromises)
    .then(data => {
      res.json(data);
    })
    .catch(err => {
      res.json(err);
    });
});

app.get('/asignaciones', (req, res) => {
  var asignacionesPromises = [];
  for (var i = 50; i >= 0; i--) {
    let asignacion = {
      trabajador_id: Math.round(Math.random() * 9) + 11, 
      edificio_id: Math.round(Math.random() * 9) + 1, 
      fecha_inicio: getRandomDate(),
      numero_dias: Math.round(Math.random() * 50) + 1
    };

    asignacionesPromises.push(knex('asignaciones').insert(asignacion));
  }

  Promise.all(asignacionesPromises)
    .then(data => {
      res.json(data);
    })
    .catch(err => {
      res.json(err);
    });
});

app.get('/supervisores', (req, res) => {

  var supervisoresPromises = [];
  for (var i = 3; i < 10; i++) {
    supervisoresPromises.push(
      knex('trabajadores')
      .where('id', '=', i + 11)
      .update({
        supervisor_id: Math.round(Math.random() * 2) + 11
      })
    );
  }

  Promise.all(supervisoresPromises)
    .then(data => {
      res.json(data);
    })
    .catch(err => {
      res.json(err);
    });
});

function getRandomDate() {
  return '2018-'+(Math.round(Math.random() * 11) + 1)+'-'+(Math.round(Math.random() * 20) + 1);
}
app.listen(__PORT, (req, res) => {
  console.log('APP running on PORT: ', __PORT);
});