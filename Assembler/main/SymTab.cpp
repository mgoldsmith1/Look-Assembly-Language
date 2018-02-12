//
//		Implementation of the symbol table class.
//
#include "stdafx.h"
#include "SymTab.h"

/*
NAME

    AddSymbol - adds a new symbol to the symbol table.

SYNOPSIS

    void AddSymbol( char *a_symbol, int a_loc );

DESCRIPTION

    This function will place the symbol "a_symbol" and its location "a_loc"
    in the symbol table.
*/
void 
SymbolTable::AddSymbol( string &a_symbol, int a_loc )
{
    // If the symbol is already in the symbol table, record it as multiply defined.
    map<string, int>::iterator st;
    st = m_symbolTable.find( a_symbol );

    if( st != m_symbolTable.end() ) {
        st->second = -999;
        return;
    }
    // Record the location in the symbol table.
    m_symbolTable[a_symbol] = a_loc;
}
void SymbolTable::DisplaySymbolTable()
{
   map<string, int>::iterator it;
   for(it = m_symbolTable.begin(); it != m_symbolTable.end(); ++it)
   {
      cout << it->first << " " << it->second << "\n"; 
   }

}
string SymbolTable::DisplaySymbol(int &a_loc)
{
	map<string, int>::iterator it;
	string hi = "";
	for (it = m_symbolTable.begin(); it->second != a_loc && it != m_symbolTable.end(); ++it)
	{
		return hi = it->first;
	}
}
int SymbolTable::DisplaySymbolLocationTable()
{
	map<string, int>::iterator it;
	int get = 0;
	for (it = m_symbolTable.begin(); it != m_symbolTable.end(); ++it)
	{
		cout << it->second << "\n";
		return get = it->second;
	}
}

string SymbolTable::LookupSymbol( int &a_loc) {
	map<string, int>::iterator it;
	for (it = m_symbolTable.begin(); it->second <= a_loc; ++it) {
		if (it->second == a_loc) {
			return "" + a_loc;
		}
	}

}
