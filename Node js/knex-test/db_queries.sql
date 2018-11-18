CREATE TABLE users(id SERIAL PRIMARY KEY, name TEXT NOT NULL, email TEXT UNIQUE NOT NULL);
CREATE TABLE blogs(id SERIAL PRIMARY KEY, title TEXT NOT NULL, content TEXT NOT NULL);
CREATE TABLE blogs_user(user_id INT REFERENCES users(id), blog_id INT REFERENCES blogs(id), creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP);

-- SELECT
SELECT * FROM users;
SELECT * FROM blogs;
SELECT * FROM blogs_user;

-- SEEDS
INSERT INTO users(name, email) VALUES('Brandon Mosqueda', 'bmosqueda@ucol.mx');
INSERT INTO users(name, email) VALUES('Alejandro González', 'agonzalez@ucol.mx');

INSERT INTO blogs(title, content) VALUES('blog 1', 'Hola mundo 1');
INSERT INTO blogs(title, content) VALUES('blog 2', 'Hola mundo 2');
INSERT INTO blogs(title, content) VALUES('blog 3', 'Hola mundo 3');
INSERT INTO blogs(title, content) VALUES('blog 4', 'Hola mundo 4');

INSERT INTO blogs_user(user_id, blog_id) VALUES(1, 1);
INSERT INTO blogs_user(user_id, blog_id) VALUES(1, 2);
INSERT INTO blogs_user(user_id, blog_id) VALUES(2, 3);
INSERT INTO blogs_user(user_id, blog_id) VALUES(2, 4);