#ifndef RECORDFACILE_H_INCLUDED
#define RECORDFACILE_H_INCLUDED
#include <string>
#include <vector>
#include "persona.h"
using namespace std;
/*
class persona1{
public:
    string username;
    int punteggio;
    persona(string,int);
};
*/
class recordFacile{
public:
    //vector<string> record1;
    int NRecord=1;
    //vector<int> vector1;
    vector<persona> record1;
    /*
    String Username;
    int punteggio;

    */

    string a;
    void record();
    void StampaRecord(string,int,int);
};

#endif // RECORDFACILE_H_INCLUDED
