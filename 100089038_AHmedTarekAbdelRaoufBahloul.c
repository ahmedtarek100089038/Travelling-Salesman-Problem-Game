#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NROW 8
#define NCOL 8



/* input name function*/
void inputName(char name[]){

    printf("\n\nPlease key in your name: ");
    scanf("%s", name);

    printf("***Good day %s, let's start the game...all the best!!!***", name);

    printf("\n\nPress any key to start the game...\n\n");
    getchar();

}


/* Board Function (Array 8 Rows and 8 Coloums) */

	/* Initialize Array First */

void initialize(char a[NROW][NCOL]){

    /* Declare variable */
    int x, y;

	/* Make Array */

    for(x=0; x<NROW; x++){

        for(y=0; y<NCOL; y++){

         	a[x][y]= '.';	 /* Display Dots in Board Function	 */
		}
	}
}


/* Display Board Function */

void disp_arr(char a[NROW][NCOL])
{
	int x,y;
	/* Srand(time(NULL)) is for generate a random letter and use it one time only  */

	srand(time(NULL));

	

	for(x=0; x<NROW; x++)
	{
        for(y=0; y<NCOL; y++)
		{
         
		if(x == 1 && y == 0)
			{
				printf("|-%c-|\t", a[x][y]);
			}

			else
			{
				printf(" %c \t", a[x][y]);
			}
		
		}

        printf("\n\n");

	}


}

/* This function to declare and initialize random letter  */

char rndch(void)
{

	/* Declare variable */
	
	int rl;
	
  /* randomise the alphabets of NROW and NCOL. 19 means that use first 19 letters. 'A' means that random function will start from letter A */

    rl = (rand() % 9) + 'A';
	
	return (char)rl;
}


/* This function will generate a random alphabets and dots */

void init(char a[NROW][NCOL]){

	/* Declare variable */
	
    int i, j, n;



    for(i = 0;i < NROW;i++)
    {
		n = (rand() % 2)+1; /* this is for display random letters in row */

        for(j = 0;j < NCOL;j++)
        {
            a[i][j] = rndch();

			j = j + n;

			n = (rand() % 1) + 1; /* this is for display random letters in column */

			i = i + n;
		}
	}
}






/* print and get Player's action function*/

int playerAction(int *steps, int *citiescount){

	/* Declare variable */
	
    char choice;
	
	int x;

	
    fflush(stdin);
	printf("\nTotal Steps taken: %i . [Number of cities yet to cover: %i ]\n", *steps, *citiescount);
	
    printf("Press '6' to go right\n");

    printf("Press '4' to move left\n");

    printf("Press '8' to move up\n");

	printf("Press '2' to move down\n");

    printf("Please choose your next action (press 'Q' to quit) : ");
	
	choice = getch();
    fflush(stdin);

    return choice;
}


/* declaration for the below function to avoid errors because it involved this function*/

