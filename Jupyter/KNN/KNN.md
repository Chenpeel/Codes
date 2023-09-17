<a href = "https://github.com/Chenpeel/Notes-of-CS/blob/master/notes_md/machine_learn.md">返回</a>

> # KNN算法

> ### KNN分类预测


```python
import numpy as np
import pandas as pd
```

#### header 参数指定标题行，默认0 没有标题设置None


```python
data = pd.read_csv(r'./files/iris.csv',header=0)
data.head()     # 首位5行默认为5"
data.tail()     # 末尾n行默认为5
data.sample()   # 随机抽取默认为1
data
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>species</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.1</td>
      <td>3.5</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>setosa</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.9</td>
      <td>3.0</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>setosa</td>
    </tr>
    <tr>
      <th>2</th>
      <td>4.7</td>
      <td>3.2</td>
      <td>1.3</td>
      <td>0.2</td>
      <td>setosa</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4.6</td>
      <td>3.1</td>
      <td>1.5</td>
      <td>0.2</td>
      <td>setosa</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5.0</td>
      <td>3.6</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>setosa</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>145</th>
      <td>6.7</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.3</td>
      <td>virginica</td>
    </tr>
    <tr>
      <th>146</th>
      <td>6.3</td>
      <td>2.5</td>
      <td>5.0</td>
      <td>1.9</td>
      <td>virginica</td>
    </tr>
    <tr>
      <th>147</th>
      <td>6.5</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.0</td>
      <td>virginica</td>
    </tr>
    <tr>
      <th>148</th>
      <td>6.2</td>
      <td>3.4</td>
      <td>5.4</td>
      <td>2.3</td>
      <td>virginica</td>
    </tr>
    <tr>
      <th>149</th>
      <td>5.9</td>
      <td>3.0</td>
      <td>5.1</td>
      <td>1.8</td>
      <td>virginica</td>
    </tr>
  </tbody>
</table>
<p>150 rows × 5 columns</p>
</div>




```python
data['species'] = data['species'].map({'setosa':0,'virginica':1,'versicolor':2})
data
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>species</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.1</td>
      <td>3.5</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.9</td>
      <td>3.0</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>4.7</td>
      <td>3.2</td>
      <td>1.3</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4.6</td>
      <td>3.1</td>
      <td>1.5</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5.0</td>
      <td>3.6</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>145</th>
      <td>6.7</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.3</td>
      <td>1</td>
    </tr>
    <tr>
      <th>146</th>
      <td>6.3</td>
      <td>2.5</td>
      <td>5.0</td>
      <td>1.9</td>
      <td>1</td>
    </tr>
    <tr>
      <th>147</th>
      <td>6.5</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>148</th>
      <td>6.2</td>
      <td>3.4</td>
      <td>5.4</td>
      <td>2.3</td>
      <td>1</td>
    </tr>
    <tr>
      <th>149</th>
      <td>5.9</td>
      <td>3.0</td>
      <td>5.1</td>
      <td>1.8</td>
      <td>1</td>
    </tr>
  </tbody>
</table>
<p>150 rows × 5 columns</p>
</div>




```python
data.duplicated().any()
data.drop_duplicates(inplace=True)
data['species'].value_counts()
```




    species
    2    50
    1    49
    0    48
    Name: count, dtype: int64




```python
class KNN_C:
    def __init__(self,k) -> None:
        # 初始化
        self.k = k
    
    def fit(self,X,y):
        '''
        训练方法
        
        ------
        X:  类数组类型,形状为:[样本数量,特征数量]
            带训练的样本特征
        
        y:  类数组类型,形状为:[样本数量]
            每个样本的目标值,标签
        '''
        # 将X转化成ndarray
        self.X = np.asarray(X) 
        self.y = np.asarray(y)
        
    def predict_basic(self,X):
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
            # 选出对应位置的y 统计次数
            count = np.bincount(self.y[index])
            # 最多的次数
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
            count = np.bincount(self.y[index],weights=1/distance[index])
            # 最多的次数
            result.append(count.argmax())
        return np.asarray(result)
```


```python
# 分割训练集和测试集
# 提取每个类别的数据
t0 = data[data['species']==0]
t1 = data[data['species']==1]
t2 = data[data['species']==2]
t0 = t0.sample(len(t0),random_state=0)
t1 = t1.sample(len(t1),random_state=0)
t2 = t2.sample(len(t2),random_state=0)

# 构建训练集 测试集
train_X = pd.concat([t0.iloc[:40,:-1],t1.iloc[:40,:-1],t2.iloc[:40,:-1]],axis=0)
train_y = pd.concat([t0.iloc[:40,-1],t1.iloc[:40,-1],t2.iloc[:40,-1]],axis=0)

test_X = pd.concat([t0.iloc[40:,:-1],t1.iloc[40:,:-1],t2.iloc[40:,:-1]],axis=0)
test_y = pd.concat([t0.iloc[40:,-1],t1.iloc[40:,-1],t2.iloc[40:,-1]],axis=0)

knn = KNN_C(k = 3)
# 训练
knn.fit(train_X,train_y)
# 测试
result = knn.predict(test_X)

# display(result)
# display(test_y)
display(np.sum(result==test_y)) 
display("Percent:", np.sum(result==test_y)/len(result))
```


    26



    'Percent:'



    0.9629629629629629



```python
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
```


