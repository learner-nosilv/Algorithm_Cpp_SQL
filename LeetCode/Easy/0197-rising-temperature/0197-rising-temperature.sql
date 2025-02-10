SELECT today.id
FROM (SELECT * FROM weather)as today
    LEFT JOIN ( SELECT DATE_ADD(recordDate, INTERVAL 1 DAY) as tomorrowDate, temperature FROM Weather ) as yesterday
    ON today.recordDate = yesterday.tomorrowDate
WHERE today.temperature > yesterday.temperature