#include"test.h"
#include"setcons.h"
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
