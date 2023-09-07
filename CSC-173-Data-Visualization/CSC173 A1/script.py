import pandas as pd
import matplotlib.pyplot as plt

# Read the Excel file
df1 = pd.read_excel('DFW rate and equity gaps by course 2022-08-08.xlsx', sheet_name='DFW rate and equity gaps by course 2022-08-0')

# Print the contents of the DataFrame
print(df1)