-- Write your PostgreSQL query statement below
SELECT
    id
FROM (
    SELECT
        id AS id,
        temperature AS now_temp,
        recordDate AS now_date,
        LAG(temperature, 1, NULL) OVER (ORDER BY recordDate ASC) AS prev_temp,
        LAG(recordDate, 1, NULL) OVER (ORDER BY recordDate ASC) AS prev_date
    FROM
        Weather)
WHERE
    now_temp > prev_temp
    AND now_date - prev_date = 1
