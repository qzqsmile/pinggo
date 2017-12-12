// powerset construction alogrithm
#include<assert.h>
#include<queue>
#include<set>
#include"nfa.h"
#include"setcons.h"

using std::set;
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

Nfa_t* Set_Cons(Nfa_t* nfa)
{
    int set_code_count = 0;
    int accept = nfa->accept;
    Nfa_t* set_nfa = Nfa_new();
    Node_t* node0 = Nfa_lookupOrInsert(nfa, 0);
    Node_t* q0 = Nfa_lookupOrInsert(set_nfa, set_code_count++);

    set_nfa->start = set_nfa->accept = q0->num;
    q0->set_nodes = Eps_Closure(nfa, node0);
    queue<Node_t *> q_que;
    set<set<int> > all_set_nodes;
    all_set_nodes.insert(q0->set_nodes);
    //todo

    q_que.push(q0);
    
    while(!q_que.empty()){
        Node_t* iter_node = q_que.front();
        q_que.pop();
        for(set<int>::iterator iter = iter_node->set_nodes.begin(); iter != (iter_node->set_nodes).end(); iter++){
            Node_t* closure_node = Nfa_lookupOrInsert(nfa, *iter);
            Edge_t* edges = closure_node->edges;
            while(edges){
                if(edges->c != -2){
                    set<int>next_set = Eps_Closure(nfa, edges->to);
                    if(all_set_nodes.find(next_set) == all_set_nodes.end()){
                        Node_t *next_node = Nfa_lookupOrInsert(set_nfa, set_code_count++);
                        next_node->set_nodes = next_set;
                        Nfa_addEdge(set_nfa, iter_node->num, next_node->num, edges->c);
                        if((next_node->set_nodes).find(accept)!=(next_node->set_nodes).end())
                            set_nfa->accepts.push_back(next_node->num);
                        all_set_nodes.insert(next_set);
                        q_que.push(next_node);
                    }                    
                }
                edges = edges->next;
            }
        }   
    }
    return set_nfa;
}



