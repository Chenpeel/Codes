#include <random>
using namespace std;

// 生成随机数返回
random_device rd;
mt19937 gen(rd()); //梅森旋转算法的伪随机数
uniform_int_distribution<> dis_int(1, 100);
uniform_real_distribution<> dis_float(0.0, 1.0);

int rd_int() {
  int res_rd = dis_int(gen);
  return res_rd;
}
float rd_float() {
  float res_rd = dis_float(gen);
  return res_rd;
}