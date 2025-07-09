from datetime import datetime
from dateutil.relativedelta import relativedelta

def solution(today, terms, privacies):
    d = {x[0]: x[2:] for x in terms}
    final_date = [
        datetime.strptime(x[:-2], "%Y.%m.%d")
        + relativedelta(months=int(d[x[-1]])) for x in privacies
    ]
    today = datetime.strptime(today, "%Y.%m.%d")
    answer = [(i + 1) for i, day in enumerate(final_date) if (day <= today)]
    return answer