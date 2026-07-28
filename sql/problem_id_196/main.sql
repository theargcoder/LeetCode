-- Write your PostgreSQL query statement below
DELETE FROM Person O_P
WHERE EXISTS (
        SELECT
            id
        FROM
            Person N_P
        WHERE
            O_P.email = N_P.email
            AND O_P.id > N_P.id)
