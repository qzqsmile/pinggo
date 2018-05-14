#include"hopcroft.h"
#include"nfa.h"
#include"dfa.h"
#include<map>
#include<algorithm>

Hopcrof_set* Build_Hopcrof_set(Dfa_t *dfa_t){
    map<int, int> num_to_hopcrof_set;
    map<int, set<int> > set_include_nums;
    set<int> not_accept_nodes;
    map<int, Dfa_node *> num_to_dfa_nodes;
    Hopcrof_set * new_hopcrof_set = new Hopcrof_set();
    int hopcorf_set_num = 0;

    for(vector<Dfa_node *>::iterator iter = dfa_t->dfa_nodes.begin(); iter != (dfa_t->dfa_nodes).end(); iter++){
        if(dfa_t->accepts.find((*iter)->num) == dfa_t->accepts.end()){
            not_accept_nodes.insert((*iter)->num);
        }
        num_to_dfa_nodes[(*iter)->num] = *iter;
    }
    set_include_nums[hopcorf_set_num++] = dfa_t->accepts;
    set_include_nums[hopcorf_set_num++] = not_accept_nodes;
    Update_Dfa_Node_HopCroft_Set(num_to_hopcrof_set,set_include_nums);

    int last_set_num = 0;
    while(last_set_num != set_include_nums.size()){
        last_set_num = set_include_nums.size();
        
        for(map<int, set<int> >::iterator iter = set_include_nums.begin(); iter != set_include_nums.end(); iter++){
            set<int> accept_chars;
            Hopcrof_Node_Accept_Char(iter->second, num_to_dfa_nodes, accept_chars);

            for(set<int>::iterator accept_chars_iter = accept_chars.begin(); accept_chars_iter != accept_chars.end(); accept_chars_iter++){
                map<int, set<int> > split_sets;
                for(set<int>::iterator dfa_iter = iter->second.begin(); dfa_iter != iter->second.end(); dfa_iter++){
                    if(num_to_dfa_nodes[*dfa_iter]->dfa_mapping.find(*accept_chars_iter) != num_to_dfa_nodes[*dfa_iter]->dfa_mapping.end()){
                        split_sets[num_to_hopcrof_set[num_to_dfa_nodes[*dfa_iter]->dfa_mapping[*accept_chars_iter]]].insert(*dfa_iter);
                    }else{
                        split_sets[num_to_hopcrof_set[*dfa_iter]].insert(*dfa_iter);
                    }
                }
                if(split_sets.size() > 1){
                    set_include_nums.erase(iter->first);
                    for(map<int, set<int> >::iterator split_iter = split_sets.begin(); split_iter != split_sets.end(); split_iter++){
                        set_include_nums[hopcorf_set_num++] = split_iter->second;
                    }
                    Update_Dfa_Node_HopCroft_Set(num_to_hopcrof_set, set_include_nums);
                    split_sets.clear();
                    break;
                }
            }
        }
    }
    
    vector<int> accept_nodes;
    int start_node = -1;
    for(map<int, set<int> >::iterator iter = set_include_nums.begin(); iter != set_include_nums.end(); iter++){
        Hopcrof_Node * new_hopcrof_node = new Hopcrof_Node();
        new_hopcrof_node->num = iter->first;
        bool first_find_accept_flag = false;
        for(set<int>::iterator set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++){
            new_hopcrof_node->dfa_nodes.insert(num_to_dfa_nodes[*set_iter]);
            if((!first_find_accept_flag) && (dfa_t->accepts.find(*set_iter) != dfa_t->accepts.end())){
                first_find_accept_flag = true;
                accept_nodes.push_back(iter->first);
            }
            if(dfa_t->start == (*set_iter)){
                start_node = iter->first;
            }
        }
        for(set<Dfa_node *>::iterator hopcroft_dfa_node_iter = new_hopcrof_node->dfa_nodes.begin(); 
                hopcroft_dfa_node_iter != new_hopcrof_node->dfa_nodes.end(); hopcroft_dfa_node_iter++){
                    for(map<int, int>::iterator dfa_edge_iter = (*hopcroft_dfa_node_iter)->dfa_mapping.begin(); dfa_edge_iter != (*hopcroft_dfa_node_iter)->dfa_mapping.end(); dfa_edge_iter++){
                        if((iter->first) != num_to_hopcrof_set[dfa_edge_iter->second]){
                            new_hopcrof_node->edges[dfa_edge_iter->first] = num_to_hopcrof_set[dfa_edge_iter->second];
                        }
                    }
        }
        new_hopcrof_set->hopcrof_nodes.push_back(new_hopcrof_node);
    }
    new_hopcrof_set->accepts = accept_nodes;
    new_hopcrof_set->start = start_node;
    //to do
    //build edges and set accept and start point

    return new_hopcrof_set;
}

void Update_Dfa_Node_HopCroft_Set(map<int, int>& num_to_hopcrof_set, map<int, set<int> >& set_include_nums){
    for(map<int, set<int> >:: iterator iter = set_include_nums.begin(); iter != set_include_nums.end(); iter++){
        for(set<int>::iterator set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++){
            num_to_hopcrof_set[*set_iter] = iter->first;
        }
    }
}

void Hopcrof_Node_Accept_Char(set<int>& dfa_nodes, map<int, Dfa_node* >& num_to_dfa_nodes, set<int>& accept_chars){
    for(set<int>::iterator iter = dfa_nodes.begin(); iter != dfa_nodes.end(); iter++){
        for(map<int, int>::iterator dfa_node_iter = num_to_dfa_nodes[*iter]->dfa_mapping.begin(); 
            dfa_node_iter != num_to_dfa_nodes[*iter]->dfa_mapping.end(); dfa_node_iter++){
                accept_chars.insert(dfa_node_iter->first);
        }
    }
}

