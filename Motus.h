#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>


using namespace std;

// colors
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"


#define HEIGHT 6
#define WORDLENGHT 6


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
    

};




struct WordList
{
    string _w;
    int _wsize;

    vector<string> _wlist;
    
    WordList(const int size, string file = "mots_fr.txt" ) : _wsize(size) { read(file); };

    // read a file and store the words in _wlist
    void read( string filename );

    bool wordExist( string guess );

    // @return random word
    string randomW() const;
    string randomWSize() const;

};


struct Game
{
    Grid _g;
    WordList _wl = WordList(HEIGHT);
    
    vector<vector<int>> _answers;

    int _wordsize;
    string targetW;

    Game( const int size );

    void init();
    void guess( string guess, int line);

    // print the grid
    void printGrid() const;
};
