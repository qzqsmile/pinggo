#include"test.h"
#include"setcons.h"
#include<stdio.h>
#include<assert.h>
#include<iostream>

using namespace::std;

void TestClosure(Nfa_t* nfa, int num)
{
  Node_t* e = Nfa_lookupOrInsert(nfa, num);
  set<int> nodes= Eps_Closure(nfa, e);
  for(set<int>::iterator iter = nodes.begin(); iter != nodes.end(); iter++){
    cout << ' '<< *iter;
  }
}

void Set_Dfa_print(Dfa_t* nfa)
{
  assert (nfa);
  printf("set nfa is: \n");
  for(vector<Dft_node*>::iterator iter = nfa->dfa_nodes.begin(); iter != nfa->dfa_nodes.end(); iter++){
    for(map<int, int>::iterator edge_iter = (*iter)->dfa_mapping.begin(); edge_iter!= (*iter)->dfa_mapping.end(); edge_iter++){
      cout << (*iter)->num << "----" << edge_iter->first << "-----" << edge_iter->second << endl;
    }
  }

  for(vector<Dft_node*>::iterator iter = nfa->dfa_nodes.begin(); iter != nfa->dfa_nodes.end(); iter++){
    cout << "DFA node num is: " << (*iter)->num << endl;
    for(set<int>::iterator set_iter = (*iter)->nfa_nums.begin(); set_iter != (*iter)->nfa_nums.end(); set_iter++){
      cout << " "<<*set_iter;
    }
    cout << endl;
  }
}