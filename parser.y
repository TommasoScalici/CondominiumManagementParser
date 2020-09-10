%{
        #include <stdio.h>
        #include <string.h>
        #include "symbol.tab.h"

        extern int yylex();
        extern void yyerror (char const *);
%}

%define parse.error verbose

%union {
        char* string;
}

%union {
        float float_t;
        int int_t;
}

%token <float_t>        NUM_REAL
%token <int_t>          MILLESIMAL UNIT
%token <string>         DATE EXPENSE NAME EMAIL FISCALCODE TELEPHONE
%token                  DASH SEPARATOR_1 SEPARATOR_2

%start  Start

%%

Start                   : section1 SEPARATOR_1 section2 SEPARATOR_2 section3
                        ;

section1                : DATE
                        ;

section2                : section2 EXPENSE NUM_REAL { addExpense($3); }
                        |
                        ;

section3                : section3 NAME DASH FISCALCODE DASH EMAIL DASH
                                   TELEPHONE DASH MILLESIMAL DASH UNIT
                                   {
                                           addSymbol($2, $4, $6, $8, $10, $12);
                                   }
                        |
                        ;

%%

void yyerror (char const *s) { 
        fprintf(stderr, "Error: %s\n", s);
}