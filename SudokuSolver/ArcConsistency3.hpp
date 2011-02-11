//
//  ArcConsistency3.h
//  SudokuSolver
//
//  Created by Brandon Lyons on 2/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#include "SudokuProblem.hpp"

class ArcConsistency
{
private:
   SudokuProblem * mySudoku;
   bool ac3solve();
   bool revise(std::pair < std::set < char > *, Constraint * > x);
public:
   ArcConsistency(SudokuProblem * newSudoku); 
};