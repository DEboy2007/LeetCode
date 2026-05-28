import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    # remove repeated salaries from dataframe, id doesn't matter so can js use sets
    salaries = employee["salary"].tolist()
    salaries.sort()
    unique_salaries = []
    nth_salary = None
    for i in salaries:
        if i not in unique_salaries:
            unique_salaries.append(i)
    unique_salaries = unique_salaries[::-1]

    if N <= len(unique_salaries) and N >= 1:
        nth_salary = unique_salaries[N - 1]

    return_df = pd.DataFrame(data={f"getNthHighestSalary({N})": [nth_salary]})
    return return_df
    