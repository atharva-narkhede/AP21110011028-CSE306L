// Identification of Vowels and Consonants

%%
[aeiouAEIOU] 	{ printf("%s is vowel\n",yytext); }
[a-zA-Z] 	{printf("%s is consonant\n",yytext);}
. 		{printf("%s is invalid lexeme\n",yytext);}
%%


int main()
{
  yylex();
}
int yywrap()
{
  return 1;
}
