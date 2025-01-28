SELECT half.FLAVOR
FROM FIRST_HALF as half LEFT JOIN ( SELECT FLAVOR, SUM(TOTAL_ORDER) as sum
                                    FROM JULY
                                    GROUP BY FLAVOR ) as july
                        ON half.FLAVOR = july.FLAVOR
ORDER BY (half.TOTAL_ORDER+july.sum) desc
LIMIT 3