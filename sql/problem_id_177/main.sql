CREATE OR REPLACE FUNCTION nthhighestsalary (n int)
    RETURNS TABLE (
        salary int
    )
    AS $$
BEGIN
    IF n <= 0 THEN
        RETURN;
    END IF;
    RETURN QUERY
    SELECT
        e.salary
    FROM
        employee AS e
    GROUP BY
        e.salary
    HAVING
        COUNT(DISTINCT e.salary) = 1
ORDER BY
    e.salary DESC
LIMIT 1 OFFSET n - 1;
END;
$$
LANGUAGE plpgsql;

