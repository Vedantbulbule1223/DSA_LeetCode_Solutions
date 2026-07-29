# Write your MySQL query statement below
-- select max(salary) as SecondHighestSalary 
-- from Employee where salary < (select max(salary) From employee);

-- Select salary aS SecondHighestSalary  From (
--     select salary , Dense_Rank() over (order by salary Desc) as rnk
--     from employee
-- ) ranked
-- where rnk = 2;

SELECT (
    SELECT DISTINCT salary 
    FROM Employee 
    ORDER BY salary DESC 
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;

