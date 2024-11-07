# Write your MySQL query statement below
select E1.name from Employee E1 join (
    select managerId, count(*) from Employee group by managerId having count(*) >= 5
) E2 where E1.id = E2.managerId