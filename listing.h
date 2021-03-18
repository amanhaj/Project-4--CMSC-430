/* Compiler Theory and Design
   Dr. Duane J. Jarc 
	listing.h
*/
 /*------------------------------------------------------------------------------																								                                                                                                                                                                                          
*Name: Amanda Hajati                                                                                            
*Project 4                                                                                     
*File name: listing.h                                                                    
*Date: May 9th, 2020                                                                   
*Description: This file contains the function prototypes for the functions that produce the // compilation listing      
--------------------------------------------------------------------------------*/
enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);
