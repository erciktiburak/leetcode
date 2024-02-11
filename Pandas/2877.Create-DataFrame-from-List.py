import pandas as pd
from typing import List

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    # Create DataFrame with columns student_id and age
    df = pd.DataFrame(student_data, columns=['student_id', 'age'])
    return df

# Example usage:
student_data = [
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]

result_df = createDataframe(student_data)
print(result_df)

# case 1: [[1,15],[2,11],[3,11],[4,20]]