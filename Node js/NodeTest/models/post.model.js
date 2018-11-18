const General = require('./general.model.js');

class Post extends General {
  constructor() {
    super('posts');
  }

  getAllByUser(idUser) {
    let sql = 
     `SELECT users.name, posts.content FROM postsUser 
      INNER JOIN users ON postsUser.idUser = users.id
      INNER JOIN posts ON postsUser.idPost = posts.id
      WHERE idUser = :id`;
    return this.getBySql(sql, {id: idUser});
  };
}

/*function Post() {
  General.call(this, 'posts');
}

Post.prototype = Object.create(General.prototype);

Post.prototype.getAllByUser = function(idUser) {
  let sql = 
   `SELECT users.name, posts.content FROM postsUser 
    INNER JOIN users ON postsUser.idUser = users.id
    INNER JOIN posts ON postsUser.idPost = posts.id
    WHERE idUser = :id`;
  return this.getBySql(sql, {id: idUser});
};*/

module.exports = Post;