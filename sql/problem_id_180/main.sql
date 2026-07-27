-- Write your PostgreSQL query statement below
SELECT DISTINCT
    num AS ConsecutiveNums
FROM
    Logs U
WHERE
    EXISTS (
        SELECT
            num,
            id
        FROM
            Logs N
        WHERE
            n.num = u.num
            AND n.id = U.id - 1)
    AND EXISTS (
        SELECT
            num,
            id
        FROM
            Logs N
        WHERE
            n.num = u.num
            AND n.id = U.id - 2)
