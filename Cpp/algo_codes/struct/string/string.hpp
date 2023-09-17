#include <iostream>

class String {
private:
    char *str;
    int length;

public:
    // 构造函数
    String() : str(nullptr), length(0) {}

    // 析构函数
    ~String() {
        if (str) {
            delete[] str;
        }
    }

    // 重载赋值运算符
    String &operator=(const char *chars) {
        if (str) {
            delete[] str;
        }
        length = 0;
        while (chars[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = chars[i];
        }
        str[length] = '\0';
        return *this;
    }

    // 获取字符串长度
    int getLength() {
        return length;
    }

    // 字符串比较
    int compare(const String &other) {
        int i = 0;
        while (i < length && i < other.length) {
            if (str[i] != other.str[i]) {
                return str[i] - other.str[i];
            }
            i++;
        }
        return length - other.length;
    }

    // 字符串拼接
    String concat(const String &other) {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        for (int i = 0; i < length; i++) {
            result.str[i] = str[i];
        }
        for (int i = 0; i < other.length; i++) {
            result.str[length + i] = other.str[i];
        }
        result.str[result.length] = '\0';
        return result;
    }

    // 截取子串
    String substring(const int pos, const int len) {
        String sub;
        sub.length = len;
        sub.str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            sub.str[i] = str[pos + i];
        }
        sub.str[len] = '\0';
        return sub;
    }

    // 输出字符串
    void print() {
        std::cout << str << std::endl;
    }

    // 拷贝字符串
    void copy(const String &src) {
        if (str) {
            delete[] str;
        }
        length = src.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = src.str[i];
        }
        str[length] = '\0';
    }
};