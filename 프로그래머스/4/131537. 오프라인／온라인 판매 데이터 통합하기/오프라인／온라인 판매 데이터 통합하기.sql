SELECT DATE_FORMAT(sales_date, "%Y-%m-%d") as SALES_DATE, product_id, user_id, sales_amount
FROM ONLINE_SALE
WHERE sales_date >= "2022-03-01" and sales_date < "2022-04-01"
UNION ALL
SELECT DATE_FORMAT(sales_date, "%Y-%m-%d") as SALES_DATE, product_id, NULL as user_id, sales_amount
FROM OFFLINE_SALE
WHERE sales_date >= "2022-03-01" and sales_date < "2022-04-01"
ORDER BY SALES_DATE, product_id, user_id