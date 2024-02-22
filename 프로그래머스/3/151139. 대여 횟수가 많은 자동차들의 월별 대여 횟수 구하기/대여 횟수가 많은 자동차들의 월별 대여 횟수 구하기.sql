-- 코드를 입력하세요
WITH B AS (
    SELECT CAR_ID, COUNT(HISTORY_ID) AS RECORD
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
        GROUP BY CAR_ID
        HAVING RECORD >= 5
)
SELECT MONTH(A.START_DATE) AS MONTH, A.CAR_ID, COUNT(A.HISTORY_ID) AS RECORDS
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY A, B
    WHERE A.CAR_ID = B.CAR_ID AND START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
    GROUP BY MONTH, CAR_ID
    HAVING RECORDS != 0
    ORDER BY MONTH, CAR_ID DESC