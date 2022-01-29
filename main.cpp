#include <iostream>
#include "Motus.h"

#define HEIGHT 6

int main(int argc, char const *argv[]) {
    Grid g;


    if(argc < 2)
        g = Grid();
    else
        g = Grid(HEIGHT, atoi(argv[1]));


    WordList wl = WordList(g._wlenght, "mots_fr.txt");
    
    string w = wl.randomWSize();

    g.writeAt(0, 0, w[0]);

    g.printGrid();


    return 0;
}
