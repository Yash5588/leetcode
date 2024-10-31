# Write your MySQL query statement below
# Write your MySQL query statement below
select t1.name 
from SalesPerson t1
where t1.sales_id not in (
    select t3.sales_id 
    from Company t2 join Orders t3
    on t2.com_id = t3.com_id and t2.name = "RED"
)