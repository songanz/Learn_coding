#include "header.h"
using namespace std;

// merge-sort 有点慢
class Solution {
public:
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
// heap sort
class Solution2 {
public:
    
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        heapSort(nums, nums.size());
        return nums;
    }
private:
    void heapify(vector<int>& a, int n, int i) {
        /*
        a: array to be sorted
        n: size
        i: root node index
        */
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l<n && a[l] > a[largest]) largest = l;
        if (r<n && a[r] > a[largest]) largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            // recursively heapify
            heapify(a, n, largest);
        }
    }
    void heapSort(vector<int>& a, int n) {
        // build heap
        for (int i = n/2-1; i >= 0; --i) heapify(a, n, i);
        // one by one extract
        for (int i = n-1; i>=0; --i) {
            swap(a[0], a[i]);
            // call heapify with reduced heap
            heapify(a, i, 0);
        }
    }
    
};

int main() {
    Solution s;
    Solution2 ss;
    vector<int> nums = {5, 2, 3, 1};
    // s.sortArray(nums); 
    nums = ss.sortArray(nums); 
    for (int i = 0; i < nums.size(); ++i) 
        cout << nums[i] << " "; 
    cout << "\n";
}