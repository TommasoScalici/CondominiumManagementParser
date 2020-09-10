#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.tab.h"

FILE *output; 
float sum;
symbol *symbolTable;

void initialize()
{
    output = fopen("output.txt", "w+");
    sum = 0;
    symbolTable = NULL;
}

void addExpense(float amount)
{
    sum += amount;
}

void addSymbol(char *name, char* fiscalcode, char* email, char* telephone, int millesimal, int unit)
{
    symbol *temp = malloc(sizeof(symbol));

    temp->name = malloc(strlen(name) + 1);
    temp->email = malloc(strlen(email) + 1);
    temp->fiscalcode = malloc(strlen(fiscalcode) + 1);
    temp->telephone = malloc(strlen(telephone) + 1);

    strcpy(temp->name, name);
    strcpy(temp->email, email);
    strcpy(temp->fiscalcode, fiscalcode);
    strcpy(temp->telephone, telephone);

    temp->unit = unit;
    temp->millesimal = millesimal;
    temp->amountToPay = sum * millesimal / 1000;

    temp->next = symbolTable;
    symbolTable = temp;
}

void print()
{
    symbol *temp = symbolTable;

    while(temp != NULL)
    {
        fprintf(output, "%s: €%.2f\n", temp->name, temp->amountToPay);
        temp = temp->next;
    }

    fclose(output);
}