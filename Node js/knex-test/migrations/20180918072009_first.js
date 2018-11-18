exports.up = function(knex, Promise) {
  return Promise.all([
    knex.schema.createTable('migration', function(table) {
        table.increments('id').primary()
    })]);  
};

exports.down = function(knex, Promise) {
  return Promise.all([
    knex.schema.dropTable('migration')
  ]);    
};
