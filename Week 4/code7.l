// Write LEX program to add line number before each line in a file.


%{
int line_number = 1; 
%}

line .*\n	

%%
{line} { printf("%10d %s", line_number++, yytext); }
%%

int yywrap(){}

int main(int argc, char*argv[])
{
  extern FILE *yyin; 
  yyin = fopen("flexd.txt","r"); 
  yylex(); 
  return 0;
}
