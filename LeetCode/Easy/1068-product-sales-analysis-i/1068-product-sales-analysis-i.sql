SELECT prod.product_name, sales.year, sales.price
FROM Sales as sales INNER JOIN Product as prod ON sales.product_id = prod.product_id