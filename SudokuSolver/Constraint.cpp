#include "Constraint.hpp"

#include "SudokuTypes.h"

Constraint::Constraint()
{
   mVariable = NULL;
}

Constraint::Constraint(c_set * pVariable)
{
   mVariable = pVariable;
}

void Constraint::setVariable(c_set * pVariable)
{
   if (mVariable == NULL)
   {
      mVariable = pVariable;
   }
}

bool Constraint::allowed(char x)
{
   s_iter setItr;
   for (setItr = mVariable->begin(); setItr != mVariable->end(); setItr++)
   {
      if (*setItr != x)
      {
         
         return true;
      }
   }
   return false;
}

c_set * Constraint::getVariable()
{
   return mVariable;
}