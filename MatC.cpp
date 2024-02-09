#include <iostream>
#include <string>
#include "lexer.h"

using namespace std;

int main(int argc, char** argv){
    if (argc < 2){ printf("Usage: %s <filename>\n", argv[0]); exit(1); }
    string filename = argv[1];
    freopen(filename.c_str(), "r", stdin);
    token t;
    while((t = scan()) != t_eof){   
        cout << t << endl;
    }
    return 0;
}