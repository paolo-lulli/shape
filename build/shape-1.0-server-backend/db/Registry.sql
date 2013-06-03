.headers on
.mode line
select  u.ID as USER,
	g.ID as USERGROUP,
	r.ID as ROLE,
	p.ID_Resource as RESOURCE
 from   Account a
join User u on u.ID = a.ID_User
join Usergroup g on g.ID = a.ID_Usergroup
join Role r on  r.ID = a.ID_Role
join Policy p on p.ID_Role = r.ID
;
--where u.ID = '87249A0D-8555-4941-8C1C-74FAEABD734B';

