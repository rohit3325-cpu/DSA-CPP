# Write your MySQL query statement below
Select c.customer_id,COUNT(c.customer_id) as "count_no_trans"
from Visits c
left join transactions t
on c.visit_id=t.visit_id
where transaction_id is Null 
group by customer_id ;