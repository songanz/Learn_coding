#include "header.h" 
using namespace std;

// use union find set
class UnionFindSet {
public:
    // init
    UnionFindSet(int n) {
        ranks_ = vector<int>(n+1, 0);
        parents_ = vector<int>(n+1, 0);
        // 初始化成自己的parent是自己
        for (int i=0; i<parents_.size(); ++i) {
            parents_[i] = i;
        }
    }
    // merge set that contain u and v
    // return true if merged, false if u and v already in one set
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        // merge low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu]) parents_[pu] =pv;
        else if (ranks_[pv] < ranks_[pu]) parents_[pv] = pu;
        else {
            parents_[pu] = pv;
            ranks_[pv]++;
        }
        return true;
    }

    // get the root of u
    int Find(int u) {
        // path compression: 指向最根的节点
        if (u != parents_[u]) parents_[u] = Find(parents_[u]);
        return parents_[u];
    }
private:
    vector<int> ranks_;
    vector<int> parents_;
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, \
    vector< vector<string> >& pairs) {
        if (words1.size() != words2.size()) return false;
        UnionFindSet s(pairs.size()*2);
        unordered_map <string, int> word_m;
        for (auto& pair : pairs) {
            int u = getIndex(pair[0], word_m);
            int v = getIndex(pair[1], word_m);
            s.Union(u,v);
        }
        for (int i=0; i<words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            int u = getIndex(words1[i], word_m);
            int v = getIndex(words2[i], word_m);
            if (s.Find(u) != s.Find(v)) return false;
        }
        return true;
    }
private:
    int getIndex(string& word, unordered_map <string, int>& word_m) {
        int n = word_m.size();
        auto it = word_m.find(word);
        if (it == word_m.end()) {
            word_m[word] = n;
            return n;
        }
        return it->second;
    }
};

int main() {
    vector<string> words1 = {"great", "acting", "skills"};
    vector<string> words2 = {"fine", "drama", "talent"};
    vector< vector<string> > pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
    Solution s;
    cout << s.areSentencesSimilarTwo(words1, words2, pairs) << endl;
}