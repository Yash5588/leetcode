# Write your MySQL query statement below
SELECT activity_date AS day, 
COUNT(DISTINCT user_id)
AS active_users
FROM Activity
GROUP BY activity_date
HAVING DATEDIFF('2019-07-27', activity_date) 
BETWEEN 0 and 29;