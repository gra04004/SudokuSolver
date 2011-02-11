//
//  SudokuTypes.h
//  SudokuSolver
//
//  Created by Brandon Lyons on 2/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUDOKU_TYPES_H
#define SUDOKU_TYPES_H

#include <set>
#include <map>
#include "Constraint.hpp"

typedef std::set < char > c_set;
typedef c_set::iterator s_iter;
typedef std::multimap < c_set * , Constraint * > c_map;
typedef std::pair < c_set *, Constraint * > c_pair;
typedef c_map::iterator m_iter;
typedef std::pair<m_iter, m_iter> m_range;

#endif