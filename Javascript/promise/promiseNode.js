//Promises, para evitar el callback hell
//Se usan para que funciones asincrónicas se ejecuten de manera secuencial
//Control para lo errores
var fs = require('fs')

//Leemos un archivo en el directorio actual y escribimos otro aquí mismo con la cantidad de caracteres del primero
// fs.readFile('./pruebas.html', function(err, content){
	// fs.writeFile('./cantidad.txt', content.length, function(err) {
		// console.log(content.length);
	// })
// })


//Lo mismo de arriba pero con promesas, se gana modularidad en lugar de tener callbacks anidados
function readFile(name) {
	console.log('Leyendo ' + name)
	//Las promesas reciben como parámetro una función
	//El resolve es lo que espera la siguiente función
	return new Promise(function(resolve, reject) {
		fs.readFile(name, function(err, content) {
			//Si hay un error se devulve reject
			if(err) {
				reject(err)
			}
			resolve(content)
			// reject("Falló la lectura")
			console.log('Leído ' + name)	
		})
	})
}

function writeFile(name, content) {
	return new Promise(function(resolve, reject) {
		//Funciona si llamamos esta función sin un callback pero esta práctica ha sido deprecada para funciones asincrónicas
		fs.writeFile(name, content, function(err) {
			//No devulve nada porque no hay otra función que espere después de esta en el presente contexto
			if(err) {
				reject(err)
			}
			console.log("Dentro: " + content)
			resolve(content)
			// reject("Falló la escritura")
		})
	})
}

//La función .then() de las promesas, también devulve una promesa
//catch() se manda llamar si alguna de las dos funciones llamadas falla (que devuelva el reject)
// readFile('./modals.html')
// .then(content => writeFile('cantidad.txt', content.length))
// .then(content => console.log("Fuera: " + content))
// .catch(err => console.log("Hubo un error: " + err.message))

//Recibe un array de promesas y las ejecuta en paralelo, then se ejecuta cuando termina el último
//then() recibe un array de respuestas
Promise.all([
	readFile('./cantidad.txt'),
	readFile('./modals.html'),
	readFile('./pruebas.html')
]).then(responses => responses.forEach(response => console.log(response.toString()))) 

//Promise.race() lo mismo que .all pero aquí se ejecuta cuando la primera promesa termina, por lo tanto sólo recibe una respuesta, no un array