import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df = world.loc[(world["area"] >= 3000000) | (world["population"] >= 25000000)]
    df.drop(columns=["continent", "gdp"], inplace=True)
    return df
    