/* Compiler Theory and Design
   Dr. Duane J. Jarc 
	symbols.h
*/
 /*------------------------------------------------------------------------------																								                                                                                                                                                                                          
* File: symbols.h
 * Author: Amanda Hajati
 * Project: Project 4
 * Date: My 9th, 2020
 * Description: creates the symbol table helps handle parameters
--------------------------------------------------------------------------------*/

template <typename T>
class Symbols
{
public:
	void insert(char* lexeme, T entry);
	bool find(char* lexeme, T& entry);
private:
	map<string, T> symbols;
};

template <typename T>
void Symbols<T>::insert(char* lexeme, T entry)
{
	string name(lexeme);
	symbols[name] = entry;
}

template <typename T>
bool Symbols<T>::find(char* lexeme, T& entry)
{
	string name(lexeme);
	typedef typename map<string, T>::iterator Iterator;
	Iterator iterator = symbols.find(name);
	bool found = iterator != symbols.end();
	if (found)
		entry = iterator->second;
	return found;
}