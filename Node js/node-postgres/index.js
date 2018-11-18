const express = require('express');
const app = express();
const { Pool, Client } = require('pg');

const client = new Client({
  user: 'postgres',
  host: 'localhost',
  database: 'constructora',
  password: '',
  port: 5432
});

client.connect(function(error) {
  if(error)
    console.error(error);
  console.log('Conectado a PostgreSQL');
});


class User {
  constructor(param) {
    this.table = 'trabajadores';
    if(!isNaN(param))
    {
      /*
        No podemos usarlo por como en el cenedic porque los métodos son asíncronos y los constructores
        no pueden ser asíncronos, las propiedades se las asigna después de llamarse
      */
      this.getById(param, (error, data) => {
        this.nombre = data.rows[0].nombre;
        console.log(this);
      });
    }
    else
      console.log("no es un número");

    console.log(this);
  }

  getAllUsers(callback) {
    client.query(`SELECT * FROM ${this.table}`, callback);
  }

  getById(id, callback) {
    client.query(`SELECT * FROM ${this.table} WHERE trabajador_id = ${id}`, callback);
  }
}

app.get('/', function(req, res) {
  let newUser = {
    trabajador_id: 200
    nombre: 'Hola mundo',
    tarifa_hora: 65.65,
    tipo_oficio: 'Electricista',
    supervisor_id: 1311
  };

  await client.query('INSERT INTO trabajadores(trabajador_id, nombre, tarifa_hora, tipo_oficio, supervisor_id) VALUES($1)', [newUser])

  const { rows } = await client.query('SELECT * FROM users')

  res.json(rows);
});

app.listen(3000, function() {
  console.log('App running on port 3000');
});