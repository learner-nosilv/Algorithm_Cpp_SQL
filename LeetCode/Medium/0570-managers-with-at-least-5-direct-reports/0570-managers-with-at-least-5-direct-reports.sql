SELECT name
FROM Employee
WHERE id in ( SELECT managerId
              FROM ( SELECT managerId, count(*) as cnt
                     FROM Employee
                     GROUP BY 1
                     HAVING managerID is not null AND cnt >= 5 ) as manager ) 