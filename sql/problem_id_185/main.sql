-- Write your PostgreSQL query statement below
SELECT
    O_Dep.name AS Department,
    O_Emp.name AS Employee,
    O_Emp.salary AS Salary
FROM
    Employee O_Emp
    LEFT JOIN Department O_Dep ON O_Emp.departmentId = O_Dep.id
WHERE
    O_Emp.id = ANY (
        SELECT
            id
        FROM (
            SELECT
                id,
                DENSE_RANK() OVER (ORDER BY salary DESC) AS rank
            FROM (
                SELECT
                    *
                FROM
                    Employee N_Emp
                WHERE
                    N_Emp.departmentId = O_Emp.departmentId))
        WHERE
            rank <= 3)
