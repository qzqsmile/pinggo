// powerset construction alogrithm
#include<assert.h>
#include<queue>
#include<map>
#include<set>
#include<iostream>
#include"nfa.h"
#include"dfa.h"
#include"setcons.h"

using std::set;
using std::endl;
using std::queue;

set<int> Eps_Closure(Nfa_t* nfa, Node_t *e)
{
    set<int> closure;
    queue<Node_t*> worklist;
    
    closure.insert(e->num);
    worklist.push(e);
    while(!worklist.empty()){
        Node_t* t = worklist.front();
        worklist.pop();
        Node_t* nodes = nfa->nodes;
        assert(nodes);
        while(nodes){
            if(nodes->num == t->num){
               Edge_t* edges = nodes->edges;
               while(edges){
                   if(edges->c == -2){
                        worklist.push(edges->to);
                        closure.insert(edges->to->num);
                   }
                   edges = edges->next;
               }
            }
            nodes = nodes->next;
        }
    }
    return closure;
}

void Dft_Node_Edge_To_Mapping(Dft_node *dft_node, map<int, Node_t*>& nft_node)
{
    for(set<int>::iterator iter = dft_node->nfa_nums.begin(); iter != dft_node->nfa_nums.end(); iter++){
        Edge_t * edges = nft_node[*iter]->edges;
        while(edges){
            if(edges->c != EPS)
                dft_node->nfa_mapping[edges->c] = edges->to->num;
            edges = edges->next;
        }
    }
}


Dfa_t* Set_Cons(Nfa_t* nfa)
{
    int set_code_count = 0;
    int accept = nfa->accept;    
    map<int, int> nft_mapping;
    Dfa_t* set_dfa = new Dfa_t();
    Dft_node* q0 = new Dft_node();
    queue<Dft_node*> worklist;
    int dft_node_count = 0;

    Node_t * nodes = nfa->nodes;    
    map<int, Node_t *> nft_node_map;
    while(nodes){
        nft_node_map[nodes->num] = nodes;
        nodes = nodes->next;
    }
    q0->nfa_nums = Eps_Closure(nfa, nft_node_map[0]);
    q0->num = dft_node_count++;    
    Dft_Node_Edge_To_Mapping(q0, nft_node_map);
    set_dfa->dfa_nodes.push_back(q0);
    worklist.push(q0);

    while(!worklist.empty()){
        Dft_node* node = worklist.front();
        worklist.pop();
        for(map<int,int>::iterator iter = node->nfa_mapping.begin(); iter != node->nfa_mapping.end(); iter++){
            set<int> eps_closure = Eps_Closure(nfa, nft_node_map[iter->second]);
            Dft_node *find_result = set_dfa->find(eps_closure);
            if(find_result){
                node->dfa_mapping[iter->first] = find_result->num;
            }else{
                Dft_node * new_node = new Dft_node();
                new_node->num = dft_node_count++;
                new_node->nfa_nums = eps_closure;
                Dft_Node_Edge_To_Mapping(new_node, nft_node_map);
                node->dfa_mapping[iter->first] = new_node->num;
                set_dfa->dfa_nodes.push_back(new_node);
                worklist.push(new_node);
            }
        }
    }
    return set_dfa;
}



