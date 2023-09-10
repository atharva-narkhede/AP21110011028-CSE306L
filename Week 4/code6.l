// Write LEX programs to check well formedness of the parenthesis. Make use of command line arguments.


%%
[(]     
[)]    
.       
%%


int main() 
{
    int open_paren = 0;
    int close_paren = 0;
    int c;

    while ((c = getchar()) != EOF) 
    {
        if (c == '(') 
        {
            open_paren++;
        } 
        else if (c == ')') 
        {
            close_paren++;
            if (close_paren > open_paren) 
            {
                printf("Parentheses are not well formed\n");
                return 1;
            }
        }
    }

    if (open_paren == close_paren) 
    {
        printf("Parentheses are well-formed.\n");
    } 
    else 
    {
        printf("Parentheses are not well formed\n");
    }
    return 0;
}
