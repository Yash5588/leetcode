# Write your MySQL query statement below
select p.email from Person p group by p.email having count(p.id) > 1