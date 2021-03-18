/* Compiler Theory and Design
   Dr. Duane J. Jarc 
	types.cc	
*/	
 /*------------------------------------------------------------------------------																								                                                                                                                                                                                          
 * File: types.cc
 * Author: Amanda Hajati
 * Project: Project 4
 * Date: May 9th, 2020
 * Description: handles all the type matching and its error handling
--------------------------------------------------------------------------------*/

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"

string resultType;
string expressionType;

void checkAssignment(Types lValue, Types rValue, string message)
{
if (lValue != MISMATCH && rValue != MISMATCH && lValue != rValue){
if(lValue != REAL_TYPE){
appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);}
}
if(lValue = REAL_TYPE){
	resultType= "real";
}else{
	resultType = "something";
		
}
}

string getResultType(){
	return resultType;
}

Types checkArithmetic(Types left, Types right)
{
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == BOOL_TYPE || right == BOOL_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Numeric Type Required");
		return MISMATCH;
	}
	if ((left == INT_TYPE && right == REAL_TYPE) || (left == REAL_TYPE && right == INT_TYPE))
	{
		if (getResultType() != "real"){
		appendError(GENERAL_SEMANTIC, "Illegal Narrowing Function Return");
		return MISMATCH;
		}
	}
	return INT_TYPE;
}

Types checkInteger(Types left, Types right)
{
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left != INT_TYPE || right != INT_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Integer Operands Required");
		return MISMATCH;
	}
	return INT_TYPE;
}

Types checkLogical(Types left, Types right)
{
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left != BOOL_TYPE || right != BOOL_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Boolean Type Required");
		return MISMATCH;
	}
		return BOOL_TYPE;
	return MISMATCH;
}

Types checkRelational(Types left, Types right)
{
	if (checkArithmetic(left, right) == MISMATCH)
		return MISMATCH;
	return BOOL_TYPE;
}

Types checkIfThen(Types expression, Types left, Types right)
{
	if (expression != BOOL_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "If Expression Must Be Boolean");
		return MISMATCH;
	} else
	{
		if (left != BOOL_TYPE || right !=BOOL_TYPE) {
			appendError(GENERAL_SEMANTIC, "If-Then Type Mismatch");
			return MISMATCH;
			
		}
		if ((left == INT_TYPE && right == REAL_TYPE) || 
		   (left == REAL_TYPE && right == INT_TYPE)) {
			appendError(GENERAL_SEMANTIC, 
			"Illegal Narrowing Function Return");
			   return MISMATCH;
		}
		return INT_TYPE;
	}
	return BOOL_TYPE;
}

Types checkExpression(Types expression) {
	if (expression != INT_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Case Expression must be of Integer Type");
		return MISMATCH;
	}
	
	

	return INT_TYPE;
}

Types checkCases(Types state1, Types state2) {
	if (state1 != BOOL_TYPE && state2 != BOOL_TYPE) {
	    appendError(GENERAL_SEMANTIC, 
	    "Case Types Mismatch");
	    return MISMATCH;
	}
	if (state1 != INT_TYPE && state2 != REAL_TYPE) {
	    appendError(GENERAL_SEMANTIC, 
	    "Case Types Mismatch");
	     return MISMATCH;
	}
	else {
	    return REAL_TYPE;
	}	
	if (state1 != REAL_TYPE && state2 != INT_TYPE) {
		appendError(GENERAL_SEMANTIC, 
		"Case Types Mismatch");
		return MISMATCH;
	}
	else {
	    return INT_TYPE;
	}
	return BOOL_TYPE;
}