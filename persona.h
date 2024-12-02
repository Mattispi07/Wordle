#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
using namespace std;
class persona{
public:
    string username;
    int punteggio;
    string naz;
    int naz1;
    persona(string,int,string);
    persona(string,int,int);
};


#endif // PERSONA_H_INCLUDED
