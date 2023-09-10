// Count number of vowels and consonants


%{
int vowel_count = 0;
int consonant_count = 0;
%}

%%
[aAeEiIoOuU] { vowel_count++; }
[A-Za-z]      { consonant_count++; }
.             { /* Ignore all other characters */ }
%%

int main() 
{
    yylex();
    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);
    return 0;
}
