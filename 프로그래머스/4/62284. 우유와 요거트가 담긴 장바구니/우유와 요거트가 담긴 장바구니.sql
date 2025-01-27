SELECT CART_ID
FROM
    (SELECT CART_ID, GROUP_CONCAT(distinct name order by name separator ' ')as NAME
    FROM CART_PRODUCTS
    WHERE NAME="Milk" OR NAME="Yogurt"
    GROUP BY 1
    HAVING NAME="Milk Yogurt"
    ORDER BY 1) as A