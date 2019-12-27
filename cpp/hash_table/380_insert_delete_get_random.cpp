#include "../header.h"
using namespace std;

// 题目要求O(1): hashtable 强暗示 使用基础数据类型unordered_map，不是map(对应红黑树)！！！
// getRandom():直接拿出随机元素 --> vector支持随机访问
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 找到了，返回false
        if (m_.find(val) != m_.end()) return false;
        // 找不着，加进去，返回true
        m_[val] = a_.size();
        a_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 找不着，返回false
        if (m_.find(val) == m_.end()) return false;
        // 找到了，移除，返回true
        int index = m_[val];
        // 移除的时候，把index和最后一个元素的index交换，然后移除，保证时间复杂度O(1)
        m_[a_.back()] = index;
        m_.erase(val);
        // 在数组中删除
        swap(a_[index], a_.back());  // Exchanges the values of a and b
        a_.pop_back();  // 弹出最后一个element
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand() % a_.size();
        return a_[i];        
    }
private:
    unordered_map<int, int> m_;  // key是value，为了用map的查找，第二个元素是在array里面的位置
    vector<int> a_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet r;
    r.insert(1);
    r.insert(2);
    cout << r.insert(2) << endl;
    r.insert(3);
    cout << r.remove(4) << endl;
    r.remove(3);
    cout << r.getRandom() << endl;    
}