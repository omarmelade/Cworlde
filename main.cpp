#include <iostream>
#include "Wordle.h"


void info()
{
    system("clear");
    cout << RED;
    cout << " ****     ****   *******   ********** **     **  ********" << endl;
    cout << NC;
    cout << "/" << RED << "**" << "/" << RED << "**   **" << NC << "/" << RED << "**  **" << NC
         << "/////" << RED << "**" << NC <<"/////" << RED << "**" << NC << "/// /" << RED << 
         "**    " << NC << "/" << RED << "** **" << NC << "////// " << endl;
    cout << NC;
    cout << "/" << RED << "**" << NC << "//" << RED <<"** ** " << NC <<"/" <<RED<< "** **     " <<NC<< "//" <<RED<< "**    " << 
            NC <<"/" << RED <<"**    " <<NC<< "/" <<RED<< "**    " <<NC<< "/" <<RED<< "**" <<NC<< "/" <<RED<<"**       " << endl;
    cout << NC;
    cout << "/" <<RED<< "** " <<NC<< "//" <<RED<< "***  " <<NC<< "/" <<RED<< "**" <<NC<< "/" <<RED<< "**      " <<NC<<"/"<<
        RED<<"**    "<<NC<<"/"<<RED<<"**    "<<NC<<"/"<<RED<<"**    "<<NC<<"/"<<RED<<"**"<<NC<<"/"<<RED<<"*********" << endl;
    cout << NC;
    cout << "/" <<RED<< "**  " <<NC<< "//" <<RED<< "*   "<<NC<<"/"<<RED<<"**"<<NC<<"/"<<RED<<"**      "<<NC<<"/"<<RED<<
        "**    "<<NC<<"/"<<RED<<"**    "<<NC<<"/"<<RED<<"**    "<<NC<<"/"<<RED<<"**"<<NC<<"////////"<<RED<<"**" << endl;
    cout << NC;
    cout << "/" <<RED<< "**   "<<NC<<"/    /"<<RED<<"**"<<NC<<"//"<<RED<<"**     **     "<<NC<<"/"<<RED<<"**    "<<NC<<
        "/"<<RED<<"**    "<<NC<<"/"<<RED<<"**       "<<NC<<"/"<<RED<<"**" << endl;
    cout << NC;
    cout << "/" <<RED<<"**        "<<NC<<"/"<<RED<<"** "<<NC<<"//"<<RED<<"*******      "<<NC<<"/"<<RED<<"**    "<<NC<<
        "//"<<RED<<"*******  ******** " << endl;
    cout << NC;
    cout << "//         //   ///////       //      ///////  ////////  " << endl;
    cout << NC;

    cout << " Bienvenu dans Motus/C++Wordle" << endl;
    cout << " Vous devez trouvez le mot et vous n'avez que 6 essais." << endl;
    cout << " Lorsque la lettre devient " << GRN << "verte" << NC << " elle est bien placée." << endl;
    cout << " Si elle devient " << RED << "rouge" << NC << " elle est mal placée." << endl;
    cout << " La couleur par defaut indique que la lettre n'est pas présente dans le mot." << endl;

}


void game(int wsize)
{  
    info();

    Game g = Game(wsize);
    int currentLine = 0;

    while( currentLine != HEIGHT)
    {
        g.printGrid();
        string gess;
        cin >> gess;
        g.guess(gess, currentLine);
        g._g.writeWord(currentLine, gess);   
        currentLine++;
    }

}


int main(int argc, char const *argv[]) {

    int wsize = WORDLENGHT;
    
    if(argc >= 2)
        wsize = atoi(argv[1]);
    
    game(wsize);

    return 0;
}


