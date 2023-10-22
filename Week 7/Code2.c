#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;
char stack[20];
char ip[20];

void push(char c) {
    stack[i++] = c;
}

void pop() {
    i--;
}

void error() {
    printf("\n\nSyntax Error!!!! String is invalid\n");
    exit(0);
}

int main() {
    int n;

    printf("The given grammar is\n\n");
    printf("E  -> TE'\n");
    printf("E' -> +TE' | epsilon\n");
    printf("T  -> FT'\n");
    printf("T' -> *FT' | epsilon\n");
    printf("F  -> (E) | d\n\n");

    printf("Enter the string to be parsed:\n");
    scanf("%s", ip);
    n = strlen(ip);
    ip[n] = '$';
    ip[n + 1] = '\0';

    push('$');
    push('E');

    while (1) {
        if (ip[i] == '$' && stack[i] == '$') {
            printf("\n\nSuccessful parsing of string\n");
            break;
        } else if (ip[i] == stack[i]) {
            printf("\nMatch of %c occurred ", ip[i]);
            i++;
            pop();
        } else {
            switch (stack[i]) {
                case 'E':
                    if (ip[i] == 'd' || ip[i] == '(') {
                        printf("\nE -> TE'");
                        pop();
                        push('E');
                        push('\'');
                        push('T');
                    } else {
                        error();
                    }
                    break;

                case 'E' - 1:
                    if (ip[i] == '+') {
                        printf("\nE' -> +TE'");
                        pop();
                        push('E');
                        push('\'');
                        push('T');
                        push('+');
                    } else if (ip[i] == ')' || ip[i] == '$') {
                        printf("\nE' -> epsilon");
                        pop();
                    } else {
                        error();
                    }
                    break;

                case 'T':
                    if (ip[i] == 'd' || ip[i] == '(') {
                        printf("\nT -> FT'");
                        pop();
                        push('T');
                        push('\'');
                        push('F');
                    } else {
                        error();
                    }
                    break;

                case 'T' - 1:
                    if (ip[i] == '*') {
                        printf("\nT' -> *FT'");
                        pop();
                        push('T');
                        push('\'');
                        push('F');
                        push('*');
                    } else if (ip[i] == '+' || ip[i] == ')' || ip[i] == '$') {
                        printf("\nT' -> epsilon");
                        pop();
                    } else {
                        error();
                    }
                    break;

                case 'F':
                    if (ip[i] == 'd') {
                        printf("\nF -> d");
                        pop();
                        push('d');
                    } else if (ip[i] == '(') {
                        printf("\nF -> (E)");
                        pop();
                        push(')');
                        push('E');
                        push('(');
                    } else {
                        error();
                    }
                    break;

                default:
                    error();
            }
        }
    }
    return 0;
}
