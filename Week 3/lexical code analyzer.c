#include<stdio.h>
#include<string.h>
#include<ctype.h>
char symtable[50][10];
char keyword[30][30]={"int","while","break","for","do","if","float","char","switch","double","short","long",
"unsigned","sizeof","else","register","extern","static","auto","case","break","volatile","enum","typedef"};
bool check_keyword(char id[]){ 
	int i;
	for(i=0;i<24;i++)
	if(strcmp(id,keyword[i])==0)
	  return 1;
	return 0;
}
void symbol_table(char id[],int n){
	int flag=0;
	char c1[10];
	strcpy(c1,id);
	for(int j=0;j<n;j++){
		if(strcmp(c1,symtable[j])==0){
	     flag=1;
	 }
	}
     char *p[50];
	if(flag==0){
	for(int i=0;i<=10;i++){
    symtable[n][i]=id[i];
}
    
    
    printf("%s\t%p\n",symtable[n],&symtable[n]); 
}
}
int main(){
	
    char id[20], num[10],rop[10],spcf[12];
    int state =1;
 
 
    FILE *f1,*f2;
 
    f1=fopen("Lexical Analyzer File.txt","r");
    f2=fopen("new_file","w");
    char c;
    int j=0;
    int i,l;
    int n=0;
    int k=0;
    printf("Identifiers\t Address\n");
    while((c=fgetc(f1))!=EOF){
 
    switch(state){
 	case 1:
 		    i=0;
 		   if(isalpha(c)){
 		   	state=2;
 		   	id[i]=c;
 		   	i++;
			}
			else if(isdigit(c)){
				state=3;
				num[j++]=c;
			}
			else if(c=='!'||c=='='||c=='<'||c=='>'){
				state=4;
				rop[k++]=c;
				
			}
		
			else if(c=='/'){
				state=5;
				
			}
			else if(c==' ' || c=='\t'|| c=='\n'){
				state=1;
			}
			else if(c=='('||c==')'||c==','||c=='{'||c=='}'||c==';'||c=='"'){
				state=1;
			    fprintf(f2,"delimiter:\t%c\n",c);
			    
			}
			else if(c=='%'||c=='+'||c=='-'|| c=='*'||c=='&'){
				state=8;
				spcf[l++]=c;
			}
			else{
			fprintf(f2,"%c\t\n",c);
			}
			break;
	case 2:
		  if(isalnum(c)){	
		  	state=2;
		  	id[i++]=c;
		  	
		  }
		  else{
		  	   id[i]='\0';
		  	   if(check_keyword(id))
		  	   fprintf(f2,"keyword:\t%s\n",id);
				else{
				
					fprintf(f2,"identifier:\t%s\n",id);
					n++;
					symbol_table(id,n);
				}
			    state=1;
				i=0;
				ungetc(c,f1);
					
		  }
		  break;
    case 3:
    	if(isdigit(c)||c=='.'){
    		state=3;
    		num[j++]=c;
		}
		else{
			num[j]='\0';
			fprintf(f2,"number:\t%s\n",num);
			state=1;
			j=0;
			ungetc(c,f1);
		
		}
		break;
	case 4:
		if(c=='='){
			rop[k++]=c;
			rop[k]='\0';
			fprintf(f2,"relational_operator:\t%s\n",rop);
			state=1;
			k=0;
		  ungetc(c,f1);
	
		}
		else{
			rop[k]='\0';
			
			fprintf(f2,"relational_operator:\t%s\n",rop);
			k=0;
			state=1;
			ungetc(c,f1);
		}
		break;
  	case 5:
	  if(c=='*')
        state=6;
      else
          fprintf(f2,"\n invalid lexeme");
    break;
    case 6: 
	     if(c=='*')
           state=7;
         else
            state=6;
    break;
    
    case 7:
      if(c=='*')
        state=7;
      else if(c=='/')
        state=1;
      else
        state=6;
    break;
    
    case 8:
    	if(c=='d'||c=='f'){
    		spcf[l++]=c;
    		fprintf(f2,"format specifier:\t%s\n",spcf);
    	
    		l=0;
    		state=1;
		}
		else{
			spcf[l]='\0';
			fprintf(f2,"operator:\t%s\n",spcf);
			ungetc(c,f1);
			state=1;
			l=0;
		}
		
 }
 }
 if(state==6) fprintf(f2,"comment did not close");
 fclose(f1);
 fclose(f2);
 return 0;
}
