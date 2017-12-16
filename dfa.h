#ifndef DFA_H
#define DFA_H

#include"nfa.h"

struct Dfa_t
{
  int start;     // start node of an NFA
  Node_t* nodes;  // a list of all nodes
  vector<int> accepts;
};

Dfa_t* Dfa_new ();
void Dfa_addEdge(Dfa_t* nfa, int from, int to, int c);
Node_t* SetDfa_lookupOrInsert(Dfa_t* nfa, int num);
Node_t* SetDfa_lookupOrInsert(Dfa_t* nfa, int num, set<int> search_nodes);


#endif
