# Write your MySQL query statement below
SELECT p.product_id AS product_id,
s.year AS first_year,
s.quantity as quantity,
s.price AS price
FROM Product p
LEFT JOIN
Sales s
ON p.product_id = s.product_id
WHERE (p.product_id, s.year) IN (
    SELECT product_id, MIN(year)
    FROM Sales
    GROUP BY product_id
);

