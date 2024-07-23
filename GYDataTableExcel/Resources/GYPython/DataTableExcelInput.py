import sys

module_path = sys.argv[1]
Xlsx_path = sys.argv[2]
  
if module_path not in sys.path:  
    sys.path.append(module_path) 


import pandas as pd  

# 读取Xlsx文件  
df = pd.read_excel(Xlsx_path + '.xlsx', engine='openpyxl')  # 使用openpyxl引擎读取xlsx文件

# 将DataFrame保存为XLSX文件  
df.to_csv(Xlsx_path + '.csv', index=False)  # 保存到CSV文件，index=False表示不保存行索引