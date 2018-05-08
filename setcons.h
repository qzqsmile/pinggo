#ifndef SETCONS_H
#define SETCONS_H

#include<set>
#include<map>
#include"nfa.h"
#include"dfa.h"
#include"re.h"

using std::set;

set<int> Eps_Closure(Nfa_t* nfa, Node_t *e);
Dfa_t* Set_Cons(Nfa_t* nfa);
// void Edge_To_Mapping(Nfa_t* nft, map<int, int>& nft_mapping);
void Dft_Node_Edge_To_Mapping(Dft_node *dft_node, map<int, Node_t*>& nft_node);

#endif
