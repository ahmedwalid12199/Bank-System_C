 #define N 5
 #define J 8

 tNode*Head=NULL;


void CreateNewAcc(tNode **Head )
{
    char *GenBank_ID;
    char *Gen_Password;

    tNode *TempNode = NULL ;
    tNode *LastNode = NULL ;

    TempNode = (tNode *)malloc(sizeof(tNode)); //created a node

    if (NULL != TempNode)
    {
        // ^Getting info from the user and save it^
        TempNode->NodeLink = NULL ;
        /**
         *  Generate Pass and ID 
         * 
        */
        GenBank_ID= Gen_ID();
        Gen_Password= Gen_Pass();
        
        // *TempNode->State = "active";
        strcpy(TempNode->State, "active");
        strcpy(TempNode->ID, Gen_ID);
        strcpy(TempNode->Pass, Gen_Pass);
        printf("Enter Your Name    : ");
        gets(TempNode->Name);
        printf("Enter Your Address : ");
        gets(TempNode->Addr);
        printf("Enter Your Age     : ");
        scanf("%u" , &TempNode->Age);

        if (21 > TempNode->Age)
        {
            printf("You have to enter the National ID of your Guardian ! \n");
            printf("==================================================== \n\n");

            printf("Enter National ID : ");
            scanf("%i" , &TempNode->G_ID);
        }
        else
        {
            printf("Enter National ID : ");
            scanf("%i" , &TempNode->ID);            
        }
        printf("Enter Your Balance   : ");
        scanf("%i" , &TempNode->Balance);

        // ^Check if there is other users in DataBase or this is first user^
        /* DataBase is Empty */
        if (NULL == *Head)
        {
            Head = TempNode ;       // Head of DataBaase points to this user data as it is first user */
        }
        /* DataBase is not Empty */
        else
        {
            LastNode = Head ;       // save Head of DataBase into another variable to make itration on it */

            while (NULL != LastNode->pnext)
            {
                /* check if NodeLink Points to Null --> to find the last item in DataBase */
                LastNode = LastNode->pnext ;
            }
            LastNode->pnext = TempNode ;
        }
    }
    else
    {
        /* 
         *Do Nothing 
         */
    }
}

void main(void)
{
    int x;
    printf("For Clinet mode Press 1:");
    printf("For Admin mode Press 2:");
    printf("Exit Press 3");
    scanf("%d",&x);
    switch(x)
    {
        case 1: {  //Admin mode
            while(1)
            {
                printf("****************Welcome to Admin mode**************");
                int choice1;
                printf("Create New account Press 1:\n");
                printf("Open existing account Press 2:");
                printf("Exit system Press 3:");
                scanf("%d",&choice1); //then here the admin select the choice & do the functions

                if ( choice1==1)
                {
                     CreateNewAcc( &Head);
                

                }
                else if(choice1==2)
                {
                    Open_existaccount(&Head);
                
                }
                else if(choice ==3)
                {
                    break;
                }
                else
                {
                    print("Please enter valid input and try again");
                }

                



            }
        }

        case 2: { //Client mode

            printf("please enter password");
            scanf
            printf
            scanf
            while(1)
            {
                printf("********************Welcome to Client mode***********************");
                int choice;
                int op,np,cash;
                printf("Make Transaction Press 1:");
                printf("Change Password Press 2:");
                printf("Get Cash Press 3:");
                printf("Deposit in account Press 4");
                printf("Return to main menu Press 5");
                scanf("%d",&choice);
                
                if ( choice ==1) //Transaction
                {
                    Make_Transaction(&Head);
                    break;
                }
                else if (choice ==2) //change password
                {
                   Chg_Pass(&Head);  

                }
                else if (choice ==3)
                {

                    Get_Cash(&Head);
                }
                else if(choice ==4)
                {
                    Deposit_account(&Head);
                }
                
                else if( choice ==5) //Exit
                {
                    break;
                }
                else
                {
                    printf("Invalid input please try again");

                }


            }    
        


        }
        case 3: { // Exit mode
                break;
        }
    }


    
}



void Open_existaccount(tNode **head)
{
    int y;
	//PrintList();
	long long AccountId;
	
	start:
	printf("Please Enter your Bank Account ID: ");
	scanf("%lld",&AccountId);
	
	tNode*current=Head; //point to first node 
	
	//check exist of ID
	current = CheckUser(AccountId); 
	int OpenChoice;	

	if ( current != NULL ) // LIST EXIST 
	{
		y=1;
			while (y){
				if (current->BankAccountId==AccountId){
					printf("\n****************************************************************\n");		
					printf("Make Transacation          Press 1\n");
					printf("Change Account Status      Press 2\n");
					printf("Get Cash                   Press 3\n");
					printf("Deposite in Account        Press 4\n");
					printf("Return to main menu        Press 5\n");
					
					printf("Enter your choice: ");
					scanf("%d",&OpenChoice); 
					printf("****************************************************************\n");	
					
						if (OpenChoice==1){ //Make Transacation 
							MakeTransaction( current );
							//PrintList(); //--> To show changes
						}
						
						else if (OpenChoice==2){ //Change Account Status 
							ChangeAccountStatus( current );
							//PrintList();
						 }
						
						
						 else if (OpenChoice==3){ //Get Cash
							GetCash ( current );
							//PrintList();
						 }
						
						 else if (OpenChoice==4){ //Deposite in Account 	
							Deposite ( current );
							//PrintList();
						 }
						
						 else if (OpenChoice==5){ //Return to main menu 
							y=0;
						 }
					}
					
				else{
				printf("Wrong ID, Make sure you have an account\n");
				goto start;
				}
		   }
		current=current->pnext;	
	}

}

