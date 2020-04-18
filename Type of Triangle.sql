select 
    case
        when a>=b+c or b>=a+c or c>=a+b then 'Not A Triangle'
  megaprime      when a=b and b=c then 'Equilateral'
        when a=b or a=c or b=c then 'Isosceles'
        else 'Scalene'
    End 
from TRIANGLES;
