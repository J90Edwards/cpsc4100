#include <stdio.h>              /* for printf, file stuff, etc */
#include <stdlib.h>             /* for exit */

// constants defined with preprocessor
#define MSG_SIZE 100
#define LINE_SIZE 1024


// argv is array of command line parameters
// argc is number of items in that array
// argv[0] is always the executable name
int main(int argc, char *argv[])
{
    // require 1 parameter (2 items in argv: executable name, parameter)
    if (argc != 2)
    {
        // error messages should be routed to stderr rather than stdout
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);

        // exit the program
        exit(-1);
    }

    // open command line parameter in read mode
    FILE* in = fopen(argv[1], "r");

    // fopen returns NULL (aka 0) upon failure
    if (in == NULL)
    {
        // 
        char msg[MSG_SIZE];
        snprintf(msg, MSG_SIZE, "Error opening '%s'", argv[1]);

        // print error with diagnostic message based on global errno used by
        // system calls
        perror(msg);

        // exit the program
        exit(-1);
    }


    // at this point, you can read the contents of the file using calls from
    // the standard library like fscanf, getline or fread (for binary files)
    // never use gets!  it's a security risk.
    
    // declare a char buffer (aka array) for temporary file contents
    char line[LINE_SIZE];

    // fgets gets the next line of text from 'in' (at most LINE_SIZE bytes to
    // avoid a buffer overflow) and stores in buffer (null-terminated)
    while (fgets(line, LINE_SIZE, in) != NULL)
    {
        // output the buffer we just read to stdout
        fputs(line, stdout);
    }

    // fgets probably ended because it reached the end of file, but we can
    // check this just to be sure.
    if (ferror(in))
    {
        perror("Error reading file");
    }


    // close the open file to recover resources
    fclose(in);

    // the end
    return 0;
}
