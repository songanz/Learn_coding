#include "header.h"
using namespace std;

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
必须用二分法才能满足题目要求: https://www.youtube.com/watch?v=KB9IcSCDQ9k
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        // 只在小的数组上做二分搜索
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        const int k = (n1 + n2 + 1)/2;  // k是左中位数，为什么要加1: 因为int直接赋值会：舍去小数部分！！！

        int l = 0;  // 左位
        int r = n1;  // 右位: 一共只需要搜n1个

        // 二分搜索 Binary search
        while (l < r) {
            const int m1 = l + (r - l)/2;  // nums1中取第几个
            const int m2 = k - m1;
            if (nums1[m1] < nums2[m2 -1]) 
                l = m1 + 1;
            else
                r = m1; 
        }
        const int m1 = l;
        const int m2 = k - l;

        const int c1 = max(m1 <= 0 ? INT32_MIN: nums1[m1 - 1], m2 <= 0? INT32_MIN: nums2[m2-1]);

        if ((n1 + n2) % 2 == 1) {
            return c1;
        }

        const int c2 = min(m1 >= n1 ? INT32_MAX: nums1[m1], m2 >= n2 ? INT32_MAX: nums2[m2]);

        return double((c1+c2)*0.5);
    }
};

int main() {
    Solution s;
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);

    nums2.push_back(5);
    nums2.push_back(6);
    nums2.push_back(7);
    nums2.push_back(9);

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

}