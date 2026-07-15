# Note

#### 1. 类型增强

相比于C， C++对类型的检查更为严格



在C语言中 

- `const * `  -> `non-const *`
-  `void * `  -> `sometype *`	
- `some type* `  -> `some type *`

转换是被允许的



但在C++在则编译不通过

如：`cannot initialize a variable of type "int *" with an rvalue of type "const int *" `





#### 2. 逻辑类型bool

C++引入了bool类型 用于真值表示，其更加符合人类的感官

bool类型占据一个字节



#### 3. 枚举enum

在C++中允许枚举任意类型元素用于取代宏常量

```cpp
#include <iostream>
enum Season {
  Spring, 
  Summer, 
  Fall, 
  Winter
};
int main(){
	enum Season S = Spring;
  return 0;
}
```

#### 4. 可被赋值的表达式

可以将表达式作为被赋值的对象，使用括号将其区分 

```cpp
#include <iostream>
int main(){
  int a =3, b = 5;
  (a>b?a:b) = 10;
  std::cout << "a : " <<a <<",b : " <<b <<std::endl;
  return 0;
}
```

#### 5.  nullptr

为了避免语意上混淆，C++11引入了nullptr 与NULL 和0 对应



#### 6. 标准输入输出

`std::cin`和`std::cout`

分别对应了I/O设备：键盘和屏幕

通过流的方式将I/O传输到对应位置，这个库函数封装了对输入输出的多种规格整理，以及安全地I/O



#### 7. 函数重载

C++的函数包括运算符都是可以重载的

重载是有严格匹配的，未找到的函数可能回通过隐式类型转换

- `int -> long / double `
- `double -> int / float`
- `int -> short / char`
- ...

如果重载函数碰到隐式类型转换，编译报错ambiguous，引起二义性

#### 8. extern C

C++默认通过命名倾轧(Name Manling)的方式将函数进行编译，因此能够实现重载，在编译后

同名函数可能会被编译成不同名的函数从而实现重载

```cpp
void func(int a) // 编译后 -> func_i()
void func(float a) // 编译后 -> func_f()
```

通过使用`extern  "C"`的方式，使得特定内容避免C++的命名倾轧

可以使C++向后兼容C标准库 以及一些未使用C++标准编写的库，从而避免C标准库在链接失败



