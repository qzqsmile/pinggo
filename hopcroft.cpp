#include"hopcroft.h"
#include"nfa.h"
#include"dfa.h"

int set_count = 0;
map<int, Node_t*> num_to_nodes;

void Init_Dfa_hopcrof_new(Dfa_t* dfa, map<int, int>&mapping_table, Hopcrof_set &start_set,
    Hopcrof_set& accept_set, set<char>& accept_char){
    start_set.set_num = 0;
    accept_set.set_num = 1;
    Node_t *nodes = dfa->nodes;
    while(nodes){
        if((dfa->accepts.find(nodes->num)) != (dfa->accepts.end())){
            accept_set.include_nodes_num.insert(nodes->num);
            mapping_table[nodes->num] = accept_set.set_num;
        }else{
            start_set.include_nodes_num.insert(nodes->num);
            mapping_table[nodes->num] = start_set.set_num;
        }
        num_to_nodes[nodes->num] = nodes;
        Edge_t* edges = nodes->edges;
        while(edges){
            accept_char.insert(edges->c);
            edges = edges->next;
        }
        nodes = nodes->next;
    }
}

void hopcrof(Dfa_t* dfa, set<Hopcrof_set>& set_list, vector<vector<int> >&mapping_table){
    // first time initilize -1
    int last_time_count = -1;
    map<int, int> nodes_belong_to_set;
    set<char> accept_char;
    Hopcrof_set start_set, accept_set;
    Init_Dfa_hopcrof_new(dfa, nodes_belong_to_set, start_set, accept_set, accept_char);
    last_time_count = set_count = 2;
    while(last_time_count != set_count){
        for(set<char>::iterator iter = accept_char.begin(); iter != accept_char.end(); iter++){
            ;
        }
    }
}

