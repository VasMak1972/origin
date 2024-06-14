-- Домашнее задание №1. Работа с SQL. Создание БД

CREATE table IF NOT EXISTS   Genre (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

INSERT INTO Genre (name) VALUES

    ('Jazz'), ('Blues'), ('Rock'), ('Rock-n-Roll'), ('Disco'), ('Rap'), ('Heavy Metal');


CREATE TABLE IF NOT EXISTS  Autor (
	id SERIAL PRIMARY KEY,
	nickname TEXT NOT NULL,
	jenre VARCHAR(50) NOT NULL
);

INSERT INTO Autor (nickname, jenre) VALUES    
    ('BB King', 'Blues'), 
    ('Duk Ellington', 'Blues'),
    ('Eric Clapton', 'Blues'),    
    ('Lui Armstrong', 'Jazz'),
    ('Elvis Presley', 'Rock-n-Roll'),
    ('Beatles', 'Rock-n-Roll'),
    ('ABBA', 'Disco'),
    ('Boney M', 'Disco'),
    ('Baccara', 'Disco'),
    ('Michael Jackson', 'Pop'),
    ('Elton John', 'Pop'),
    ('Modern Talking', 'Pop'),
    ('Eminem', 'Rap'),
    ('Jay-Z', 'Rap'),
    ('U2', 'Rock'),    
    ('Bon Jovi', 'Rock'),
    ('Rolling Stones', 'Rock'),
    ('Black Sabbath', 'Heavy Metal'),
    ('Metallica', 'Heavy Metal');    

CREATE TABLE IF NOT EXISTS  AutorGenre (
	autor_id INTEGER REFERENCES Autor(id),
	genre_id INTEGER REFERENCES Genre(id),
	CONSTRAINT pk PRIMARY KEY (autor_id, genre_id)
);

INSERT INTO AutorGenre (autor_id, genre_id) VALUES
     (1, 1), (2, 1), (2, 2), (3, 1), (3, 6), (4, 2), (5, 7), (6, 7),
     (6, 6), (7, 3), (7, 4), (8, 3), (9, 3), (10, 4), (11, 4), (11, 7),
     (12, 4), (13, 5), (13, 4), (14, 5), (15, 6), (15, 4), (16, 6), 
     (17, 6), (17, 7), (18, 6),(18, 8), (19, 8);


CREATE TABLE IF NOT EXISTS  Album (
	id SERIAL PRIMARY KEY,
	relise DATE NOT NULL,
	autor VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS  AlbumAutor (
	album_id INTEGER REFERENCES Album(id),
	autor_id INTEGER REFERENCES Autor(id),
	CONSTRAINT pk_1 PRIMARY KEY (album_id, autor_id)
);

CREATE table IF NOT EXISTS  Track (
	id SERIAL PRIMARY KEY,
	name_album TEXT NOT NULL,
	time INTEGER NOT NULL,
	id_album INTEGER NOT NULL REFERENCES Album(id)
);

CREATE table IF NOT EXISTS  Collection (
	id SERIAL PRIMARY KEY,
	name_collection TEXT NOT NULL,
	relise DATE NOT NULL
);

CREATE table IF NOT EXISTS   CollectionTrack (
	collection_id INTEGER REFERENCES Collection(id),
	track_id INTEGER REFERENCES Track(id),
	CONSTRAINT pk_2 PRIMARY KEY (collection_id, track_id)
);
