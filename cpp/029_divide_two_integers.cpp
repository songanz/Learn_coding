#include "header.h"
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long int abs_d1 = abs(dividend);
        long int abs_d2 = abs(divisor);
        if (abs_d1 < abs_d2) return 0;

        int r = abs_d1;
        int ans = 1;
        int temp = abs_d2;

        while ((r >> 1) > abs_d2) {
            r >>= 1; // 由于不能用除法，使用二进制移位实现 << i: 乘2的i次方； >> 除2的i次方
            ans <<= 1;
            temp <<= 1;
        }
        int res = abs_d1 - temp;
        if (res > abs_d2) {
            ans += 1;
        }

        if ((dividend*divisor) < 0) return -ans; 
        return ans;
    }
};

int main() {
    Solution s;
    int dividend = 10;
    int divisor = 3;
    cout << s.divide(dividend, divisor) << endl;


}