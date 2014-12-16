/*!*********************************************************************
* 
* \brief Calculator 
*
* \author Nishant Jain
*
* \date 9 December 2014
*
* \details A source file with function Bitwise()
*
**********************************************************************/

#include "Bitwise.h"
#include <stdio.h>

/*!**********************************************************************
*
* \brief Bitwise
*
* \author Nishant Jain* \date November 27, 2014
*

*p-
* \details This function uses and displays bit operations on variables
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
* A integer used for calculating sum
* B integer used in for loop
* C integer used to calulate sum
*
***********************************************************************/

void Bitwise()
{
  int A, B, C;
  printf("Type two integers to learn about bitwise operations. A= ");
  scanf(" %d", &A);
  printf("\n B= ");
  scanf(" %d", &B);
  C= A & B;
  printf("AND: A & B = %d \n", C);
  C= A | B;
  printf("OR: A | B = %d \n", C);
  C= A ^ B;
  printf("XOR: A ^ B = %d \n", C);
  C= ~A;
  printf("COMPLEMENT: ~A = %d \n", C);
  C= A <<2;
  printf("LESFT SHIFT: A <<2 = %d \n", C);
  C= A >>2;
  printf("RIGHT SHIFT: A >>2 = %d \n", C);

}