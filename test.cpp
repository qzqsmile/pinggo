#include"test.h"
#include"setcons.h"
#include"hopcroft.h"
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
  for(vector<Dfa_node*>::iterator iter = nfa->dfa_nodes.begin(); iter != nfa->dfa_nodes.end(); iter++){
    for(map<int, int>::iterator edge_iter = (*iter)->dfa_mapping.begin(); edge_iter!= (*iter)->dfa_mapping.end(); edge_iter++){
      cout << (*iter)->num << "----" << edge_iter->first << "-----" << edge_iter->second << endl;
    }
  }

  for(vector<Dfa_node*>::iterator iter = nfa->dfa_nodes.begin(); iter != nfa->dfa_nodes.end(); iter++){
    cout << "DFA node num is: " << (*iter)->num << endl;
    for(set<int>::iterator set_iter = (*iter)->nfa_nums.begin(); set_iter != (*iter)->nfa_nums.end(); set_iter++){
      cout << " "<<*set_iter;
    }
    cout << endl;
  }
}

void HopCrof_Set_print(Hopcrof_set * hopcrof_set){
  for(vector<Hopcrof_Node *>::iterator hopcrof_iter = hopcrof_set->hopcrof_nodes.begin();
  hopcrof_iter != hopcrof_set->hopcrof_nodes.end(); hopcrof_iter++){  
    for(map<int, int>::iterator edge_iterator = (*hopcrof_iter)->edges.begin(); edge_iterator != (*hopcrof_iter)->edges.end(); edge_iterator++){
      printf("%d----%d----%d\n", (*hopcrof_iter)->num, edge_iterator->first, edge_iterator->second);
    }
  }
  // print hopcrof set detail
  printf("Start node is %d \n", hopcrof_set->start);
  printf("Accept nodes are:\n");
  for(vector<int>::iterator iter = hopcrof_set->accepts.begin(); iter != hopcrof_set->accepts.end(); iter++){
      cout << " " << *iter;
  }
  cout << endl;

  for(vector<Hopcrof_Node *>::iterator hopcrof_iter = hopcrof_set->hopcrof_nodes.begin();
  hopcrof_iter != hopcrof_set->hopcrof_nodes.end(); hopcrof_iter++){  
    cout << "Hopcrof set " <<(*hopcrof_iter)->num << " include dfa nodes: " << endl;
    for(set<Dfa_node *>::iterator dfa_iter = (*hopcrof_iter)->dfa_nodes.begin(); dfa_iter != (*hopcrof_iter)->dfa_nodes.end(); dfa_iter++){
      cout << " " << (*dfa_iter)->num;
    }
    cout << endl;
  }
}