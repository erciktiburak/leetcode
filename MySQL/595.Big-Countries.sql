-- To select a country with an area of at least three million square kilometers or a lifespan of at least twenty-five million according to the specified divisions for large regions to be available

SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;

/* 
| name        | continent | area    | population | gdp          |
| ----------- | --------- | ------- | ---------- | ------------ |
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
*/