-- Write your PostgreSQL query statement below
SELECT
    (
        SELECT
            salary
        FROM
            Employee
        GROUP BY
            salary
        HAVING
            COUNT(DISTINCT salary) = 1
        ORDER BY
            salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary;

