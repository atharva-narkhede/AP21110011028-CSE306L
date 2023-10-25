%{
#include "y.tab.h"
%}

%%
[0-9]+          { yylval = atoi(yytext); return d; }
[+*/()]         { return *yytext; }
\n              { return EOL; }
[ \t]           ; 
.               { yyerror("Invalid character"); }
\n               return 0;
.return yytext[0];
%%

int yywrap() {
    return 1;
}
