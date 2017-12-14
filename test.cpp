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

void Set_Nfa_print(Nfa_t* nfa)
{
  assert (nfa);
  Node_t* nodes = nfa->nodes;
  assert (nodes);
  printf("set nfa is: \n");
  while (nodes){
    Edge_t* edges = nodes->edges;
    while (edges){
      printf ("%d ----(%d)----> %d\n"
              , edges->from->num
              , edges->c
              , edges->to->num);
      edges = edges->next;
    }
    nodes = nodes->next;
    // printf("Node %d contians",nodes->num);
    // for (set<int>::iterator iter = nodes->set_nodes.begin(); iter != nodes->set_nodes.end(); iter++){
    //     printf("%d ", *iter);
    }
}