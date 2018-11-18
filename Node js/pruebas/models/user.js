var mongoose = require('mongoose')
var Schema = mongoose.Schema;
var md5 = require('md5');

mongoose.connect("mongodb://localhost/pruebas");

var passwordValidation = {
	validator: function(pass) {
		//Se encripta la contraseña
		this.password = md5(pass);
		return this.passwordConfirmation == this.password;	//Todos los validadores deben de regresar un booleano
	},
	message: "Las contraseñas no son iguales"
}

var userSchema = new Schema({
	name: String,
	password: {
		type: String, 
		required: true, 
		minlength: [3, "El password es muy corto"],
		validate: passwordValidation
	}
})

///IMPORTANTE
/*Lo de las validaciones del password confirmation sirven para recibir los dos campos que se piden al registrar un usuario, la contraseña y la confirmacion, 
pero la confirmación no se guarda, sólo se usa para corroborar que las contraseñas ingresadas coinciden */
userSchema.virtual("passwordConfirmation").get(function() {
	return this.passConfirm;
}).set(function(password) {
	this.passConfirm = md5(password);
});


var User = mongoose.model("User", userSchema);
module.exports.User = User;
