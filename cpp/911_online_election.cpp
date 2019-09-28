#include "header.h"
using namespace std;

class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int> persons, vector<int> times) {
    vector<int> votes(persons.size() + 1);
    int last_lead = persons.front();
    for (int i = 0; i < persons.size(); ++i) {
      if (++votes[persons[i]] >= votes[last_lead])
        last_lead = persons[i];      
      leads_[times[i]] = last_lead;      
    }
  }
 
  int q(int t) {
    return prev(leads_.upper_bound(t))->second;
  }
private:
  map<int, int> leads_; // time -> lead
};

int main() {
    vector<int> persons = {0,1,1,0,0,1,0};
    vector<int> times = {0,5,10,15,20,25,30};
    TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
    int param_1 = obj->q(12);
    cout << param_1 << endl;
}