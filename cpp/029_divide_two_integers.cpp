#include "header.h"
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT32_MIN && divisor == -1)
                return INT32_MAX;
        
        long _divisor = labs(divisor);
        long _dividend = labs(dividend);
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;  
        /* Bitwise exclusive OR
        0 ^ 0 = 0;
        0 ^ 1 = 1; 
        1 ^ 0 = 1; 
        1 ^ 1 = 0
        */
        int count = 0;
        long temp;
        long sol = 0;
        while(_dividend >= _divisor)
        {
            count = 1;
            temp = _divisor;
            while(temp << 1 <= _dividend)
            {
                temp = temp << 1;  // 由于不能用除法，使用二进制移位实现 << i: 乘2的i次方； >> 除2的i次方
                count = count << 1;
            }
            sol += count;
            _dividend -= temp;
        }
        if(sol > INT32_MAX || sol < INT32_MIN)  // overflow 问题
            return INT32_MAX;
        return sign == 1 ? sol : -sol;
    }
};


int main() {
    Solution s;
    // int dividend = -2147483648;
    int dividend = 2147483647;
    // int dividend = 10;
    int divisor = 1;
    // int divisor = 3;
    cout << s.divide(dividend, divisor) << endl;
}