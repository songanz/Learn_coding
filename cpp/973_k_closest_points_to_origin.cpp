#include "header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > kClosest(vector< vector<int> > & points, int K) {
        vector< pair<int, int> > toSort;
        pair<int, int> temp;
        for (int i = 0; i < points.size(); i++ ){
            temp = make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            toSort.push_back(temp);
        }
        sort(toSort.begin(), toSort.end());  // to sort the vector elements on the basis of first element of pairs in ascending order
        vector< vector<int> > ans;
        for (int i=0; i < K; i++){
            ans.push_back(points[toSort[i].second]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector< vector<int> > input;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    input.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(2);
    input.push_back(temp);
    int k = 1;

    for (int i = 0; i < k; i++) {
        cout << s.kClosest(input, k)[i][0] << ", " << s.kClosest(input, k)[i][1] << "\n";
    }
}