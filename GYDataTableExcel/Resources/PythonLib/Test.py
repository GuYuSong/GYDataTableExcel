import sys

module_path = sys.argv[1]
  
if module_path not in sys.path:  
    sys.path.append(module_path) 


import pandas as pd  

# 读取CSV文件  
df = pd.read_csv(module_path + 'Test.csv')  # 替换'your_file.csv'为你的CSV文件名  

# 将DataFrame保存为XLSX文件  
df.to_excel(module_path + 'output_file.xlsx', index=False)  # 替换'output_file.xlsx'为你想要的输出文件名，index=False表示不保存行索引