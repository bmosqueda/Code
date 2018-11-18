const mariasql = require('mariasql-promise');
const db = new mariasql();

db.connect({
  host: '127.0.0.1',
  user: 'brandon',
  password: 'ninguna123',
  db: 'mariaDBtest'
}).then(() => {console.log("Conectado")})
  .catch((err) => {console.error("Error: ", err)})

class General {
  constructor(table) {
    this.table = table;
  }

  getBySql(sqlStmt, params = {}) {
    console.log('sql: ', sqlStmt);
    console.log('params: ', params);
    return new Promise((resolve, reject) => {
      let sql 8= db.prepare(sqlStmt);
      db.query(sql(params))
        .then(rows => {
          resolve(rows);
        })
        .catch(err => {
          reject(err);
        });
    });
  };

  getById(id) {
      let sql = `SELECT * FROM ${this.table} WHERE id = :id`;
      
      return this.getBySql(sql, {id: id});
  };

  getAll() {
    let sql = `SELECT * FROM ${this.table}`;

    return this.getBySql(sql);
  };

  deleteById(id) {
    let sql = `DELETE FROM ${this.table} WHERE id = :id`;

    return this.getBySql(sql, {id: id});
  };
}


/*function General(table) {
  this.table = table;
}

General.prototype.getById = function(id) {
    let sql = `SELECT * FROM ${this.table} WHERE id = :id`;
    
    return this.getBySql(sql, {id: id});
};

General.prototype.getAll = function() {
  let sql = `SELECT * FROM ${this.table}`;

  return this.getBySql(sql);
};

General.prototype.deleteById = function(id) {
  let sql = `DELETE FROM ${this.table} WHERE id = :id`;

  return this.getBySql(sql, {id: id});
};

General.prototype.getBySql = function(sqlStmt, params = {}) {
  console.log('sql: ', sqlStmt);
  console.log('params: ', params);
  return new Promise((resolve, reject) => {
    let sql = db.prepare(sqlStmt);
    db.query(sql(params))
      .then(rows => {
        resolve(rows);
      })
      .catch(err => {
        console.log(err);
        reject(err);
      });
  });
};
*/
module.exports = General;