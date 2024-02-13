""" Write a solution to list the names of animals that weigh strictly more than 100 kilograms.
Return the animals sorted by weight in descending order. """

import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    heavy_animals = animals[animals['weight'] > 100]
    sorted_heavy_animals = heavy_animals.sort_values(by='weight', ascending=False)
    return sorted_heavy_animals[['name']]  # Ensure that the result is a DataFrame, not a Series


""" 
Example 1:

Input: 
DataFrame animals:
+----------+---------+-----+--------+
| name     | species | age | weight |
+----------+---------+-----+--------+
| Tatiana  | Snake   | 98  | 464    |
| Khaled   | Giraffe | 50  | 41     |
| Alex     | Leopard | 6   | 328    |
| Jonathan | Monkey  | 45  | 463    |
| Stefan   | Bear    | 100 | 50     |
| Tommy    | Panda   | 26  | 349    |
+----------+---------+-----+--------+
Output: 
+----------+
| name     |
+----------+
| Tatiana  |
| Jonathan |
| Tommy    |
| Alex     |
+----------+
Explanation: 
All animals weighing more than 100 should be included in the results table.
Tatiana's weight is 464, Jonathan's weight is 463, Tommy's weight is 349, and Alex's weight is 328.
The results should be sorted in descending order of weight.
 """
