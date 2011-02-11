#include "SudokuProblem.hpp"

#include <fstream>
#include <iostream>
#include "SudokuTypes.h"

using namespace std;

SudokuProblem::SudokuProblem(const char * fileName)
{
   ifstream fin;
   fin.open(fileName);
   if (fin.fail())
   {
      cerr << "Error: Cannot open file " << fileName << endl;
      fin.clear();
   }
   else
   {
      char tempChar;
      Constraint* constraintList[9][9];
      for (int i = 0; i < 9; i++)
      {
         for (int j = 0; j < 9; j++)
         {
            constraintList[i][j] = new Constraint();
         }
      }
      
      c_set * tempSet;
      int i = 0, j = 0;
      while (fin >> tempChar)
      {
         // determine the domain of the variable
         if (tempChar == '_')
         {
            char domain[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            tempSet = new c_set (domain, domain + 9);
         }
         else if (('1' <= tempChar) && (tempChar <= '9'))
         {
            char domain[] = { tempChar };
            tempSet = new c_set (domain, domain + 1);
         }
         else
         {
            // The character is not an acceptable value, the file must be corrupt
            cerr << "Error: Corrupt file\n";
            exit(1);
         }
         variables.push_back(tempSet);
         constraintList[i][j]->setVariable(tempSet);
         for (int a = 0; a < 9; a++)
         {
            // TODO: Need to add the constraints with the cells in the same square
            if (tempSet != constraintList[i][a]->getVariable())
            {
               constraints.insert( c_pair(tempSet, constraintList[i][a]) );
            }
            if (tempSet != constraintList[a][j]->getVariable())
            {
               constraints.insert( c_pair(tempSet, constraintList[a][j]) );
            }
            if (tempSet != constraintList[(i/3)*3+a/3][(j/3)*3+a%3]->getVariable())
            {
               constraints.insert( c_pair(tempSet, constraintList[(i/3)*3+a/3][(j/3)*3+a%3]) );
            }
         }
         if (++j == 9)
         {
            j = 0;
            i++;
         }
      }
      if (variables.size() != 81)
      {
         cerr << "Error: Incorrectly sized Sudoku puzzle\n";
         exit(1);
      }
      m_iter outItr, inItr;
      for (outItr = constraints.begin(); outItr != constraints.end(); outItr++)
      {
         for (inItr = outItr; inItr != constraints.end(); inItr++)
         {
            if ((outItr != inItr) and (*outItr == *inItr))
            {
               constraints.erase(inItr++);
            }
         }
      }
   }
   cout << constraints.size() << endl;
   return;
}

c_map SudokuProblem::getConstraints()
{
   return constraints;
}

std::vector < c_set * > SudokuProblem::getVariables()
{
   return variables;
}
