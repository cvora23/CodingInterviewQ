/*
 * Test46.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: chintan
 */

/*
 * given a string with only paranthesis - find out if it is balanced or not
eg {}[]()
followup : scale your solution and specify the right data structure
to use if you have a lot of such bracket types
 */

#include <stack>
#include <stdio.h>

/* Returns 1 if character1 and character2 are matching left
   and right Parenthesis */
bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

/*Return 1 if expression has balanced Parenthesis */
bool areParenthesisBalanced(char exp[])
{
   int i = 0;

   /* Declare an empty character stack */
   std::stack<char>myStack;

   /* Traverse the given expression to check matching parenthesis */
   while (exp[i])
   {
      /*If the exp[i] is a starting parenthesis then push it*/
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
    	  myStack.push(exp[i]);

      /* If exp[i] is a ending parenthesis then pop from stack and
          check if the popped parenthesis is a matching pair*/
      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
      {

          /*If we see an ending parenthesis without a pair then return false*/
         if (myStack.empty())
           return 0;

         /* Pop the top element from stack, if it is not a pair
            parenthesis of character then there is a mismatch.
            This happens for expressions like {(}) */
         else if ( !isMatchingPair(myStack.top(), exp[i]))
           return 0;

         else if(isMatchingPair(myStack.top(), exp[i]))
             myStack.pop();
      }
      i++;
   }

   /* If there is something left in expression then there is a starting
      parenthesis without a closing parenthesis */
   if (myStack.empty())
     return 1; /*balanced*/
   else
     return 0;  /*not balanced*/
}

/* UTILITY FUNCTIONS */
/*driver program to test above functions*/
int main()
{
  char exp[100] = "{()}[]";
  if (areParenthesisBalanced(exp))
    printf("Balanced \n ");
  else
    printf("Not Balanced \n ");
  return 0;
}
