-- 코드를 입력하세요
SELECT A.ANIMAL_ID, A.NAME
    FROM ANIMAL_OUTS A
    LEFT JOIN ANIMAL_INS B ON A.ANIMAL_ID = B.ANIMAL_ID
    WHERE B.INTAKE_CONDITION IS NULL