void Make_Transaction(tnode **head)
{
   /* unsigned transCash;
    char MyID[20], TransID[20];
    printf("Please enter your Bank ID:");
    scanf("%s",MyID);
    printf("Please enter the ID you want to trasfer to:");
    scanf("%")
    printf("Please enter the amount of money you want to transfer");
    scanf("%u",&transCash);
    tempnode->Balance */

    char local_pBankAccountID[MAX_NO_Bank_AccountID_Generator];
	// Uint8_t* local_pu8AccountStatus;
	unsigned local_MoneyAmount;

	printf("\t\tHello there :)\n\n");
	printf("There are all IDS on our system \n");
	printf("------------------------------------------\n");
	display_BankAccountIDS(strNode);
	printf("------------------------------------------\n");
	printf("please enter Bank Account ID that you want to transfer money to >> ");
	scanf("%s", local_pBankAccountID);
	printf("please enter amount of money >> ");
	scanf("%u", &local_MoneyAmount);
	Is_BankAccountIDFound(strNode, local_pBankAccountID, local_MoneyAmount);
}

void Chg_Pass(tnode **head)
{
    char local_pMyBankID[15];
	char local_MyNewPassword[15];
	tNode* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pMyBankID);

	printf("What is your new password >> ");
	scanf("%s", local_MyNewPassword);
	local_strCurrntNode = CurrentNode(strNode, local_pMyBankID);

	strcpy(local_strCurrntNode->password, local_MyNewPassword);

}

void Get_Cash(tnode **head)
{
    unsigned local_u16CashNo;
	char local_u8Flag = 0;
	char local_pu8MyBankID[15];
	tNode* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be withdrawn >> ");
	scanf("%u", &local_u16CashNo);
	
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(local_strCurrntNode->balance >= local_u16CashNo)
		{
			local_strCurrntNode->balance -=  local_u16CashNo;
			printf("\nYou withdrawed : %u , and your Account balance : %u \n", local_u16CashNo, local_strCurrntNode->balance);
		}
		else if(local_strCurrntNode->balance < local_u16CashNo)
		{
			printf("you don't have enough money\n");
		}
		else 
		{
			/* do nothing */
		}
	}

}

void Deposit_account(tnode **head)
{
    unsigned local_u16DepNo;
	char local_pu8MyBankID[15];
	char local_u8Flag = 0;
	tNode* local_strCurrntNode;

   

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be deposited >> ");
	scanf("%u", &local_u16DepNo);
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(!strcmp(local_strCurrntNode->accountStatus, "active"))
		{
			local_strCurrntNode->balance += local_u16DepNo;
			printf("\nYou deposited : %u , and your Account balance : %u \n", local_u16DepNo, local_strCurrntNode->balance);
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "restricted"))
		{
			printf("this account is restricted");
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "closed"))
		{
			printf("this account is closed");
		}
		else 
		{
			/*  */
		}
	}

}
//************************************************************************************//

char* Gen_Pass()
{
    // Initialize counter
    char i = 0;
  
    char randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((char)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";
  
    // Array of small alphabets
   char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    // Array of all the special symbols
    // Sint8_t symbols[] = "!@#$^&*?";
  
    // Stores the random password
    static char password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 3;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 3;
        }
        
        else if (randomizer == 2) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 3;
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 3;
        }
    }

	return password;
}
//*****************************************************************************************************//
char* Gen_Pass()
{
	    // Initialize counter
    char i = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((char)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";

    // Stores the random AccountID
    static char AccountID[MAX_NO_Bank_AccountID_Generator];
  
    // To select the randomizer
    // inside the loop
    // randomizer = rand() % 3;
  
    // Iterate over the range [0, N]
    for (i = 0; i < MAX_NO_Bank_AccountID_Generator; i++) 
	{
		AccountID[i] = numbers[rand() % 10];
    }

	return AccountID;
}


tNode* CheckUser( long long ID ){
	
	tNode *current=Head;
	
	while( current->pnext!= NULL ){ 
	
		if (current->BankAccountId==ID){
			return current;
	    }
	
		current=current->pnext;
	}
	//return node of sending ID
	return current;
}
//**********************************************************************************************************************************************
//Function Print List
void PrintList(){
	tNode *current = Head;
	while (current!=NULL){
		//printf("Address in memory= %X\n",current);
		printf("User Name: %s\n",current->Name);
		printf("National ID: %d\n",current->National_ID);
		printf("Password: %s\n",current->Password);
		printf("AccountID: %lld\n",current->BankAccountId);
		printf("Age: %d\n",current->Age);
		printf("Address: %s\n",current->Address);
		printf("Balance: %lld\n",current->Balance);
		printf("AccountStatus: %s\n",current->AccountStatus); 
		current=current->pnext;
	}	
} 

//******************************************************************************************************************************************************

