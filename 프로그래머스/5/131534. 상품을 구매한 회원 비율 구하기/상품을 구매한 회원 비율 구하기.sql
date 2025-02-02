# SELECT count(user_id) FROM USER_INFO WHERE year(joined)=2021

# SELECT year(sales_date) as YEAR, month(sales_date) as MONTH, count(distinct sale.USER_ID)as PURCHASED_USERS, sale.USER_ID
# FROM USER_INFO as info LEFT JOIN ONLINE_SALE as sale ON info.USER_ID = sale.USER_ID
# WHERE year(info.joined)=2021
# GROUP BY 1, 2


SELECT year(sales_date) as YEAR, month(sales_date) as MONTH, count(distinct user_id) as PURCHASED_USERS, round(count(distinct user_id) / (SELECT count(user_id) FROM USER_INFO WHERE year(joined)=2021), 1) as PUCHASED_RATIO
FROM ONLINE_SALE
WHERE user_id in (  SELECT user_id
                    FROM USER_INFO
                    WHERE year(joined)=2021 )
GROUP BY 1, 2
ORDER BY 1, 2