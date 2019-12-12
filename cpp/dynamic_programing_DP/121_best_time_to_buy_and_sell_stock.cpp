#include "../header.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int ans = INT32_MIN;
        for (int i=0; i<prices.size()-1; ++i) {
            for (int j=i+1; j<prices.size(); ++j) {
                if ((prices[j]-prices[i]) > ans) {
                    ans = prices[j]-prices[i];
                }
            }
        }
        if (ans < 0) return 0;
        return ans;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0, minPrice = INT32_MAX;
        // 肯定是要在最小值买进
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(prices[i] - minPrice, maxPro);
        }
        return maxPro;
    }
};

int main () {
    Solution s;
    vector<int> prices={7,1,6,3,8,3,4};
    cout << s.maxProfit(prices) << endl;
}