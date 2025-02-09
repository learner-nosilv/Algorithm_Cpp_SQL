SELECT uni.unique_id, emp.name
FROM Employees as emp left join EmployeeUNI as uni ON emp.id = uni.id