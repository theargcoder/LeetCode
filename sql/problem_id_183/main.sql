-- Write your PostgreSQL query statement below
SELECT
    name AS Customers
FROM
    Customers C_O
WHERE
    id != ALL (
        SELECT
            customerId
        FROM
            Orders O_O
        WHERE
            C_O.id = O_O.customerId);

