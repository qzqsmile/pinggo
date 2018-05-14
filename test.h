#ifndef TEST_H
#define TEST_H

#include"nfa.h"
#include"dfa.h"
#include"hopcroft.h"

void TestClosure(Nfa_t* nfa, int num);
void Set_Dfa_print(Dfa_t* nfa);
void HopCrof_Set_print(Hopcrof_set * hopcrof_set);

#endif