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
                    Open_existaccount();
                
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
                    Make_Transaction();
                    break;
                }
                else if (choice ==2) //change password
                {
                   Chg_Pass();  

                }
                else if (choice ==3)
                {

                    Get_Cash();
                }
                else if(choice ==4)
                {
                    Deposit_account();
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



void Open_existaccount(tnode **head)
{

}

void Make_Transaction(tnode **head)
{
    unsigned transCash;
    char MyID[20], TransID[20];
    printf("Please enter your Bank ID:");
    scanf("%s",MyID);
    printf("Please enter the ID you want to trasfer to:");
    scanf("%")
    printf("Please enter the amount of money you want to transfer");
    scanf("%u",&transCash);
    tempnode->Balance
}

void Chg_Pass(tnode **head)
{

}

void Get_Cash(tnode **head)
{

}

void Deposit_account(tnode **head)
{

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