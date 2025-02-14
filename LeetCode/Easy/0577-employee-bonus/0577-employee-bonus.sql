SELECT emp.name, bns.bonus
FROM Employee as emp LEFT JOIN Bonus as bns ON emp.empId = bns.empId
WHERE bns.bonus < 1000 OR bns.bonus IS NULL