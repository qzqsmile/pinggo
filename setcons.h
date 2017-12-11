#ifndef SETCONS_H
#define SETCONS_H

#include<set>
#include"nfa.h"

using std::set;

set<Node_t*> Eps_Closure(Nfa_t* nfa, Node_t *e);

#endif