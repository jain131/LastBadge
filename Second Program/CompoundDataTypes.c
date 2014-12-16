/*!*********************************************************************
*
* Original Author: Nishant Jain
*
* File Creation Date: 6 December 2014
*
* Description: A program that uses data structure to store data input 
* by the user and calculates and displays user's percentage score.
*
**********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Data structure to hold details of a user
struct member
{
  char Name[20];
  float marks[6];
  int Roll;
  long int CellNo;
  char Gender;
  float percentage;
};

//Function prototype
void change(struct member* user);


/*!**********************************************************************
* Module Name: main
*
* Original Author: Nishant
*
* Module Creation Date: December 5, 2014
*
* Description: Inputs user information into a struct and calls change()
*
* Required Files/Databases:
* None
*
* Non System Routines Called:
* None
*
* Return Value:
* Type Description
* int return(0)
*
* OS Specific Assumptions:
* None
*
* Local Variables:
* Name Type Description
* user struct member Data structure stores user's information
* ch char User's choice of operation
* k int Used to put initials of user's name in the string
* length int Length of string storing user's name
* Per float Percentage of user's marks 
*
***********************************************************************/
int main()
{
  /*!Flowchart: 
  * \image html compounddatatypes.jpg
  */

  //Declaring a member object pointer called user
  struct member *user;
  float *Per;
  Per = malloc(sizeof(Per));
  int k=0;
  char ch;
  int length;
  
  printf("This program will calculate percentage score of the user->\n");

  printf("\nWhat's your full name? ");
  fgets(user->Name, sizeof(user->Name), stdin);

  printf("\nWhat's your Roll Number? ");
  scanf(" %d", &user->Roll);
  
  printf("\nWhat's your gender (M/F)? ");
  scanf(" %c", &user->Gender);
  
  printf("\nWhat's you Cell Number? ");
  scanf(" %ld", &user->CellNo);

  for(int i=0; i<5 ; i++)
  {
    printf("Enter subject %d marks out of 100: ", i+1);
    scanf(" %f", &user->marks[i]);
  }


  //Displaying user's information
  do
  {
    printf("\n\nName= %s \nGender= %c", user->Name, user->Gender);
    printf("\nRoll Number= %d \nCell Number= %ld", user->Roll, user->CellNo);
  
    for(int i=0; i<5; i++)
    {
      printf("\nSubject %d marks: %f", i+1, user->marks[i]);
    }
  
    printf("\n\nIs the information correct (Y/N)? ");
    scanf(" %c", &ch);
    if(ch=='N' || ch=='n')
    {
      /*!
      * Passing a pointer to function as parameter
      * Call by reference
      */
      change(user);
    }
  }while(ch=='N' || ch=='n');
  
  //Putting Initials of the name in the user->Name string
  length=strlen(user->Name);
  user->Name[length]=' ';
  user->Name[length+1]=user->Name[0];
  //Finding the second initial
  while( user->Name[k]!=' ' && k<strlen(user->Name))
  {  
    k++;
  }
  user->Name[length+2]=user->Name[k+1];
  user->Name[length+3]='\0';


  //Calculating percentage
  for(int j=0;j<5;j++)
  { 
    //!Derefercing value of pointer variable Per  
    *Per+=user->marks[j];
  }

  *Per/=5;
  //!user->Percentage points to percentage Per now
  user->percentage = *Per;
  
  //Printing Report Card
  printf("\nName: %s \nRoll Number: %d \nGender: %c \nCell Number: %ld \n", 
    user->Name, user->Roll, user->Gender, user->CellNo);
  printf("Percentage= %f \n\n", user->percentage);
  
  free(Per);

  return (0);
}


/*!**********************************************************************
* Module Name: change
*
* Original Author: Nishant Jain
*
* Module Creation Date: December 6, 2014
*
* Description: This function allows user to change struct values
*
* Required Files/Databases:
* None
*
* Non System Routines Called:
* None
*
* Return Value: 
* None
*
* OS Specific Assumptions:
* None
*
* Local Variables:
* choice char-array Used to take input for user's choice 
* sub int Subject score to change
*
***********************************************************************/
void change(struct member* user)
{
  int choice;
  int sub;

  printf("\nWhat would you like to change?");
  printf("\n1)Name \n2)Roll Number \n3)Gender \n4)Cell Number");
  printf("\n5)Marks \n");
  scanf(" %d", &choice);


  /*
  * Dereferencing
  * Changes values in the struct user 
  */
  switch (choice)
  {
    case 1:
    printf("\nWhat's your full name? ");
    //To get rid of the spaces in the buffer
    getchar();
    fgets(user->Name, sizeof(user->Name), stdin);
    break;

    case 2:
    printf("\nWhat's your Roll Number? ");
    scanf(" %d", &user->Roll);
    break;

    case 3:
    printf("\nWhat's your gender (M/F)? ");
    scanf(" %c", &user->Gender);
    break;

    case 4:
    printf("\nWhat's you Cell Number? ");
    scanf(" %ld", &user->CellNo);
    break;

    case 5:
    printf("\nWhich subject would you like to change? ");
    scanf(" %d", &choice);
    printf("%s, enter subject %d marks out of 100: ", user->Name, choice);
    scanf(" %f", &user->marks[choice-1]);
    break;
  }
}
