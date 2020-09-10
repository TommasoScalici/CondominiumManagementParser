typedef struct symbol
{
    char* name;
    char* email;
    char* fiscalcode;
    char* telephone;
    int unit;
    int millesimal;
    float amountToPay;
    struct symbol *next;
} symbol;

void addExpense(float);
void addSymbol(char*, char*, char*, char*, int, int);
void initialize();
void print();