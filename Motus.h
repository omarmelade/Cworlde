#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>


using namespace std;

#define HEIGHT 6
#define WORDLENGHT 10


struct Grid 
{
    // numbers of letters depending on the word
    int _wlenght; // column
    int _gridlenght; // line

    // grid
    vector<vector<string>> _grid;

    Grid( const int line = HEIGHT, const int col = WORDLENGHT );


    void writeAt(int li, int col, char letter);
    // @return the string at the indexes
    string readAt(int li, int col);

    // write a word in the line
    void writeWord(int li, string word);
    
    // print the grid
    void printGrid() const;
};


struct WordList
{
    string _w;
    int _wsize;

    vector<string> _wlist;

    WordList(const int size) : _wsize(size) {};
    WordList(const int size, string file = "mots_fr.txt" ) : _wsize(size) { read(file);};

    // read a file and store the words in _wlist
    void read( string filename );

    // @return random words
    string randomW() const;
    string randomWSize() const;

};