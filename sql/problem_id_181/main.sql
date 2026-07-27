-- Write your PostgreSQL query statement below
SELECT
    name AS Employee
FROM
    Employee E_O
WHERE
    EXISTS (
        SELECT
            id,
            managerId,
            salary
        FROM
            Employee E_P
        WHERE
            E_O.managerId = E_P.id
            AND E_O.salary > E_P.salary)
