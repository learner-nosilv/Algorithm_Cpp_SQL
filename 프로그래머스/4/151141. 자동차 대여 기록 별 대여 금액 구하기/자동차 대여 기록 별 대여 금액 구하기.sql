SELECT id_fee_dur.history_id, round(id_fee_dur.full_fee * if(DISCOUNT_RATE is NULL, 1, dis.DISCOUNT_RATE),0) as FEE
FROM
    ( SELECT day_fee.history_id, day_fee.day * day_fee.daily_fee as full_fee, if(day_fee.day < 7, 0, if(day_fee.day<30, 7, if(day_fee.day<90, 30, 90))) as dur
    FROM    (
        SELECT his.history_id, timestampdiff(day, his.start_date, his.end_date)+1 as day, car.DAILY_FEE
             FROM   CAR_RENTAL_COMPANY_RENTAL_HISTORY as his
                    INNER JOIN
                        ( SELECT *
                          FROM CAR_RENTAL_COMPANY_CAR
                          WHERE CAR_TYPE = "트럭" ) as car
                    ON his.CAR_ID = car.CAR_ID ) as day_fee ) as id_fee_dur
     LEFT JOIN          
                ( SELECT if(DURATION_TYPE like "7일%", 7, if(DURATION_TYPE like "30일%", 30, 90))as DURATION, (1-DISCOUNT_RATE/100) as DISCOUNT_RATE
                  FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                  WHERE CAR_TYPE = "트럭"
                ) as dis
     ON id_fee_dur.dur = dis.DURATION
ORDER BY 2 desc , 1 desc