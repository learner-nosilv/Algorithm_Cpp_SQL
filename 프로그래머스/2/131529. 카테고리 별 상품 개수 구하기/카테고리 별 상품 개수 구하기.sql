SELECT left(PRODUCT_CODE,2) as 'CATEGORY', count(product_id) as 'PRODUCTS'
from PRODUCT
group by 1