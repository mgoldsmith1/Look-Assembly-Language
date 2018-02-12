//
//  Implementation of file access class.
//
#include "stdafx.h"
#include "FileAccess.h"

// Don't forget to comment the function headers.
FileAccess::FileAccess( int argc, char *argv[] )
{
	
    // Check that there is exactly one run time parameter.
    if( argc != 2 ) {
        cerr << "Usage: Assem <FileName>" << endl;
        exit( 1 );
    }
		// Open the file.  One might question if this is the best place to open the file.
		// One might also question whether we need a file access class.
		//
	m_sfile.open(argv[1], ios::in);

    // If the open failed, report the error and terminate.
    if( ! m_sfile ) {
        cerr << "Source file could not be opened, assembler terminated."
            << endl;
        exit( 1 ); 
    }
	else{
		cout << "Source file found" << endl;
		//m_sfile.read();
		while ( !m_sfile.eof() ) {		
           m_sfile >> m_buff;
		   GetNextLine(m_buff);
		}
	}
}
FileAccess::~FileAccess( )
{
    m_sfile.close( ); //Closes the file
}
// Get the next line from the file.
bool FileAccess::GetNextLine( string &a_buff ) 
{
    if( m_sfile.eof() ) return false; //***True if at the end of the file

    getline( m_sfile, a_buff );
    
    // Return indicating success.
    return true;
}
void FileAccess::rewind( ) //Going back to the beginning 
{
    // Clean the end of file flag and go back to the beginning of the file.
    m_sfile.clear();	//***Clears the bits in the ifstream?
    m_sfile.seekg( 0, ios::beg ); //***Means next place we ae reading is from the beginning of the file 
}
    
