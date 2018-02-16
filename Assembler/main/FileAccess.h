//
//		File access to source file.
//
#ifndef _FILEACCESS_H   
#define _FILEACCESS_H 

#include <fstream>
#include <stdlib.h>
#include <string>

class FileAccess {

public:

    // Opens the file.
    FileAccess( int argc, char *argv[] );

    // Closes the file.
    ~FileAccess( );

    // Get the next line from the source file.
    bool GetNextLine( string &a_buff );

    // Put the file pointer back to the beginning of the file.
    void rewind( );

private:
        ifstream m_sfile;		// Source file object.
	string m_buff;
};
#endif

