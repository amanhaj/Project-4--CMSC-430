/* Compiler Theory and Design
   Dr. Duane J. Jarc 
	types.h
*/
 /*------------------------------------------------------------------------------																								                                                                                                                                                                                          
 * File: types.h
 * Author: Amanda Hajati
 * Project: Project 4
 * Date: May 9th, 2020
 * Description: defines the enum types for number types
--------------------------------------------------------------------------------*/
#include <vector>

typedef char* CharPtr;

enum Types {MISMATCH, INT_TYPE, REAL_TYPE, BOOL_TYPE, EMPTY};

void checkAssignment(Types lValue, Types rValue, string message);
Types checkArithmetic(Types left, Types right);
Types checkLogical(Types left, Types right);
Types checkRelational(Types left, Types right);
Types checkInteger(Types left, Types right);
Types checkIfThen(Types expression, Types left, Types right);
Types checkExpression(Types expression);
Types checkCases(Types state1, Types state2);