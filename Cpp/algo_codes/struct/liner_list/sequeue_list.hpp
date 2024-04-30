#ifndef SEQUEUE_LIST_HPP
#define SEQUEUE_LIST_HPP

#include <iostream>

#define LIST_INIT_SIZE 50
#define LIST_INCRE 30

template <typename T>
class Sequeue_List{
private:
    T *elem;
    int length;
    int listSize;

protected:
    void ReNew(){
        T *new_elem = new T[length + LIST_INCRE];
        for(int i =0;i<length;i++){
            new_elem[i] = elem[i];
        }
        listSize += LIST_INCRE;
        elem = new_elem;
    }

public:
    Sequeue_List():elem(nullptr),listSize(0),length(0){
        elem = new T[LIST_INIT_SIZE];
        listSize = LIST_INIT_SIZE;
        length = 0;
    }

    ~Sequeue_List(){
        delete[] elem;
    }
    
    void Print(){
        std::stringstream ss;
        ss << "[";
        for(int i=0;i<length;i++){
            ss << elem[i];
            if(i != length-1){
                ss << ", ";
            }
        }
        std::string result = ss.str();
        result += "]";
        std::cout << result << std::endl;
    }

    void Insert(const int i, const T e){
        if(i<1 || i > length) {
            std::cout << "Wrong Position"<<std::endl;
            return;
        }
        if(length>=listSize)
            ReNew();
        for(int k =length-1;k>i;k--){
            elem[k+1] = elem[k];
        }
        elem[i-1] = e;
        length++;
    }

    void AddElem(const T e){
        length++;
        if(length >= listSize) ReNew();
        elem[length-1] = e;
    }

    void DeleteElem(const int i){
        if(i<1 || i > length) {
            std::cout << "Wrong Position"<<std::endl;
            return;
        }
        for(int k = i-1;k < length;k++){
            elem[k] = elem[k+1];
        }
        length--;
    }

    int GetElem(const T e){
        for(int i=0;i<length;i++){
            if(elem[i] == e) return i+1;
        }
        std::cout << "can't found " << e << std::endl;
        return false;
    }
};


template<typename T>
void Merge_Sqlist(const Sequeue_List<T> &L1, const Sequeue_List<T> &L2, Sequeue_List<T> &L){
    L.length = L1.length + L2.length;
    L.listsize = L.length;
    L.elem = new T[L.listSize];
    T *p1 = L1.elem, *p2 = L2.elem, *p = L.elem;
    const T *p1l = L1.elem + L1.length - 1, *p2l = L2.elem + L2.length - 1;
    while (p1 <= p1l && p2 <= p2l){
        if(*p1 <= *p2) *p++ = *p1++;
        else *p++ = *p2++;
    } 
    while (p1 <= p1l) *p++ = *p1++;
    while (p2 < p2l) *p++ = *p2++;
    delete[] p1;
    delete[] p2;
}

#endif
