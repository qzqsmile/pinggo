#include<assert.h>
#include<iostream>
#include"dfa.h"
#include"nfa.h"

Dfa_t *Dfa_new()
{
  Dfa_t *dfa;
  return dfa;
}

Dfa_node* Dfa_t::find(set<int> nfa_node){
  for(vector<Dfa_node*>::iterator iter = dfa_nodes.begin(); iter != dfa_nodes.end(); iter++){
    if(((*iter)->nfa_nums) ==  nfa_node)
      return *iter;
  }
  return NULL;
}
