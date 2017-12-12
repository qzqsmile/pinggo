#ifndef SETCONS_H
#define SETCONS_H

#include<set>
#include"nfa.h"

using std::set;

struct Set_Node_t;

set<int> Eps_Closure(Nfa_t* nfa, Node_t *e);
Nfa_t* Set_Cons(Nfa_t* nfa);

#endif