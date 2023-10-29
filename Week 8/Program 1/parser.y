%{
#include&lt;stdio.h&gt;
%}

%token DIGIT
%left &#39;-&#39; &#39;+&#39;
%left &#39;*&#39; &#39;/&#39;
%nonassoc UMINUS
%%
S: E { printf(&quot;The result is =%d\n&quot;,$1);}
;
E: E'+'E  { $$ = $1 + $3; }
| E'-'E { $$ = $1 - $3; }
| E'*'E { $$ = $1 * $3; }
| E'/'E { if($3 == 0)
              yyerror(&quot;Divide by zero&quot;);
          else
              $$ = $1 / $3; }
| '-'E %prec UMINUS { $$ = -$2; }
| '(' E ')'; { $$ = $2; }
| DIGIT {$$ = $1;}
;
%%

int main()
{
  yyparse();
}
int yywrap()
{
  return 1;
}
void yyerror(char *s)
{
  printf(&quot;Error %s&quot;,s);exit(0);
}
