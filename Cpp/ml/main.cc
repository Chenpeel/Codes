#include <iostream>
#include "include/eigen3/Eigen/Dense"

using namespace Eigen;
using namespace std;


template <typename T>
using Mat2 = Matrix<T, 3, 3>;

int main(int argc,char *argv[]) {

  Mat2<int> mat1;
  mat1 << 1, 2, 1, 2, 4 ,2 , 1, 2, 1;
  cout << mat1 << endl;

  return 0;
}

