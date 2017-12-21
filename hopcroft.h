#ifndef HOPCROF_H
#define HOPCROF_H

#include"nfa.h"
#include<set>
#include<map>

using namespace::std;

struct Hopcrof_set;

// struct Dfa_hopcrof{
//     int start;     // start node of an NFA
//     int accept;
//     int count;
//     Hopcrof_set* hopcrof_sets;
// };

struct Hopcrof_set{
    int set_num;
    set<int> include_nodes_num;
};

#endif