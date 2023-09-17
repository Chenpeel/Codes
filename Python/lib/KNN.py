import numpy as np
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm


data = pd.read_csv(r'../../jupyter/files/iris.csv',header=0)
data.head()
data.tail()
data.sample()

data['species'] = data['species'].map({'setosa':0 ,'virginica':1,'versicolor':2})


data.duplicated().any()
data.drop_duplicates()

print(data['species'].value_counts())

class KNN_C:
    def __init__(self,k) -> None:
        self.k = k

    def fit(self,X,y):
        '''
        X:  array 
            shape: [num[],feature[]]
        y:  array alike
            shape: [num[]]  
        trans X & y to np array
        '''
        self.X = np.asarray(X)
        self.y = np.asarray(y)
    
    def predict_C(self,X):
        X = np.asarray()
        result = []
        for row in X:
            # 欧式距离
            # $$
            distance = np.sqrt(np.sum(row-self.X)**2, axis=1)
            
            index = distance.argsort()
            index =index[:self.k]
            
            count = np.bincount(self.y[index])
            
            result.append(count.argmax())
            
        return np.asarray(result)
    def predict(self,X):
        '''
        根据参数传递的样本 对数据进行预测
        
        Parameters
        ------
        X:  类数组类型,形状为:[样本数量,特征数量]
            带训练的样本特征
        
        Returns
        ------
        result: 数组类型
                预测的结果
        '''
        
        X = np.asarray(X)
        result = []
    
        # 行遍历
        for x in X:
            # 标准差
                # s = x - self.X    
            # 欧氏距离
            distance= np.sqrt(np.sum((x-self.X)**2,axis=1))
            # 返回排序后原数组索引
            index = distance.argsort()
            # 取前K个 因此进行截断
            index =index[:self.k]
            # 选出对应位置的y 根据权重 统计次数
            count = np.bincount(self.y[index],weights=1 / np.maximum(distance[index], 1e-10))
            # 最多的次数
            result.append(count.argmax())
        return np.asarray(result)
    
t0 = data[data['species']==0]
t1 = data[data['species']==1]
t2 = data[data['species']==2]
t0 = t0.sample(len(t0),random_state=0)
t1 = t1.sample(len(t1),random_state=0)
t2 = t2.sample(len(t2),random_state=0)


train_X = pd.concat([t0.iloc[:40,:-1],t1.iloc[:40,:-1],t2.iloc[:40,:-1]],axis=0)
train_y = pd.concat([t0.iloc[:40,-1],t1.iloc[:40,-1],t2.iloc[:40,-1]],axis=0)

test_X = pd.concat([t0.iloc[40:,:-1],t1.iloc[40:,:-1],t2.iloc[40:,:-1]],axis=0)
test_y = pd.concat([t0.iloc[40:,-1],t1.iloc[40:,-1],t2.iloc[40:,-1]],axis=0)

knn = KNN_C(k=3)
knn.fit(train_X,train_y)
result = knn.predict(test_X)
  

print(np.sum(result==test_y)) 
print("Percent:", np.sum(result==test_y)/len(result))  

# Draw
mpl.rcParams['font.family'] = "Apple Chancery"
mpl.rcParams['font.family'] = "Heiti TC"
mpl.rcParams['axes.unicode_minus']= False

# 训练集
plt.scatter(x=t0['sepal_length'][:40],y=t0['petal_length'][:40],color='r',label='Iris-virginica')
plt.scatter(x=t1['sepal_length'][:40],y=t1['petal_length'][:40],color='g',label='Iris-setosa')
plt.scatter(x=t2['sepal_length'][:40],y=t2['petal_length'][:40],color='b',label='Iris-versicolor')
# 测试集
right = test_X[result==test_y]
wrong = test_X[result!=test_y]
plt.scatter(x=right['sepal_length'],y=right['petal_length'],color='c',marker='x',label='right')
plt.scatter(x=wrong['sepal_length'],y=wrong['petal_length'],color='m',marker='>',label='wrong')
plt.xlabel("花萼长度")
plt.ylabel("花瓣长度")
plt.title("KNN分类结果显示")
plt.legend(loc='best')
plt.show()