void loopchoice(char a[NROW][NCOL], char choice, int *row, int *col, int *steps, int *citiescount)
{

	/* Declare variable */
	
	int x,y;
	
	/* Use Swicth Case because switch statement allows a variable to be tested for equality against a list of values. */
	
    switch(choice)
    {
        case '6':	/* Ife player click on '6' */
		{
			if(*col!=7)		/* This  ' col!=7 ' means that it is a boarder and player cannot go to row number 8  */
			{
				*steps+=1;	/* Counts how many steps taken by player */
				
	            (*col)+=1;	/* Means that player can move to the right */
				
				if(a[*row][*col] != '.')	/* If rows and columns not equal to dots */
				{
					*citiescount-=1;		/* Then program will count down ho many cities left */
				}
			}

			break;
		}
        case '4':	/* Ife player click on '4' */
		{
			if(*col!=0)		/* col!=0 means that there is 7 columns only, it is a boarder  */
			{
				*steps+=1;	/* Counts how many steps taken by player */
				
	           	(*col)-=1;	/* Means that player can move to the left */
				
				if(a[*row][*col] != '.')	/* If rows and columns not equal to dots */
				{
					*citiescount-=1;		/* Then program will count down ho many cities left */
				}
			}
			break;
		}
		case '8':	/* Ife player click on '8' */
		{
			if(*row!=0)		/* This  ' *row!=0 ' means that it is a boarder and player cannot go to row number 8  */
			{
				*steps+=1;	/* Counts how many steps taken by player */
				
	            (*row)-=1;	/* Means that player can move to  up */
				
				if(a[*row][*col] != '.')	/* If rows and columns not equal to dots */
				{
					*citiescount-=1;
				}
			}
			break;
		}	 	   
        case '2':	/* Ife player click on '2' */
		{
			if(*row!=7)		/* This  ' *row!=7 ' means that it is a boarder and player cannot go to row number 8  */
			{
				*steps+=1;	/* Counts how many steps taken by player */
				
	            (*row)+=1;	/* Means that player can move to down */
				
				if(a[*row][*col] != '.')	/* If rows and columns not equal to dots */
				{
					*citiescount-=1;	/* Then program will count down ho many cities left */
				} 
			}
			break;
		}	 
        case 'Q': case 'q':
            printf("Thanks for playing! See you again!");
            break;
        default:
            printf("Wrong input! Press enter to continue.");
            getchar();
            system("cls");
    }
	system("cls");
	

	/* New board function */
	
	for(x=0; x<NROW; x++)
	{
        for(y=0; y<NCOL; y++)
		{	 
         	if(x == *row && y == *col && a[x][y] == '.' )
			{
				printf("|-%c-|\a\t",a[*row][*col]);
			}

			else if(x == *row && y == *col && (a[x][y] != '.' || a[x][y] == '#'))
			{
				printf("|-%c-|\a\t",a[*row][*col]);
				a[*row][*col] ='#';
			}
			else
			{
				printf(" %c \t", a[x][y]);
			}
		}

        printf("\n\n");

	}
	
	
}





/* This is message will display to the player when he win */

void endgame()
{
        printf("\n\n\tCongratulation! You have travelled to all the cities!\n");

        printf("\t\tThanks for playing!!! See you again...\n");
}



/* writefile to key in player's record into the text file*/

void writefile(char name[20],int steps, int citiescount)
{
	FILE *playerinfo;
	
	playerinfo = fopen("playerinfo.txt", "a");
	
	fprintf(playerinfo, "\n   %s \t %i \t %i\n", name, steps, citiescount);
	fclose(playerinfo);
	
}


/* readfile to get previous player's record*/

void  readfile()
{
	char name[20];
    int num, steps, citiescount;
	FILE *playerinfo;
	playerinfo = fopen("playerinfo.txt", "r");
	
	do
	{
		num= fscanf(playerinfo,"\n\t %s\t\t%i\t\t\t%i\n\n", name, &steps, &citiescount);
		
		if(num == 3)
		{	
			
			printf("\t %s\t\t%i\t\t%i\n\n", name, steps, citiescount);
		}
	}while(num == 3);

	fclose(playerinfo);

}



/* main function for the game*/
int main()
{
	/* declaration made*/
	char ar[NROW][NCOL];
	
	int x, y, n=1, row=0,col=0, steps=0, citiescount = 7;
	
	char name[20], choice;
	
	srand((unsigned int)time(NULL));
	
	initialize(ar);

	printf("\n\t******* Welcome to Travelling Salesman Problem! *********\n\n");
	printf("\t\t***   Previous Players' Record  ****\n\n");
	printf("\t NAME\t\tSTEPS\t\tCITIE S\n\n");
	
	/* Display Previous players' record*/
	
	readfile();
	
	/* call inputName function */
	
	inputName(name);
	
	/* When player enter any key */
	
    getchar();
	
	/* To clear the screen */
	
	system("cls");

	/* Call board function */
	
	init(ar);
	disp_arr(ar);

	/* Use do while statement */
	
	do{
		/* make choice equal to playerAction function to update steps taken and how many cities left */
		
		choice = playerAction(&steps, &citiescount);	
		
		/* print loopchice function */
		
		loopchoice(ar, choice, &row, &col, &steps, &citiescount);
		
		/* player win when citiescount count down to reach to 0 */
	  	if(citiescount==0)
		{
			/* Display Congratulation message */
			
			endgame();
			
			break;
		}

	}while(choice!='Q'); /* If player press 'Q' will exit from the game , and there is a meesage will display */
	
	printf("\t\tThanks for playing!!! See you again...\n");
	

	/* Store player's information in text file to that next plaeyer can see his/her information */
	
	writefile(name, steps, citiescount);
	

    return 0;
}



