// powerset construction alogrithm
#include<assert.h>
#include<queue>
#include<set>
#include"nfa.h"
#include"setcons.h"

using std::set;
using std::queue;

set<Node_t*> Eps_Closure(Nfa_t* nfa, Node_t *e)
{
    set<Node_t*> closure;
    queue<Node_t*> worklist;
    
    closure.insert(e);
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
                        closure.insert(edges->to);
                   }
                   edges = edges->next;
               }
            }
            nodes = nodes->next;
        }
    }
    return closure;
}