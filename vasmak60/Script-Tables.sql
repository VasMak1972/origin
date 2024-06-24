--Домашнее задание №1. Работа с SQL. Создание БД

CREATE table IF NOT EXISTS   Genre (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS    Autor (
	id SERIAL PRIMARY KEY,
	nickname TEXT NOT NULL,
	jenre VARCHAR(50) NOT NULL
);


CREATE TABLE IF NOT EXISTS    AutorGenre (
	 autor_id INTEGER REFERENCES Autor(id),
	 genre_id INTEGER REFERENCES Genre(id),
	 CONSTRAINT pk PRIMARY KEY (autor_id, genre_id)
);   


CREATE TABLE  IF NOT EXISTS   Album (
	id SERIAL PRIMARY KEY,
	name_album TEXT NOT NULL,
	autor VARCHAR(50) NOT NULL,	
	relise DATE NOT NULL
);      
      

CREATE TABLE IF NOT EXISTS  AlbumAutor (
	album_id INTEGER REFERENCES Album(id),
	autor_id INTEGER REFERENCES Autor(id),
	CONSTRAINT pk1 PRIMARY KEY (album_id, autor_id)
);    
     
    
CREATE TABLE IF NOT EXISTS Track (
	id SERIAL PRIMARY KEY,
	name_track TEXT NOT NULL,
	time_track DECIMAL(3, 2) NOT NULL,
	id_album INTEGER NOT NULL REFERENCES Album(id)
);

  

 CREATE table IF NOT EXISTS Collection (
	id SERIAL PRIMARY KEY,
	name_collection TEXT NOT NULL,
	relise DATE NOT NULL
);

    

CREATE TABLE IF NOT EXISTS CollectionTrack (
	collection_id INTEGER REFERENCES Collection(id),
	track_id INTEGER REFERENCES Track(id),
	CONSTRAINT pk_2 PRIMARY KEY (collection_id, track_id)
);


