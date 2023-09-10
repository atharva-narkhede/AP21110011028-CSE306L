// Recognize a string with three consecutive 0’s

%%
[0-9]000[0-9] { printf("string accepted");}
[0-9]* { printf("string rejected");}
%%


int main()
{
  yylex();
}
int yywrap()
{
  return 1;
}
