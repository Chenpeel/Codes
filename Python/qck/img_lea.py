import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from PIL import Image

# 读取Excel数据
df = pd.read_excel('/Users/alpha/Desktop/Codes/Python/qck/LenzerheideFrontwithgraphs.xls')
numeric_df = df.drop(['Time (Date hh:mm:ss.ms)'], axis=1)
# 创建和美化图表
plt.figure(figsize=(10, 6))
sns.set_style("whitegrid")

# 这里使用Seaborn创建一个集群状的图表，你可以根据需要进行调整
sns.clustermap(numeric_df.corr(), cmap="coolwarm", linewidths=.5, annot=True, fmt=".2f")

# 保存图表
plt.savefig('enhanced_graph.png')

# 叠加到Lenzerheide图像
lenzerheide_img = Image.open('lenzerheide1.jpg')
graph_img = Image.open('enhanced_graph.png')

lenzerheide_img.paste(graph_img, (x_offset, y_offset), graph_img)

# 保存最终图像
lenzerheide_img.save('final_image.jpg')
