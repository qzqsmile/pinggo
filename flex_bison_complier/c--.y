%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

  int yylex();
  void yyerror (char *);

  // the AST:
  Prog_t tree;

  %}

%union{
  int intval;
  string strval;
  Type_t typeval;
  Dec_t decval;
  List_t decsval;
  Exp_t expval;
  Stm_t stmval;
  List_t stmsval;
  Prog_t progval;
  VAR_ID_t varval;
 }

// terminals
%token <intval> INTNUM
%token <strval> ID
%token AND BOOL FALSE INT OR TRUE LONG IF RETURN FOR
%token PRINTB PRINTI MAIN

// nonterminals
%type <progval> prog
// %type <decval> dec
%type <decsval> decs one_line_decs
%type <stmval> stm
%type <stmsval> stms ids
%type <expval> exp
%type <typeval> type
%type <varval> aloneid

%left AND OR
%left '+' '-'
%left '*' '/'

%start prog

%%

prog: '{' decs stms '}' {tree = Prog_new ($2, $3); return 0;}
;

decs: one_line_decs decs  {$$ = Con_List($1, $2);}
|               {$$ = 0;}
;

one_line_decs: type ids   {$$ = OneLine_VAR_new ($1, $2);}
;

aloneid: ID       {$$ = VAR_ID_new($1, -1);}
    | ID '[' INTNUM ']' {$$ = VAR_ID_new($1, $3);}
;

ids: aloneid      {$$ = List_new($1, 0);}
| ids ',' aloneid {$$ = List_new($3, $1);}
; 

type: BOOL       {$$ = TYPE_BOOL;}
| INT            {$$ = TYPE_INT;}
| LONG           {$$ = TYPE_LONG;}
;

stms: stm stms {$$ = List_new ($1, $2);}
|              {$$ = 0;}
;

stm: ID '=' exp ';'      {$$ = Stm_Assign_new ($1, $3);}
| PRINTI '(' exp ')' ';' {$$ = Stm_Printi_new ($3);}
| PRINTB '(' exp ')' ';' {$$ = Stm_Printb_new ($3);}
;

exp: INTNUM    {$$ = Exp_Int_new ($1);} 
| TRUE         {$$ = Exp_True_new ();}
| FALSE        {$$ = Exp_False_new ();}
| ID           {$$ = Exp_Id_new ($1);}
| exp '+' exp  {$$ = Exp_Add_new ($1, $3);}
| exp '-' exp  {$$ = Exp_Sub_new ($1, $3);}
| exp '*' exp  {$$ = Exp_Times_new ($1, $3);}
| exp '/' exp  {$$ = Exp_Divide_new ($1, $3);}
| exp AND exp  {$$ = Exp_And_new ($1, $3);}
| exp OR exp   {$$ = Exp_Or_new ($1, $3);}
| '(' exp ')'  {$$ = $2;}
;


%%

void yyerror (char *s)
{
  fprintf (stderr, "%s\n", s);
  return;
}

