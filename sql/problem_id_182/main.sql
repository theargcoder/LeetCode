-- Write your PostgreSQL query statement below
-- FIST SUBMISSION (Beats 91.18% in time and 100% in memory)
SELECT DISTINCT
    email
FROM
    Person Q_O
WHERE
    EXISTS (
        SELECT
            email
        FROM
            Person Q_P
        WHERE
            Q_O.id != Q_P.id
            AND Q_O.email = Q_P.email);

