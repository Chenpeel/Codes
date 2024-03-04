#include <iostream>
#include <vector>

using namespace std;

// func_1: insert && sort

void insert_sort(int* v, int n) {
  // insert
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // sort
  int temp, i;
  for (int j = 0; j < n; j++) {
    temp = v[j];
    i = j - 1;
    while (i > 0 && v[i] > temp) {
      v[i + 1] = v[i];
      i--;
    }
    v[i + 1] = temp;
  }
}

// func_2 : recursive_sort
void recursive_sort(int* nums, int n) {
    
}

int main() {
  // for tht insert test
  int *nums, n;
  cin >> n;
  nums = new int[n];
  insert_sort(nums, n);
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  delete nums;


  cin>> n;
  nums = new int[n];
  recursive_sort(nums,n);

  return 0;
}