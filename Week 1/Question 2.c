// Implementation of Language recognizer for set of all strings ending with two symbols of same type.
//WEEK 1 Q2

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
                    state=2;
                else if(inp[i]=='b')
                    state=3;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 2:
                if(inp[i]=='a')
                    state=2;
                else if(inp[i]=='b')
                    state=3;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 3:
                if(inp[i]=='a')
                    state=1;
                else if(inp[i]=='b')
                    state=4;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
            case 4:
                if(inp[i]=='a')
                    state=1;
                else if(inp[i]=='b')
                    state=4;
                else
                {
                    printf("Not Valid !!!");
                    exit(0);
                }
                break;
        }
    }
    if(state==2 || state==4)
        printf("String is ACCEPTED\n");
    else
        printf("String is NOT ACCEPTED\n");
    return 0;
}
