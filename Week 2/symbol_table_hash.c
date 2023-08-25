//AP21110011028
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
 int x=0, n, i=0,j=0;
 void *ptr,*id_address[5];
 char ch,id_Array2[15],id_Array3[15],c;
 printf("Input the expression ending with ; sign:");
 char s[20];
 scanf("%s",s);
 while(s[i]!=';')
 {
  id_Array2[i]=s[i];
  i++;
 }
 n=i-1;
 
 printf("\n Symbol Table display\n");
 printf("Symbol \t addr \t\t\t type");
 while(j<=n)
 {
  c=id_Array2[j];
  if(isalpha(c))
  {
   ptr=malloc(c);
   id_address[x]=ptr;
   id_Array3[x]=c;
   printf("\n%c \t %p \t identifier\n",c,ptr);
   x++;
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='/' || ch=='%'|| ch=='='|| ch=='<' || ch=='>')
   {
    ptr=malloc(ch);
    id_address[x]=ptr;
    printf("\n %c \t %p \t operator\n",ch,ptr);
    x++;
    j++;
   }
	}
}
	return 0;
}
