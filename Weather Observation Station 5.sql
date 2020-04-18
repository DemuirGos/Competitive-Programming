/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select CITY,length(CITY) from STATION order by length(CITY)asc, CITY  LIMIT 1;
select CITY,length(CITY) from STATION order by length(CITY)desc,CITY LIMIT 1;