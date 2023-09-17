<center>

## The STL.md is learn from "侯捷"

## STL六大部件 (Components)
### 1. 容器 conrainers
### 2. 分配器 allocators
### 3. 算法  algorithms
### 4. 迭代器 iterators
### 5. 适配器 adpters
### 6. 仿函式 functors
</center>


~~~ 

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


int main(){
	vector<int,allocator<int>> v(ia,ia+6);
	//vector is the container
	//and the allocator mostly do not must be written

	cout<<count_if(v.begin(),v.end(),notl(bind2nd(less<int>(),40)));
	//the "count_if" is the algorithm
	//the "v.begin(),v.end()" are iterators 
	//the "notl()" is a function adapter(negator) 
	//the "bind2nd" is a function adapter(binder)
 	//the "less<int>()" is a function object

	return 0;
}
~~~


``` 
std::vector <double> vec
for (auto elem : vec ){
	//auto 据右推左
	std::cout<<elem<<std::endl;
} 
```


### Containers
#### Sequence Containers 序列式容器
1. array

	`array<long,100> a;`

	`array.data() //数组的起始地址`

2. vector 

	`v.push_back();`
	`v.emplace_back();`

	 两者底层机制不同，push_back()会先创建元素，再拷贝进v,而emplace_back()直接在v末尾创建元素
	
	`auto elem = ::find(v.begin(),v.end(),target)//auto = iterator`

	寻找target

3. deque 			

4. list 			//链表

	

5. forward-list 	//单向链表(内存空间利用率高)

#### Associative Containers 关联式的容器 	(通过key快速地排序、查找)
1. Set/Multiset

2. Map/Multimap

#### Unordered Containers (May a kind of associative containers)
1. Unordered Set/Multiset

2. Unordered Map/Multimap

- HashTable Separate Chaining



