
void Open_existaccount(tNode **Head);
void Make_Transaction(tNode **Head);
void Chg_Pass(tNode **Head);
void Get_Cash(tNode **Head);
void Deposit_account(tNode **head);
void PrintList();
tNode* CheckUser( long long ID );

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
