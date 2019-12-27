#include "header.h"
using namespace std;

// 给一个长度为n的数字阵列arr，已知阵列中除了某k个数字被替换过，其余的数字是已序
// example: n = 10, k = 2, arr = [0, 1, 2, "1", 4, 5, "10", 7, 8, 9] (""中的数字为被替换过的数字)
// 并且假设k远小于n，要求用低于O(nlgn)的做法把阵列排序
// 解法: 可以当做k个sorted array做merge，复杂度为O(nlgk)

typedef pair<int, pair<int, int> > pint_pii; 

vector<int> mergeKSortedArrs(vector< vector<int> >& sortedArrs) {
    vector<int> ans;

    // Create a min heap of size k and 
    priority_queue<pint_pii, vector<pint_pii>, greater<pint_pii> > pq;
    // insert 1st element in all the arrays into the heap
    for (int i=0; i<sortedArrs.size(); i++) {
        pq.push({ sortedArrs[i][0], { i, 0 } });
    }
    // Repeat following steps while priority queue is not empty.
        // a) Remove minimum element from heap (minimum is always at root) and store it in output array.
        // b) Insert next element from the array from which the element is extracted.
        // b) If the array doesn’t have any more elements, then do nothing.
    while (pq.empty() == false) { 
        pint_pii curr = pq.top(); 
        pq.pop(); 
  
        // i ==> Array Number 
        // j ==> Index in the array number         
        int i = curr.second.first;   
        int j = curr.second.second;  
  
        ans.push_back(curr.first); 

        if (j + 1 < sortedArrs[i].size()) 
            pq.push({ sortedArrs[i][j + 1], { i, j + 1 } }); 
    }
    return ans;    
}

vector<int> sortedArr(vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    arr.push_back(INT32_MAX);
    
    vector< vector<int> > sortedArrs;
    vector<int> res;

    for (int i=1; i<arr.size(); i++) {
        if (arr[i-1] > arr[i]) {
            sortedArrs.push_back({arr[i], arr[i-1]});
            i++;
            }
        else res.push_back(arr[i-1]);
    }

    sortedArrs.push_back(res);

    vector<int> ans = mergeKSortedArrs(sortedArrs);
    return ans;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 1, 4, 5, 10, 7, 8, 9};
    vector<int> arr2 = {0, 1, 2, 1, 4, 5, 7, 8, 9, 1};
    vector<int> arr3 = {2, 1, 2, 3, 4, 5, 7, 8, 9, 1};
    vector<int> arr4 = {2, 1, 2, 1, 4, 5, 6, 7, 8, 9};
    vector<int> ans = sortedArr(arr3);

    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}