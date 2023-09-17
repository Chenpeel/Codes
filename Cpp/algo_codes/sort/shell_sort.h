#include <iostream>

template <typename T>
void shell_sort(T list[],int size){
    int i ,j ,gap;
    T temp;
    for(gap = size/2;gap>0;gap/=2){
        for(i = gap;i<size;i++){
            temp = list[i];
            for(int j = i;j>=gap&& list[j-gap]>temp;j-=gap){
                list[j]=list[j-gap];
            }
            list[j] = temp;
        }
    }
}