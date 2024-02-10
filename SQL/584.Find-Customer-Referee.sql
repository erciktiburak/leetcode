--- From the customer table, to find the names of customers not referred by the customer with id 2;

SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL;

/* 
| id | name | referee_id |
| -- | ---- | ---------- |
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          | 
*/