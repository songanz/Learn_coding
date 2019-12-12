#include "../header.h"
using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        // auto叫做placeholder type specifiers: The type is deduced from the initializer
        // auto必须初始化
        const auto it = m_.find(key);  // 找到对应的map item的地址
        // 由 end 操作返回的迭代器指向“末端元素的下一个”。表明它指向了一个不存在的元素。
        if (it == m_.cend()) return -1;
        // else move this key to the front of the list
        cache_.splice(cache_.begin(), cache_, it->second);  // it->second是cache_中pair的地址(put定义)
        return it->second->second;  // 
    }
    
    void put(int key, int value) {
        const auto it = m_.find(key);
        // if the key already exist
        if (it != m_.cend()) {
            it->second->second = value;
            // 放到最前面
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }

        // key does not exist: ！！！第一次存的时候
        if (cache_.size() == capacity_) {
            // 由 end 操作返回的迭代器指向的“末端元素的下一个”。表明它指向了一个不存在的元素。所以不能用cache_.end()
            const auto& node = cache_.back();
            // 删掉unordered_map里的node 
            m_.erase(node.first);  // node.first对应key; can erase by iterator, key or range
            // 删掉链表里的最后一个元素
            cache_.pop_back();
        }
        cache_.push_front(make_pair(key, value));
        m_[key] = cache_.begin();
        return;
    }
private:
    int capacity_;
    // need a hashtable and a list with pair to do it
    list< pair<int, int> > cache_;
    unordered_map<int, list <pair<int, int> >::iterator > m_;  // 指针，指向cache_里面的内容
};

int main() {
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    cout << l.get(1) << endl;  // 1
    l.put(3, 3);
    cout << l.get(2) << endl;  // -1 因为2已经那个被踢掉了
    l.put(4, 4);
    cout << l.get(1) << endl;  // -1 因为1已经那个被踢掉了
    cout << l.get(3) << endl;  // 3
    cout << l.get(4) << endl;  // 4
}