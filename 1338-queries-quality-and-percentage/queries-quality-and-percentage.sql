# Write your MySQL query statement below
SELECT query_name, 
ROUND(SUM(rating / position) / COUNT(position), 2) AS quality,
ROUND((SUM(IF(rating < 3, 1, 0)) / COUNT(position)) * 100.00, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;