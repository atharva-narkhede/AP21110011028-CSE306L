digit	[0-9]*
id	[a-zA-Z][a-zA-Z0-9]*
num	[0-9]\.[0-9]


%{
#include<stdio.h> 
#include<string.h>
int cnt=0,i=0,j=0; 
char st[10][10];
int n=0,com=0,scom=0; 
FILE *ifp,*ofp;
int lookup(char st[10][10],char *id,int n);
%}
 
 
%%
\n	{scom=0;n++;}
"//"	{scom=1;fprintf(yyout,"\n Single line comment..");} 
"/*"	{com=1;fprintf(yyout,"\n Multi line comment starts..");}
"*/"	{com=0;fprintf(yyout,"\n Multi line comment ends..");} 
int | float | char | double |  void  | 
main	{if(!com&&!scom) fprintf(yyout," \n %s is keyword",yytext);}
"<="	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Lessthan or Equal to operator",yytext);} 
"<"	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Lessthan operator",yytext);}
">="	{if(!com) fprintf(yyout,"\n %s is Relational operator Greaterthan or Equal to operator",yytext);} 
">"	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Greaterthan operator",yytext);} 
"=="	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Equal to operator",yytext);}
"!="	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Not Equal to operator" ,yytext);}
"="	{fprintf(yyout,"\n %s is Assignment operator",yytext);}
{id}	{
	  if (!com && !scom) 
	  {
    		fprintf(yyout, "\n %s is identifier", yytext);
    		if (!lookup(st, yytext, i)) 
    		{
        		strcpy(st[i++], yytext);
        		cnt++;
    		}
	   }
        }
{num}   {if(!com&&!scom) fprintf(yyout,"\n %s is float",yytext);}
{digit}   {if (!com&&!scom) fprintf(yyout,"\n %s is digit",yytext);}
.
%%

 
int main(int argc, char **argv)
{
	yyin =fopen(argv[1],"r");  
        yyout=fopen("y.txt","w");
	yylex();
	printf(" No of id are : %d ",cnt);
	printf("\nThe contents of symbol table are :\n"); 
	for(j=0;j<i;j++)
            printf("\n %s",st[j]);
	printf(" \nNo of lines is %d\n\n",n); 
	return 0;
}
 
int yywrap()
{
	return 1;
}


int lookup(char st[10][10],char *id,int n)
{
	for(j=0;j<n;j++) 
	     if(!strcmp(st[j],id)) 
	          return 1;
	return 0;
}
