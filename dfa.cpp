#include<assert.h>
#include"dfa.h"
#include"nfa.h"

Node_t* SetDfa_lookupOrInsert(Dfa_t* nfa, int num)
{
    assert(nfa);
    Node_t* nodes = nfa->nodes;
    while(nodes){
        if(nodes->num == num){
            return nodes;
        }
        nodes = nodes->next;
    }
    Node_t* p = Node_new(num, nfa->nodes);
    nfa->nodes = p;
    return p;
}


Node_t* SetDfa_lookupOrInsert(Dfa_t* nfa, int num, set<int> search_nodes)
{
  assert(nfa);
  Node_t* nodes = nfa-> nodes;
  while(nodes){
    if(nodes->set_nodes == search_nodes)
      return nodes;
    nodes = nodes->next;
  }
  Node_t* p = Node_new(num, nfa->nodes);
  p->set_nodes = search_nodes;
  nfa->nodes = p;
  return p;
}

void Dfa_addEdge(Dfa_t* nfa, int from, int to, int c)
{
  Node_t* f = SetDfa_lookupOrInsert (nfa, from);
  Node_t* t = SetDfa_lookupOrInsert (nfa, to);
  f->edges = Edge_new (f, t, c, f->edges);
  return;
}

Dfa_t* Dfa_new ()
{
  Dfa_t* p;
  p = new Dfa_t;
  p->start = -1;
  p->nodes = 0;
  return p;
}
