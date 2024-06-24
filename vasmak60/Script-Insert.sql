-- Домашнее задание №1. Работа с SQL. Создание БД

INSERT INTO Genre (name) VALUES
    ('Jazz'), ('Blues'), ('Rock'), ('Rock-n-Roll'), ('Disco'), ('Rap'), ('Heavy Metal');
    
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
    
  INSERT INTO AutorGenre (autor_id, genre_id) VALUES
     (1, 1), (2, 1), (2, 2), (3, 1), (3, 6), (4, 2), (5, 7), (6, 7),
     (6, 6), (7, 3), (7, 4), (8, 3), (9, 3), (10, 4), (11, 4), (11, 7),
     (12, 4), (13, 5), (13, 4), (14, 5), (15, 6), (15, 4), (16, 6), 
     (17, 6), (17, 7), (18, 6),(18, 7), (19, 7);
     
  INSERT INTO Album (name_album, autor, relise ) VALUES
     ('Deuces Wild', 'B.B. King', '1997-01-01'),
     ('The Blues Legend', 'B.B. King', '2024-01-01'),
     ('Blues in Orbit/Cosmic Scene', 'Duk Ellington', '2017-01-01'),
     ('Old Sock', 'Eric Clapton', '2013-01-01'),      
     ('Louis Wishes Yuo aCool Yule', 'Luis Armstrong', '2003-01-01'),      
     ('24 Chefs-d oevre', 'Luis Armstrong', '2022-01-01'),      
     ('The 50 Greatest Hits', 'Elvis Presley', '2000-01-01'),
     ('Dont Bother Me', 'Elvis Presley', '2009-01-01'),      
     ('The Beatles - With The Beatles(1963)', 'Beatles', '2022-01-01'),      
     ('Voyage', 'ABBA', '2021=01=01'),      
     ('Platinum Hits', 'Boney M.', '2013-01-01'),
     ('Boney M./Barbara Streisant', 'Boney M.', '2011-01-01'),
     ('Christmas Party', 'Boney M.', '1998-01-01'),      
     ('Satin... In Black & White', 'Baccara', '2008-01-01'),      
     ('The Best of Michael Jackson', 'Michael Jackson', '1995-01-01'),      
     ('The One', 'Elton John', '1992-01-01'),      
     ('Regimental Sgt. Zippo', 'Elton John', '2012-01-01'),      
     ('Heart and Soul', 'Modern Talking', '2010-01-01'),      
     ('Universe', 'Modern Talking', '2003-01-01'),      
     ('The Eminem Show', 'Eminem', '2002-01-01'),      
     ('4:44', 'Jay-Z', '2017-01-01'),      
     ('The Joshua Tre(Super Deluxe)', 'U2', '2017=01=01'),      
     ('Forever', 'Bon Jovi', '2024=01=01'),      
     ('Goats Head Soup (Remastered)', 'Rolling Stones', '2009-01-01'),
     ('Paranoid', 'Black Sabbath', '2014-01-01'),
     ('Death Magnetic', 'Metallica', '2008-01-01');      
      
   INSERT INTO AlbumAutor (album_id, autor_id) VALUES
    (1, 1), (1, 3), (2, 1), (3, 2), (4, 3), (5, 4), (6, 4), (7, 5),
    (8, 5), (9, 6), (10, 7), (11, 8), (12, 8), (13, 8), (14, 9),
    (15, 10), (16, 11), (17, 11), (18, 12), (19, 12), (20, 13),
    (21, 14), (22, 15), (23, 16), (24, 17), (25, 18), (26, 19);
     
   INSERT INTO Track (name_track, time_track, id_album) VALUES
    ('Rock Me Baby', 6.77, 1),
    ('When My Heart Beats', 7.40, 2),
    ('Caravan', 4.53, 3),
    ('I let a Song out My Heart', 3.05, 3),
    ('All of Me', 5.38, 4),
    ('Im Puttin All My Eggs in One Basket', 3.43, 5),
    ('Zat Yuo, Santa Clus??', 2.82, 6),
    ('Love Me Tender', 2.73, 7),
    ('Always On My Minol', 3.67, 8),
    ('Little Child', 1.75, 9),
    ('All My Loving', 2.10, 9),
    ('Mamma Mia', 3.53, 10),
    ('People Need Love', 2.77, 10),
    ('Gott a go Home', 2.53, 11),
    ('Heart of Gold', 4.10, 12),
    ('On Christmas Tree', 3.00, 13),
    ('Cara Mia', 3.00, 14),
    ('Sory, Im a Lady', 3.82, 14),
    ('State of Shock', 4.50, 15),
    ('Ben', 2.75, 15),
    ('Farewell My Summer Love', 4.40, 15),
    ('Runaway Train', 5.38, 16),
    ('Turn to Me', 3.32, 17),
    ('You re My Hert', 5.47, 18),
    ('Brother Louice', 3.67, 18),
    ('Mystery', 3.53, 19),
    ('White America', 5.45, 20),
    ('The Riss', 1.25, 20),
    ('Kill Jay-Z', 2.97, 21),
    ('Bam', 3.92, 21),
    ('Exit', 3.83, 22),
    ('Freedom for My People', 0.63, 22),
    ('Waves', 3.87, 23),
    ('My First Guitar', 4.92, 23),
    ('Angie', 4.32, 24),
    ('Connection', 3.50, 24),
    ('Iron Man', 5.54, 25),
    ('My Apocaypce', 5.03, 26),
    ('Dont Tread Me', 4.33, 26);
    
  INSERT INTO Collection (name_collection, relise ) VALUES
     ('Jazz & Blues The Best', '2010-01-01'),
     ('Discotheque 70', '2019-01-01'),
     ('Rock Legends', '2020-01-01'),
     ('Iron Century', '2024-01-01');
     
  INSERT INTO CollectionTrack (collection_id, track_id ) VALUES
     (1, 1), (1, 2), (1, 3), (1, 4), (1, 5),
     (2, 8), (2, 9), (2, 10), (2, 11), (2, 12), (2, 13),
     (3, 5), (3, 6), (3, 10), (3, 11), (3, 16), (3, 17),
     (4, 37), (4, 27), (4, 29), (4, 30), (4, 32), (4, 34), (4, 36), (4, 38);
   