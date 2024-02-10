-- To find the IDs of both low-fat (low_fats='Y') and recyclable (recyclable='Y') products from the table;

SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';

/* 
| product_id | low_fats | recyclable |
| ---------- | -------- | ---------- |
| 0          | Y        | N          |
| 1          | Y        | Y          |
| 2          | N        | Y          |
| 3          | Y        | Y          |
| 4          | N        | N          |
 */