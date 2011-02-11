//
//  ArcConsistency3.cpp
//  SudokuSolver
//
//  Created by Brandon Lyons on 2/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ArcConsistency3.hpp"
#include "Constraint.hpp"
#include <queue>
#include <iostream>
#include "SudokuTypes.h"
#include <vector>

using namespace std;

ArcConsistency::ArcConsistency(SudokuProblem * newSudoku)
{
   mySudoku = newSudoku;
   if (ac3solve())
      cout << "consistent\n";
   else
      cout << "inconsistent\n";
   vector< c_set * > test = newSudoku->getVariables();
   for (int i = 0; i < 81; )
   {
      for (s_iter cSetIter = test.at(i)->begin(); cSetIter != test.at(i)->end(); cSetIter++)
      {
         cout << *cSetIter;
      }
      if (++i % 9)
      {
         cout << " ";
      }
      else
      {
         cout << "\n";
      }
   }
}

bool ArcConsistency::ac3solve()
{
   queue < c_pair > myQueue;
   c_pair myPair;
   c_map tempMap = mySudoku->getConstraints();
   int count = 0;
   for (m_iter itr = tempMap.begin(); itr != tempMap.end(); ++itr)
   {
      count++;
      myQueue.push(*itr);
   }
   count = 0;
   while (!myQueue.empty()) 
   {
      myPair = myQueue.front();
      /*
      cout << "examining ";
      for (s_iter cSetIter = myPair.first->begin(); cSetIter != myPair.first->end(); cSetIter++)
      {
         cout << *cSetIter << " ";
      }
      cout << "against ";
      for (s_iter cSetIter = myPair.second->getVariable()->begin(); cSetIter != myPair.second->getVariable()->end(); cSetIter++)
      {
         cout << *cSetIter << " ";
      }
      cout << endl;
       */
      myQueue.pop();
      count++;
      if (revise(myPair)) 
      {
         if (myPair.first->size() == 0) 
         {
            return false;
         }
         m_range neighbors = tempMap.equal_range(myPair.first);
         for (m_iter itr = neighbors.first; itr != neighbors.second; ++itr)
         {
            if (itr->second->getVariable() != myPair.second->getVariable())
            {
               m_range kConst = tempMap.equal_range(itr->second->getVariable());
               for (m_iter blah = kConst.first; blah != kConst.second; ++blah)
               {
                  if (myPair.first == blah->second->getVariable()) {
                     myQueue.push(*blah);
                  }
               }
            }
         }
      }
   }
   cout << "count = " << count << endl;
   return true;
}

bool ArcConsistency::revise(c_pair x)
{
   bool revised = false;
   s_iter setItr;
   for (setItr = x.first->begin(); setItr != x.first->end(); ++setItr)
   {
      if (!x.second->allowed(*setItr))
      {
         x.first->erase(setItr--);
         revised = true;
      }
   }
   return revised;
}
