#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include <string>
#include <vector>
#include "persona.h"
using namespace std;
/*
class persona{
public:
    string username;
    int punteggio;
    persona(string,int);
};
*/
class Record{
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


#endif // RECORD_H_INCLUDED
