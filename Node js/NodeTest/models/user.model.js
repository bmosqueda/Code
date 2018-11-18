const General = require('./general.model.js');

/*  In database
  - id
  - name (75)
  - token (250)
*/

class User extends General {
  constructor() {
    super('users');
  }

  getByName(name) {
    let sql = `SELECT * FROM ${this.table} WHERE name LIKE :name`;

    return this.getBySql(sql, {name: `%${name}%`});
  };

  validateToCreate(user) {
    if(user) {  //Validate
      return true;
    }
    else
      return false;
  };

  create(user) {
    if(this.validateToCreate(user)) {
      let sql = `INSERT INTO ${this.table} (name, token) VALUES(:name, :token)`;

      let newUser = {
        name: user.name,
        token: user.token
      };
      
      return this.getBySql(sql, newUser);
    }
    else 
      throw ('Data error for create user');
  };

  exists(email) {
    let sql = `SELECT COUNT(*) FROM ${this.table} WHERE email = :email`;

    return this.getBySql(sql, {email: email});
  }

  getByEmail(email) {
    let sql = `SELECT * FROM ${this.table} WHERE email = :email`;

    return this.getBySql(sql, {email: email});
  }

  createGoogleUser(user) {
    console.log(user);
    if(user.token && user.name && user.urlImage && user.email) {
      let sql = `INSERT INTO ${this.table} (name, token, urlImage, email) VALUES(:name, :token, :urlImage, :email)`;

      return this.getBySql(sql, user);
    } 
    else
      throw ('Data error for create google user');
  }
}

module.exports = User;