# Write your MySQL query statement below
select e1.name as name , e2.bonus as bonus from Employee e1 left join Bonus e2 on e1.empId = e2.empId where bonus is null or  bonus<1000