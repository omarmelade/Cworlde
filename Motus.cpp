#include "Motus.h"

//// ------------------------ Grid Class

Grid::Grid(const int line, const int col):  _gridlenght( line ), _wlenght( col )
{   
    srand(time(0));

    for (int i = 0; i < this->_gridlenght; i++)
    {
        vector<string> row;
        for (int j = 0; j < this->_wlenght; j++)
        {   
            if (j == 0)
                row.push_back("_");
            else
                row.push_back("_");
        }
        this->_grid.push_back(row);
    }
}


void 
Grid::writeAt(int li, int col, char letter)
{
    this->_grid[li][col] = letter;
}


string 
Grid::readAt(int li, int col)
{
    return this->_grid.at(li).at(col);
}

void 
Grid::writeWord(int li, string word)
{

    if(word.size() == this->_grid.at(li).size())
    {
        for( int i = 0; i < word.size(); i++)
        {
            this->_grid.at(li).at(i) = word[i];
        } 
    }

}


void 
Grid::printGrid() const
{
    std::cout << std::endl;
    for (int i = 0; i < this->_grid.size(); i++)
    {
        for (int j = 0; j < this->_grid[i].size(); j++)
        {
            if (j == 0)
                std::cout << "| " << this->_grid[i][j] << " |";
            else
                std::cout << " "  << this->_grid[i][j] << " |";
        }   
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void
WordList::read( string filename )
{
    std::ifstream input( filename );
    int nbW = 0;
    if ( !input.good() ) {
        std::cerr << "ERROR" << std::endl;
    }else{
        string str;

        while(getline(input, str))
        {
            string word;
            std::istringstream iss(str);

            iss >> word;
            
            nbW++;
            _wlist.push_back(word);
        }
    }

    // std::cout << "nb word : " << nbW << std::endl;
    // std::cout << "size _wlist : " << _wlist.size() << std::endl;
}

string
WordList::randomW() const
{
    
    return  _wlist.at(rand() % _wlist.size());
}

string
WordList::randomWSize() const
{   
    string w = _wlist.at(rand() % _wlist.size());
    while( w.size() != _wsize)
    {
        
        w = _wlist.at(rand() % _wlist.size());
    }

    return  w;
}
