SELECT name, COUNT(autor_id) FROM autorgenre a
JOIN genre g  ON a.autor_id = g.id 
GROUP by g.id
ORDER by g.id;

SELECT name_album, COUNT(*) FROM track t
JOIN album a ON a.id = t.id_album
WHERE a.relise BETWEEN '2017-01-01' and '2022-01-01'  
GROUP by a.name_album
ORDER by COUNT(*);


SELECT name_album, AVG(time_track) FROM track t
JOIN album a ON a.id = t.id_album 
GROUP by a.name_album
ORDER by AVG(time_track);


SELECT autor, relise FROM album
WHERE NOT relise = '2022-01-01';

SELECT name_album, autor FROM album
WHERE autor like 'Boney_M_';