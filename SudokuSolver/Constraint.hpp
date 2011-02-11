#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <vector>
#include <set>

class Constraint
{
private:
   std::set < char > * mVariable;
public:
   Constraint();
   Constraint(std::set < char > * pVariable);
   void setVariable(std::set < char > * pVariable);
   bool allowed(char x);
   std::set < char > * getVariable();
};

#endif
