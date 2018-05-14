#ifndef DFA_H
#define DFA_H

#include<map>
#include<set>
#include<vector>

using namespace std;

struct Dfa_node{
  int num;
  set<int> nfa_nums;
  map<int, int> dfa_mapping;
  map<int, int> nfa_mapping;
};

struct Dfa_t
{
  public:
    int start;     // start node of an NFA
    vector<Dfa_node* > dfa_nodes; // a list of all nodes
    set<int> accepts;
    Dfa_node* find(set<int> nfa_node);
};

Dfa_t *Dfa_new();

#endif
