#ifndef HOPCROF_H
#define HOPCROF_H
#include"nfa.h"
#include"dfa.h"
#include<set>
#include<map>

using namespace::std;

struct Hopcrof_Node{
    int num;
    set<Dfa_node *> dfa_nodes;
    map<int, int> edges;
};

struct Hopcrof_set{
    int start;
    vector<int> accepts;
    vector<Hopcrof_Node* > hopcrof_nodes;
};

Hopcrof_set *Build_Hopcrof_set(Dfa_t *dfa_t);
void Hopcrof_Node_Accept_Char(set<int>& dfa_nodes, map<int, Dfa_node* >& num_to_dfa_nodes, set<int>& accept_chars);
void Update_Dfa_Node_HopCroft_Set(map<int, int>& num_to_hopcrof_set, map<int, set<int> >& set_include_nums);

#endif