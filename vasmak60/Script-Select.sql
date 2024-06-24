SELECT name_track, time_track  FROM track
WHERE time_track = (SELECT MAX(time_track) FROM track);

SELECT name_track, time_track  FROM track
WHERE time_track >= 3.50;

SELECT name_collection, relise FROM collection 
WHERE relise >= '2018-01-01' AND relise <= '2020-01-01';

SELECT nickname  FROM autor
WHERE nickname NOT LIKE '% %';

SELECT name_track  FROM track
WHERE name_track LIKE '%My%';
