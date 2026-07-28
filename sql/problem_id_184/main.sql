-- Write your PostgreSQL query statement below
SELECT
    O_Emp.name AS Employee,
    O_Emp.salary AS Salary,
    O_Dep.name AS Department
FROM
    Employee O_Emp
    LEFT JOIN Department O_Dep ON O_Emp.departmentId = O_Dep.id
WHERE
    salary >= ALL (
        SELECT
            salary
        FROM
            Employee N_Emp
        WHERE
            O_Emp.id != N_Emp.id
            AND O_Emp.departmentId = N_Emp.departmentId)
