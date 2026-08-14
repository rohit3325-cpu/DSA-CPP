# Write your MySQL query statement below
select 
     em.unique_id as unique_id,
      e.name as name 
      from Employees e
       left join EmployeeUNI em
       ON e.id = em.id;