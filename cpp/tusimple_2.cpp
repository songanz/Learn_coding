#include "header.h"
using namespace std;

// 有一个邻接表，有num_jumps次跳跃次数，问从某个点开始，有多少条不同的跳跃次数

class Graph 
{ 
    int V;    // No. of vertices, value of vertix is from 0 to V-1
    // Pointer to an array containing adjacency lists 
    list<int> *adj;

public: 
    Graph(int V);   // Constructor 
    ~Graph(){  // Deconstructor
        delete[] adj;  // 针对数组的delete
    }

    // function to add an edge to graph 
    void addEdge(int v, int w);  // Add w to v’s list. 
    int countPaths(int s, int k);  // start from s, jump k step 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V];  // [FIX] Deconstructor
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 

int Graph::countPaths(int s, int k){
    // BFS: k is the level of BFS
    queue<int> q, qNextLevel;
    q.emplace(s);
    int level = 0;

    while (level<k) {
        while (!q.empty()){
            list<int> curr = adj[q.front()];
            q.pop();
            for (auto i : curr){
                qNextLevel.emplace(i);
            }
        }
        level++;
        q = qNextLevel;
        qNextLevel = queue<int>();
    }

    // count how many node in level k
    int ans = 0;
    while (!q.empty()) {
        ans++;
        q.pop();
    }
    return ans;
}
  

// Driver code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << g.countPaths(0, 3) << '\n';

    return 0; 
} 