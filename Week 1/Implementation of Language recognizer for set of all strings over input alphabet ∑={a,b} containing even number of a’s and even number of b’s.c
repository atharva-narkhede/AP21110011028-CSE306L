//Implementation of Language recognizer for set of all strings over input alphabet ∑={a,b} containing even number of a’s and even number of b’s.
//WEEK 1 Q1
#include<stdio.h>
void main()
{
    int state=0,i,n;
    printf("Enter the length of the String: ");
    scanf("%d",&n);
    char inp[n];
    printf("Enter the String: ");
    scanf("%s",inp);
    for(i=0;inp[i]!='\0';i++)
    {
        switch(state)
        {
            case 0:
                if(inp[i]=='a')
                    state=1;
                else if(inp[i]=='b')
                    state=3;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 1:
                if(inp[i]=='a')
                    state=0;
                else if(inp[i]=='b')
                    state=2;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 2:
                if(inp[i]=='a')
                    state=3;
                else if(inp[i]=='b')
                    state=1;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 3:
                if(inp[i]=='a')
                    state=2;
                else if(inp[i]=='b')
                    state=0;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
        }
    }
    if(state==0)
        printf("String is ACCEPTED\n");
    else
        printf("String is NOT ACCEPTED\n");
    return 0;
}
