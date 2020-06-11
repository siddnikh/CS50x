SELECT movies.title FROM ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE ratings.movie_id IN(
    SELECT movie_id FROM stars WHERE person_id IN(
        SELECT id FROM people WHERE name = "Chadwick Boseman"
    )
) ORDER BY ratings.rating DESC LIMIT 5;
