%{
#include <stdio.h>
#include <stdlib.h>
%}

%token d
%token EOL

%%

S : E EOL    { printf("Valid expression\nResult is %d\n",$1); exit(0); }
  ;

E : E '+' T    {$$ = $1 + $3; }
  | T          {$$=$1 ;}
  ;

T : T '*' F    { $$ = $1 * $3; }
  | F          {$$=$1;}
  ;

F : '(' E ')'   { $$=( $2 ); }
  | d          { $$=$1 ; }
  ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}
