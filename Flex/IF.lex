 /* scanner for key word IF
 run command:
        flex IF.lex
        gcc lex.yy.c -lfl

        input:
        ifx if iif       if  234
        iff     if
        output:
        ID(ifx) (1, 1)
        IF        (1, 4)
        ID(iif)  (1, 8)
        IF       (1, 13)
        NUM(234) (1, 16)
        ID(iff) (2, 1)
        IF       (2, 8)
  */

%{
/* need this for the call to atof() below */
#include <math.h>
#include <string.h>
int num_line = 1, num_chars = 1;
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

\n          {
                ++num_line;
                num_chars = 1;
            }

{DIGIT}+    {
            printf( "An integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }

{DIGIT}+"."{DIGIT}*        {
            printf( "A float: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

if          {
            printf( "IF  (%d, %d)\n", num_line, num_chars );
            num_chars += strlen(yytext);
            }

{ID}        {
                printf( "ID(%s) (%d, %d)", yytext, num_line, num_chars);
                num_chars += strlen(yytext);
            }

"+"|"-"|"*"|"/"   printf( "An operator: %s\n", yytext );

"{"[\^{}}\n]*"}"     /* eat up one-line comments */

.           num_chars++;

%%

int main( int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}
