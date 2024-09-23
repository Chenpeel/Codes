#include <iostream>
#include <vector>
using namespace std;

int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int n = divisors.size();
    int max_d = 0, max_d_pos = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % divisors[i] == 0) {
                k++;
            }
        }
        if (k > max_d || (k == max_d && divisors[i] < divisors[max_d_pos])) {
            max_d = k;
            max_d_pos = i;
        }
    }
    cout << "max_d: " << max_d << "\nmax_d_pos: " << max_d_pos << endl;
    return divisors[max_d_pos];
}

int main() {
    vector<int> nums = {73,13,20,6};
    vector<int> divisors = {56,75,83,26,24,53,56,61};
    int out = maxDivScore(nums, divisors);
    cout << out << endl;
    return 0;
}

