/*!*********************************************************************
* 
* \brief Calculator 
*
* \author Nishant Jain
*
* \date 25 November 2014
*
* \details A Calulator program with basic Arithmetic Operations
* and some extra features such as sum of Fibonacci series,
* bitwise operations and square-root function
*
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Bitwise.h"

//Function prototype 
void Extra();
void CalcFib(int r);


/*!**********************************************************************
*
* \brief main
*
* \author Nishant
*
* \date November 25, 2014
*
* \details Calls arithmetic functions and uses file to log outputs
*
* Required Files/Databases:
* Log.txt
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
* check char To see if user wants to continue
* ch int User's choice of operation
* opt char User's choice of getting value from log file
* var1 float Operand 1
* var2 float Operand 2
* res float Result of Arithmetic operation
*
* Modification History:
* Date Developer Action
* 8/20/2004 Jane Doe Changed the equation used to convert
* Celsius to Fahrenheit.
* 
***********************************************************************/

/*!
* 1 while loop
* 2 if- else selection (NESTED)
* 2 switch-case constructs
* 1 for loop
*/

int main()
{
  //Welcome Screen
  printf("Welcome to Calculator. \n");
  /*! 
  * Flowchart diagram: 
  * \image html FlowchartCalc.jpeg
  */

  char check='y';
  int ch;
  char opt;
  float var1, var2;
  float res;
  FILE * Log;

  //Opening a new file for Logging info. Opening in reading and writing mode
  Log = fopen ("Log.txt", "w+");
      
  while(check!='n')
  { 
    printf("Please select an Arithmetic operation from the following:\n");
    printf("1)Addition \t 2)Subtraction \t 3)Multiplication \n4)Division"
    "\t 5)Power \t 6)Extra Features \n");
    
    //Input of operation, A SPACE before %d makes scanf ignore whitespace
    scanf(" %d", &ch);
    
    //Condition for Extra Features option
    if(ch!=6)
    {
      //Asking user if he wants to use saved previous result
      printf("Do you want to use the previous result as"
        " one of the operands (Y/N)? \n");
      scanf(" %c", &opt);
      printf("Enter any values for operand(s): \n");
      
      if(opt=='Y' || opt=='y')
      {
        printf("Operand 1 is the previous result: ");
        rewind(Log);
        //Taking value from the LOG text file for variable 1
        fscanf(Log, " %f", &var1);
        printf("%f \n", var1);
      }  
    
      else 
      {
        printf("Operand 1: "); 
        scanf("%f", &var1);
      }
      
      printf("Operand 2: "); 
      /*! 
      * An optional starting asterisk or space indicates 
      * that the data is to be read from the stream but 
      * ignored, i.e. it is not stored in the corresponding argument.
      * Input of variable2 
      */
      scanf(" %f", &var2);
      
      //Switch case construct: Statements for different conditions 
      switch(ch) 
      {
        case 1: res=var1+var2; break;
        case 2: res=var1-var2; break;
        case 3: res=var1*var2; break;
        case 4: res=var1/var2; break;
        case 5: res=pow(var1,var2); break;
      }
       
      //Displaying result from file
      printf("\nThe Result= %f \n", res); 
      //Rewind to go back to the starting of the file
      rewind(Log);
      //Logging the result
      fprintf(Log, " %f", res);
    
    }
    
    //Calling the CalcFib() function and passing range as parameter.
    else Extra();  
    
    //Asking user to continue or exit
    printf("\nContinue y/n?  ");
    scanf(" %c",&check);
    
  }    
  
  // Closing opened text file
  fclose(Log);
  
return(0);
}


/*!**********************************************************************
* \brief Extra
*
* \author Nishant Jain
*
* \date November 27, 2014
*
* \details This function calculates square root. 
* Calls CalcFib() and Bitwise()
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
* ch integer User's choice for operation
* r integer Parameter passed as range of fibonacci series
* sq float Square root of input number
*
***********************************************************************/
void Extra()
{ 
  int ch,r;
  float sq;

  printf("\nSelect from the following options: \n1)Fibonacci Series"
  " \n2)Bitwise Operations \n3)Square root \n");
  scanf(" %d",&ch);
  
  switch(ch)
  {
    case 1:
    printf("\nEnter the range of Fibonacci series: \n "); 
    scanf(" %d",&r);
    CalcFib(r); break;
    
    case 2:
    Bitwise(); break;

    case 3:
    printf("Enter the number you want the square root of: ");
    scanf(" %f",&sq);
    printf("\n Square root of %f: ",sq); 
    sq=sqrt(sq);
    printf("%f",sq);  break;
  }
}
 

/*!**********************************************************************
*
* \brief CalcFib
*
* \author Nishant Jain
*
* \date November 27, 2014
*
* \detailsThis function finds sum of Fibonacci Series
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
* j integer used for calculating sum
* i integer used in for loop
* k integer used to calulate sum
* res integer used to calulate sum
* sum long integer to store sum of fibonacci series
*
***********************************************************************/ 
void CalcFib(int r)
{
  int j=0, i=2, k=1, res;
  long int sum=1;
  
  printf("FIBONACCI SERIES: ");
  //printing first two values.
  printf("%d %d",j,k); 

  /*
  * Using increment operator in for loop
  * Displaying Fibonacci series
  * Using "+=" operator
  * Finding Sum of Fibonacci series
  */
  
  for(i=2;i<r;i++)
  {
    res=j+k;
    j=k;
    k=res; 
    printf(" %d",k);
    sum+=k;
  }  
  printf("\nSum of Fibonacci series= %ld \n", sum); 
}







