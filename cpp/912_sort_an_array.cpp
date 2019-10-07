#include "header.h"
using namespace std;

class Solution {
public:
    // merge-sort
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
    
private:
    // s:start index; e: end index
    void merge_sort(vector<int>& A, int s, int e) {
        if (s<e) {
            int q = (s + e) / 2;   
            merge_sort(A, s, q);
            merge_sort(A, q+1, e);
            merge(A, s, e, q);
        }        
    }
    
    void merge(vector<int>& A, int s, int e, int q) {
        vector<int> l(A.begin()+s, A.begin()+q+1);  // left array
        vector<int> r(A.begin()+q+1, A.begin()+e+1);   // right array
        l.push_back(INT32_MAX);
        r.push_back(INT32_MAX);
        int a = 0;
        int b = 0;
        for (int i=s; i<e+1; ++i) {
            if (l[a] < r[b]) {
                A[i] = l[a];
                a++;
            }
            else {
                A[i] = r[b];
                b++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    cout << s.sortArray(nums)[0] << '\n'; 
}