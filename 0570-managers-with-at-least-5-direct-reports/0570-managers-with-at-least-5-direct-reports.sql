select b.name from Employee b
join (select managerId from Employee group by managerID having count(*) >= 5) a 
on b.id=a.managerID