```python
# 可用的字体类型
for font in fm.fontManager.ttflist:
    # print(font.name,end=' ')
    pass
```


```python
# 默认英文
# 设置黑体
mpl.rcParams['font.family'] = "Heiti TC"
# 设置负号(-)
mpl.rcParams['axes.unicode_minus'] = False
```


```python
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
```




    <matplotlib.legend.Legend at 0x131e852d0>




    
![png](KNN_files/KNN_13_1.png)
    


> ### KNN回归预测


```python
import numpy as np
import pandas as pd
```


```python
data = pd.read_csv('./files/iris.csv')
data.drop(['species'],axis=1,inplace=True)
data.drop_duplicates(inplace=True)
data
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.1</td>
      <td>3.5</td>
      <td>1.4</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.9</td>
      <td>3.0</td>
      <td>1.4</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>4.7</td>
      <td>3.2</td>
      <td>1.3</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4.6</td>
      <td>3.1</td>
      <td>1.5</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5.0</td>
      <td>3.6</td>
      <td>1.4</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>145</th>
      <td>6.7</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.3</td>
    </tr>
    <tr>
      <th>146</th>
      <td>6.3</td>
      <td>2.5</td>
      <td>5.0</td>
      <td>1.9</td>
    </tr>
    <tr>
      <th>147</th>
      <td>6.5</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.0</td>
    </tr>
    <tr>
      <th>148</th>
      <td>6.2</td>
      <td>3.4</td>
      <td>5.4</td>
      <td>2.3</td>
    </tr>
    <tr>
      <th>149</th>
      <td>5.9</td>
      <td>3.0</td>
      <td>5.1</td>
      <td>1.8</td>
    </tr>
  </tbody>
</table>
<p>147 rows × 4 columns</p>
</div>




```python
class KNN_R:
    def __init__(self,k) -> None:
        # 初始化
        self.k = k
    
    def fit(self,X,y):
        '''
        训练方法
        
        ------
        X:  类数组类型,形状为:[样本数量,特征数量]
            带训练的样本特征
        
        y:  类数组类型,形状为:[样本数量]
            每个样本的目标值,标签
        '''
        # 将X转化成nparray
        self.X = np.asarray(X)
        self.y = np.asarray(y)
        
    def predict_basic(self,X):
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
        
        for x in X:
            # 标准差
                # s = x - self.X    
            # 欧氏距离
            distance= np.sqrt(np.sum((x-self.X)**2,axis=1))
            # 返回排序后原数组索引
            index = distance.argsort()
            # 取前K个 因此进行截断
            index =index[:self.k]
            result.append(np.mean(self.y[index]))
        return result
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
        
        for x in X:
            # 标准差
                # s = x - self.X    
            # 欧氏距离
            distance= np.sqrt(np.sum((x-self.X)**2,axis=1))
            # 返回排序后原数组索引
            index = distance.argsort()
            # 取前K个 进行截断 根据权重
            index =index[:self.k]
            s = np.sum(1/(distance[index]+0.000000000000000000000001))
            weigths = (1/(distance[index]+0.000000000000000000000001)) /s
            
            result.append(np.sum(weigths *self.y[index]))
        return result
```


```python
t = data.sample(len(data),random_state=0)

train_X = t.iloc[:120,:-1]
train_y = t.iloc[:120,-1]

test_X = t.iloc[120:,:-1]
test_y = t.iloc[120:,-1]

knn = KNN_R(k=3)
knn.fit(train_X,train_y) 
result= knn.predict(test_X)
display(result)
# 误差的方差
np.mean(np.sum(result-test_y)**2)
display(test_y.values)
```


    [1.3541198234291045,
     2.0402232927174335,
     1.155292304160408,
     1.2633077758149525,
     2.2,
     1.1633670813357746,
     2.1236921487241847,
     0.36951541759303386,
     1.8875,
     1.383592719605378,
     1.2079679356026762,
     0.1716699605900981,
     1.9768660060540153,
     2.23576080826668,
     1.6763297764921743,
     0.13818200321667007,
     1.0222015262012338,
     1.3,
     1.8555089482511353,
     1.2301527206179916,
     0.1729669293927397,
     0.24377407751375035,
     0.17101020514433646,
     2.0155337034831042,
     1.1878679656440359,
     1.8228307409608926,
     0.2]



    array([1.5, 1.8, 1. , 1.3, 2.1, 1.2, 2.2, 0.2, 2.3, 1.3, 1. , 0.2, 1.6,
           2.1, 2.3, 0.3, 1. , 1.2, 1.5, 1.3, 0.2, 0.4, 0.1, 2.1, 1.1, 1.5,
           0.2])



```python
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
```


```python
# 可用的字体类型
for font in fm.fontManager.ttflist:
    # print(font.name,end=' ')
    pass
```


```python
# 默认英文
# 设置黑体
mpl.rcParams['font.family'] = "Heiti TC"
# 设置负号(-)
mpl.rcParams['axes.unicode_minus'] = False
```


```python
plt.figure(figsize=(10,10))
plt.plot(result,'ro-',label="预测值")
plt.plot(test_y.values,'go--',label="真实值")
plt.title("KNN连续值预测")
plt.xlabel("节点序号")
plt.ylabel("花瓣宽度")
plt.show()
```


    
![png](KNN_files/KNN_22_0.png)
    


<a href = "https://github.com/Chenpeel/Notes-of-CS/blob/master/notes_md/machine_learn.md">返回</a>
