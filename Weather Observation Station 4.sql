/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select count(CITY)-count(distinct(CITY)) from STATION;