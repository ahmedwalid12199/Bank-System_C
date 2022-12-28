
void Open_existaccount(,);
void Make_Transaction(,);
void Chg_Pass(,);
void Get_Cash(,);
void Deposit_account(,);

typedef struct NODE {
    char Name[60];
    char Address[60];
    char Guardian[60];
    char AccountStatus[10];
    //Generated Automatically
    char Password[9];
    char BankAccountID[20];
    int National_ID;
    int GuardianNationalID;
    unsigned int Age;
    unsigned int Balance;
    
    
    struct Node *pnext;

}tNode;
