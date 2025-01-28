SELECT total.author_id, author.author_name, total.category, total.TOTAL_SALES
FROM (  SELECT book.author_id, book.category, SUM(book.price * sales.sales) as TOTAL_SALES
        FROM (  SELECT book_id, sales
                FROM BOOK_SALES
                WHERE sales_date>='2022-01-01' and sales_date <"2022-02-01" ) as sales
            INNER JOIN BOOK as book
                ON sales.BOOK_ID = book.BOOK_ID
        GROUP BY 1, 2 ) as total
    INNER JOIN AUTHOR as author
        ON total.author_id=author.author_id
ORDER BY 1, 3 desc