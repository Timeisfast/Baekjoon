-- 코드를 입력하세요
WITH AB AS (
SELECT
    CAR_ID, CAR_TYPE, DAILY_FEE
FROM
    CAR_RENTAL_COMPANY_CAR
WHERE
    CAR_ID NOT IN (
        SELECT DISTINCT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE BETWEEN '2022-11-01' AND '2022-11-30'
            OR END_DATE BETWEEN '2022-11-01' AND '2022-11-30'
            OR START_DATE < '2022-11-01' AND END_DATE > '2022-11-30')
    AND CAR_TYPE IN ('세단', 'SUV')
)

SELECT
    AB.CAR_ID, AB.CAR_TYPE, FLOOR(AB.DAILY_FEE * (1 - C.DISCOUNT_RATE / 100) * 30) AS FEE
FROM
    AB
JOIN
    (SELECT * FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
     WHERE DURATION_TYPE = '30일 이상') AS C
     ON AB.CAR_TYPE = C.CAR_TYPE
WHERE
    FLOOR(AB.DAILY_FEE * (1 - C.DISCOUNT_RATE / 100) * 30) BETWEEN 500000 AND 1999999
ORDER BY
    FEE DESC, CAR_TYPE, CAR_ID DESC