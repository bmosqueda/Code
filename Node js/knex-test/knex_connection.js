var config = require('./knexfile.js');  
var env = 'development';  
var knex = require('knex')(config[env]);

module.exports = knex;

//it will be used to ensure that the schema of our database is always current.
knex.migrate.latest([config]); 