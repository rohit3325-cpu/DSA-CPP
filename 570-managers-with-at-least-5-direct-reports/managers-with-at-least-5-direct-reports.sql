# Write your MySQL query statement below
select name from Employee e
join (
    select managerId
    from Employee group by managerId having Count(*)>=5
)temp
ON e.id=temp.managerId;