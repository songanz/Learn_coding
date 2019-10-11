#include "header.h"
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        int n = cost.size();
        vector<int> minCost_(n+1);
        minCost_[0] = cost[n-1];
        minCost_[1] = cost[n-2];
        cost.insert(cost.begin(), 0);
        for (int i=0; i<n-1; ++i) {
            minCost_[i+2] = min(cost[n-i-2]+minCost_[i], cost[n-i-2]+minCost_[i+1]);
        }
        return minCost_[n];
    }
};

int main() {
    Solution s;
    vector<int> cost = {15, 10, 20};
    cout << s.minCostClimbingStairs(cost) << '\n';
}