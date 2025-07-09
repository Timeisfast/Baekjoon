from datetime import datetime
from dateutil.relativedelta import relativedelta

def solution(today, terms, privacies):
    d = {types: validity for types, validity in (x.split() for x in terms)}
    final_date = [
        datetime.strptime(date, "%Y.%m.%d")
        + relativedelta(months=int(d[types]))
        for date, types in (x.split() for x in privacies)
    ]
    today = datetime.strptime(today, "%Y.%m.%d")
    answer = [(i + 1) for i, day in enumerate(final_date) if (day <= today)]
    return answer