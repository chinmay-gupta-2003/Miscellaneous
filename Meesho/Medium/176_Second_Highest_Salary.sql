SELECT DISTINCT MAX(salary) as SecondHighestSalary FROM Employee 
WHERE salary < (SELECT DISTINCT MAX(salary) FROM Employee);