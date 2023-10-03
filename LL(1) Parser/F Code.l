%{
    #include <stdio.h>
    FILE *tokenStore;
    int Totalcount_if = 0;
    int Totalcount_else = 0;
    int Totalcount_switch = 0;
    int Totalcount_case = 0;
    int Totalcount_break = 0;
    int Totalcount_int = 0;
    int Totalcount_deci = 0;
    int Totalcount_string = 0;
    int Totalcount_void = 0;
    int Totalcount_for = 0;
    int Totalcount_while = 0;
    int Totalcount_do = 0;
    int Totalcount_return = 0;
    int Totalcount_cin = 0;
    int Totalcount_cout = 0;
    int tokens=0;

%}

%%

"include <iostream>" { fprintf(tokenStore,"Expression \t\t Tokens \n\n"); }
[i][f]              { fprintf(tokenStore,"if \t\t if_Condition\n",yytext);Totalcount_if++; tokens++;}
[i][n][t]           { fprintf(tokenStore,"int \t\t int_DataType\n",yytext); Totalcount_int++; tokens++;}
[e][l][s][e]        { fprintf(tokenStore,"else \t\t else_Condition\n",yytext); Totalcount_else++; tokens++;}
[c][a][s][e]        { fprintf(tokenStore,"case \t\t case_Condition\n",yytext); Totalcount_case++; tokens++;}
[c][i][n]           { fprintf(tokenStore,"cin \t\t get_Data\n",yytext); Totalcount_cin++; tokens++;}
[c][o][u][t]        { fprintf(tokenStore,"cout \t\t print_Data\n",yytext); Totalcount_cout++; tokens++;} 
[s][w][i][t][c][h]  { fprintf(tokenStore,"switch \t\t switch_Case\n",yytext); Totalcount_switch++ ; tokens++;}
[s][t][r][i][n][g]  { fprintf(tokenStore,"string \t\t string_DataType\n",yytext); Totalcount_string++; tokens++;}
[b][r][e][a][k]     { fprintf(tokenStore,"break \t\t Stop_Condition\n",yytext); Totalcount_break++ ; tokens++;}
[d][e][c][i]        { fprintf(tokenStore,"deci \t\t deci_DataType\n",yytext);Totalcount_deci++ ; tokens++;}
[f][o][r]           { fprintf(tokenStore,"for \t\t for_Loop\n",yytext); Totalcount_for++; tokens++;}
[v][o][i][d]        { fprintf(tokenStore,"void \t\t void_Func\n",yytext); Totalcount_void++; tokens++;}
[w][h]              { fprintf(tokenStore,"while \t\t while_Condition\n",yytext); Totalcount_while++; tokens++;}
[d][o]              { fprintf(tokenStore,"do \t\t do_Loop\n",yytext); Totalcount_do++; tokens++;}
[r][e][t]           { fprintf(tokenStore,"return \t\t return_kword\n",yytext); Totalcount_return++; tokens++;}
[A-Z]
[a-z]
.
\n
"finish"  {
        fprintf(tokenStore,"\nTotal Tokens\n\n");

        if  (Totalcount_if > 0 ) fprintf(tokenStore,"Total if = %d \n",  Totalcount_if,yytext );
        if ( Totalcount_else > 0 ) fprintf(tokenStore,"Total else = %d \n", Totalcount_else,yytext );
        if ( Totalcount_switch > 0 ) fprintf(tokenStore,"Total switch = %d \n", Totalcount_switch,yytext );
        if ( Totalcount_case > 0 ) fprintf(tokenStore,"Total case = %d \n", Totalcount_case,yytext );
        if ( Totalcount_break > 0 ) fprintf(tokenStore,"Total break = %d \n", Totalcount_break,yytext );
        if ( Totalcount_int > 0 ) fprintf(tokenStore,"Total int = %d \n", Totalcount_int,yytext );
        if ( Totalcount_deci > 0 ) fprintf(tokenStore,"Total deci = %d \n",  Totalcount_deci,yytext );
        if ( Totalcount_string > 0 ) fprintf(tokenStore,"Total string = %d \n",  Totalcount_string,yytext);
        if ( Totalcount_void > 0 ) fprintf(tokenStore,"Total void = %d \n", Totalcount_void,yytext );
        if ( Totalcount_for > 0 ) fprintf(tokenStore,"Total for = %d \n", Totalcount_for,yytext );
        if ( Totalcount_while > 0 ) fprintf(tokenStore,"Total while = %d \n",  Totalcount_while,yytext  );
        if ( Totalcount_do > 0 ) fprintf(tokenStore,"Total do = %d \n", Totalcount_do,yytext );
        if ( Totalcount_return > 0 ) fprintf(tokenStore,"Total return = %d \n", Totalcount_return,yytext );
        if ( Totalcount_cin > 0 ) fprintf(tokenStore,"Total cin = %d \n", Totalcount_cin,yytext );
        if ( Totalcount_cout > 0 ) fprintf(tokenStore,"Total cout = %d \n", Totalcount_cout,yytext );

        fprintf(tokenStore,"Total Tokens: %d",tokens);

}
         
%%

int yywrap(){
     fclose(tokenStore);
    return 1;
}

int main(int argc, char** argv) 
{
  if (argc < 2) 
  {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  FILE* fileptr = fopen(argv[1], "r");
  if (fileptr == NULL) 
  {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  } 

  yyin = fileptr;
  tokenStore = fopen("tokenDataFlex.txt", "w");    
  yylex(); 


  fclose(tokenStore);
  fclose(fileptr);

  return 0;
    

}
