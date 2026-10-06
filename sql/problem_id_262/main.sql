WITH counts AS (
    WITH ubanned AS (
        SELECT
            *
        FROM (
            SELECT
                *
            FROM (
                SELECT
                    *
                FROM (
                    SELECT
                        *
                    FROM
                        Trips
                    WHERE
                        request_at::date <= '2013-10-03'::date
                        AND request_at::date >= '2013-10-01'::date)
                    LEFT JOIN Users AS users ON users.users_id = client_id)
            WHERE
                EXISTS (
                    SELECT
                        *
                    FROM
                        Users
                    WHERE
                        driver_id = users_id
                        AND banned LIKE 'No')) AS merged
            WHERE
                merged.banned LIKE 'No'
                AND merged.request_at IS NOT NULL
)
            SELECT
                request_at,
                COUNT(status) AS requests_ct,
                COUNT(status) FILTER (WHERE status LIKE 'cancelled_by_driver'
                    OR status LIKE 'cancelled_by_client') AS cancelled_ct
            FROM
                ubanned
            GROUP BY
                ubanned.request_at
)
    SELECT
        request_at AS "Day",
        ROUND(cancelled_ct::numeric / NULLIF (requests_ct, 0), 2) AS "Cancellation Rate"
FROM
    counts;


/*
WITH counts AS (
 WITH ubanned AS (
 SELECT
 *
 FROM (
 SELECT
 *
 FROM (
 SELECT
 *
 FROM
 Trips
 WHERE
 request_at::date <= '2013-10-03'::date
 AND request_at::date >= '2013-10-01'::date)
 LEFT JOIN Users AS users ON users.users_id = client_id) AS merged
 WHERE
 merged.banned LIKE 'No'
 AND merged.request_at IS NOT NULL
)
 SELECT
 request_at,
 COUNT(status) AS requests_ct,
 COUNT(status) FILTER (WHERE status LIKE 'cancelled_by_driver'
 OR status LIKE 'cancelled_by_client') AS cancelled_ct
 FROM
 ubanned
 GROUP BY
 ubanned.request_at
)
SELECT
 request_at AS "Day",
 ROUND(cancelled_ct::numeric / NULLIF (requests_ct, 0), 2) AS "Cancellation Rate"
FROM
 counts;
 */
