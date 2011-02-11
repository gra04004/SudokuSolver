#include <iostream>
#include "SudokuProblem.hpp"
#include "ArcConsistency3.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
   if (argc > 1)
   {
      SudokuProblem * test = new SudokuProblem(argv[1]);
      ArcConsistency * blah = new ArcConsistency(test);
      delete test;
   }
   return 0;
}
