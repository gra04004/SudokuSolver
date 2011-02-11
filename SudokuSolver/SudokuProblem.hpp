#ifndef SUDOKU_PROBLEM_HPP
#define SUDOKU_PROBLEM_HPP

#include <map>
#include <vector>
#include "Constraint.hpp"

class SudokuProblem
{
private:
   std::vector < std::set < char > * > variables;
   std::multimap < std::set < char > *, Constraint * > constraints;
public:
   SudokuProblem(const char * fileName);
   std::multimap < std::set < char > *, Constraint * > getConstraints();
   std::vector < std::set < char > * > getVariables();
};

#endif
