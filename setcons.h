#ifndef SETCONS_H
#define SETCONS_H

#include<set>
#include"nfa.h"
#include"dfa.h"

using std::set;

set<int> Eps_Closure(Nfa_t* nfa, Node_t *e);
Dfa_t* Set_Cons(Nfa_t* nfa);

#endif
