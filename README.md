# Project-4--CMSC-430 Compiler Theory & Design
CMSC 430 Project 4

The fourth project involves modifying the semantic analyzer for the attached compiler by adding checks for semantic errors. The static semantic rules of this language are the following: Variables and parameter names have local scope. The scope rules require that all names be declared and prohibit duplicate names within the same scope. The type of correspondence rules are as follows:

 Boolean expressions cannot be used with arithmetic or relational operators.

 Arithmetic expressions cannot be used with logical operators.

 Reductions can only contain numeric types.

 Only integer operands can be used with the remainder operator.

 The two statements in an if statement must match in type. No coercion is performed.

 All the statements in a case statement must match in type. No coercion is performed.

 The type of the if expression must be Boolean.  The type of the case expression must be Integer

 A narrowing variable initialization or function return occurs when a real value is being forced into integer. Widening is permitted.

 Boolean types cannot be mixed with numeric types in variable initializations or function returns.

Type coercion from an integer to a real type is performed within arithmetic expressions.

You must make the following semantic checks. Those highlighted in yellow are already performed by the code that you have been provided, although you are must make minor modifications to account for the addition of real types and the need to perform type coercion and to handle the additional arithmetic and logical operators.  Using Boolean Expressions with Arithmetic Operator

 Using Boolean Expressions with Relational Operator

 Using Arithmetic Expressions with Logical Operator

 Reductions containing non-numeric types

 Remainder Operator Requires Integer Operands

 If-Then Type Mismatch

 Case Types Mismatch

 If Condition Not Boolean

 Case Expression Not Integer

 Narrowing Variable Initialization

 Variable Initialization Mismatch

 Undeclared Variable

 Duplicate Variable

 Narrowing Function Return

This project requires modification to the bison input file so that it defines the additional semantic checks necessary to produce these errors and the addition of functions to the library of type checking functions already provided in types.cc. You must also make some modifications to the functions provided. You need to add a check to the check assignment function for mismatched types in the case that Boolean and numeric types are mixed. You need to also add code to the check arithmetic function to coerce integers to reals when the types are mixed and the error message must be modified to indicate that numeric rather than only integer types are permitted. The provided code includes a template class Symbols that defines the symbol table. It already includes a check for undeclared identifiers. You need to add a check for duplicate identifiers.
