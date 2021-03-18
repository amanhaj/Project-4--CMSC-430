/* Compiler Theory and Design
   Dr. Duane J. Jarc 
	listing.cc
*/
 /*------------------------------------------------------------------------------																								                                                                                                                                                                                          
*Name: Amanda Hajati                                                                                               
*Project 4                                                                                     
*File name: listing.cc                                                                    
*Date: May 9th, 2020                                                                   
*Description: handles the counting of errors                               
--------------------------------------------------------------------------------*/


#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"

static int lineNumber;
static string multipleError = "";
static string error = "";
static int errorLine = 0;
static int totalErrors = 0;
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;

static void displayErrors();

void firstLine() {
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine() {
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine() {
	printf("\r");
	displayErrors();
	printf("     \n");

	if (totalErrors > 0) {
		printf("\nLexical Errors:  %4d", lexicalErrors);
		printf("\nSyntax Errors:   %4d", syntaxErrors);
		printf("\nSemantic Errors: %4d", semanticErrors);
		printf("\nTotal Number of Errors: %4d\n", totalErrors);
	}
	if (totalErrors == 0)
 		printf("Compiled Successfully\n");
	return totalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message)
{
	string messages[] = { "Lexical Error, Invalid Character ", "",
 	"Semantic Error, ", "Semantic Error, Duplicate Identifier: ",
 	"Semantic Error, Undeclared " };

	error = messages[errorCategory] + message;
	multipleError += error;
	multipleError += "\n";
	totalErrors++;
	if (errorCategory == 0)
 		lexicalErrors++;
	if (errorCategory == 1)
		 syntaxErrors++;
	if (errorCategory >= 2)
		 semanticErrors++;
}

void displayErrors()
{
	if (error != "") {
   		printf("\n%s\n", multipleError.c_str());
 	}
	error = "";
	multipleError = "";
}