#include "Wordle.h"


// ----------------- Utils fonctions

bool contains(string word, char c)
{
   
    for (size_t i = 0; i < word.size(); i++)
    {
        if(word[i] == c)
        {
            return true;
        }
    }
    return false;
}


string applyColor( int correctLetter )
{
    switch (correctLetter)
    {
    case 0:
        return RED;
        break;

    case 1:
        return GRN;
        break;

    default:
        return NC;
        break;
    }
}


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
Game::printGrid() const
{   

    std::cout << std::endl;
    for (int i = 0; i < this->_g._grid.size(); i++)
    {
        for (int j = 0; j < this->_g._grid[i].size(); j++)
        {   

            int correctLetter = this->_answers[i][j];
            cout << applyColor(correctLetter);
            if (j == 0)
                std::cout <<  "| " << this->_g._grid[i][j] << " |";
            else
                std::cout << " "  << this->_g._grid[i][j] << " |";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}





//// ------------------------  WordList Class

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


bool
WordList::wordExist( string guess )
{
    for (const string s : this->_wlist)
    {
        if(s == guess)
        {
            return true;
        }
    }
    return false;
}



/** @return a tab of int with :
  * -1 if the char is not in the word
  *  0 if the char is in the word but not here
  *  1 if the char is at the right place
*/
vector<int>
checkingWord( string guess, string word)
{
    int wSize = word.size();
    vector<int> answer;
    answer.resize(wSize);

    for (size_t i = 0; i < wSize; i++)
    {
        answer[i] = -1;

        if( word[i] == guess[i])
        {
            answer[i] = 1;
        }
        else if (contains(word, guess[i]))
        {
            answer[i] = 0;
        }
    }
    
    return answer;
}


// ------------------------ Game class

Game::Game( const int size) : _wordsize(size)
{
    // init grid and word list
    this->_g = Grid(HEIGHT, size);
    this->_wl = WordList(this->_g._wlenght, "mots_fr.txt");

    // init answers vect
    vector<int> v;
    v.assign(this->_g._wlenght, -1);
    this->_answers.assign(HEIGHT, v);

    init();
}

void
Game::init()
{   
    string w = this->_wl.randomWSize();
    this->targetW = w;
    //cout << targetW;
    _g.writeAt(0, 0, w[0]);
}

void 
Game::guess( string guess, int line)
{
    if( guess.size() == this->_wordsize )
    {
        vector<int> answ = checkingWord(guess, this->targetW);
        this->_answers.at(line) = answ;

        // for (size_t i = 0; i < this->_wordsize; i++)
        // {
        //     cout << answ[i] << " ";
        // }
        // cout << endl;
    }
    else
    {
        cerr << "Le mot ne fait pas la bonne taille !";
    }
}



