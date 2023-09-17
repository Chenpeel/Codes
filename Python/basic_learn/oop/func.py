class func:
    empCount = 0 # 类变量
    
    def __init__(self) -> None:
        # 构造方法/初始化
        # self 代表实例
        pass
    """
    内置类属性
    def __dict__(self) -> None:
        # 类的属性
        pass
    def __name__(self) -> None:
        # 类名
        pass
    def __doc__(self) -> None:
        # 类的文档字符串
        pass
    def __module__(self) -> None:
        # 类定义所在的模块
        pass
    def __bases__(self) -> None:
        # 类的所有父类构成元素
        pass
        
    """
    
    def __del__(self) ->None:
        # 析构函数 在对象销毁时使用
        pass

    def __private_method(self) -> None:
        # 私有方法以"__"开始
        pass

class function(func):
    # 继承自func类
    empCount = 1 
    