# SELECT distinct history.car_id, car_list.car_type, car_list.FEE
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY as history
#     INNER JOIN
#        ( SELECT car.car_id, car.car_type, round(car.daily_fee*30*(100-dis.discount_rate)*0.01, 0) as FEE
#         FROM
#             ( SELECT car_id,car_type,daily_fee
#             FROM CAR_RENTAL_COMPANY_CAR
#             WHERE CAR_TYPE in ("세단", "SUV") ) as car
#             INNER JOIN
#             ( SELECT car_type, discount_rate FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN WHERE duration_type="30일 이상") as dis
#             ON car.car_type = dis.car_type
#         HAVING FEE >= 500000 and FEE < 2000000 ) as car_list
#     ON history.CAR_ID = car_list.CAR_ID
# WHERE (history.start_date <"2022-11-01" and history.end_date <"2022-11-01")
#     OR (history.start_date >"2022-11-30" and history.end_date >"2022-11-30")
# ORDER BY car_list.FEE desc, car_list.car_type, car_list.car_id desc



SELECT car.car_id, car.car_type, round(car.monthly_fee*dis.discount_rate, 0) as FEE
FROM
    ( SELECT car_id, car_type, daily_fee*30 as monthly_fee
    FROM CAR_RENTAL_COMPANY_CAR
    WHERE car_type in ("세단", "SUV")) as car
    INNER JOIN
    ( SELECT car_type, (100-discount_rate)/100 as discount_rate 
     FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
     WHERE duration_type="30일 이상") as dis
    ON car.car_type = dis.car_type
WHERE car.car_id NOT IN (   SELECT car_id
                            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                            WHERE (start_date>="2022-11-01" and start_date <="2022-11-30")
                                OR (end_date>="2022-11-01" and start_date <="2022-11-30"))
HAVING FEE >= 500000 and FEE < 2000000
ORDER BY 3 desc, 2, 1 desc