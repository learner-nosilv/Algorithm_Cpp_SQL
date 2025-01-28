SET @hour = -1;
SELECT  @hour := @hour + 1 as HOUR,
        ( SELECT COUNT(*)
          FROM ANIMAL_OUTS
          WHERE hour(DATETIME)=@hour
        ) as COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23