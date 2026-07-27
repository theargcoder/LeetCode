-- Write your PostgreSQL query statement below
SELECT
    sub_query.score,
    sub_query.rank
FROM (
    SELECT
        score,
        row_number() OVER (ORDER BY score DESC) AS rank
    FROM
        scores
    GROUP BY
        score) AS sub_query
    LEFT JOIN scores AS main_query ON sub_query.score = main_query.score
ORDER BY
    score DESC;

