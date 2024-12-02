#include "recordDifficile.h"
#include <iostream>
#include "parola.h"
#include <cstdio>
#include <string>
#include <string.h>
#include <fstream>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <conio.h>
#include "persona.h"
using namespace std;

void recordDifficile::record(){
    fstream file1("recordDifficile.txt");
    string N;
    getline(file1,N);
    NRecord=std::stoi(N);
    string myText;
    for(int i=0; i<NRecord; i++){
        getline(file1,myText);
        string N1;
        getline(file1,N1);
        int n=std::stoi(N1);
        string na;
        getline(file1,na);
        int n2=std::stoi(na);
        record1.push_back(persona(myText,n,n2));
        /*
        if(na=="ITA")
            record1.push_back(persona(myText,n,1));
        else if(na=="ING")
            record1.push_back(persona(myText,n,2));
        else if(na=="SPA")
            record1.push_back(persona(myText,n,3));
            */
    }
    file1.close();
}
void recordDifficile::StampaRecord(string b, int p, int n){
    /*
    string nazionalita="";
    switch(n){
    case 1:
        nazionalita="ITA";
    case 2:
        nazionalita="ING";
    case 3:
        nazionalita="SPA";
    }
    */
    fstream file1("recordDifficile.txt");
    int counts=-3;
    for(int i=0; i<NRecord; i++){
        if(b==record1[i].username)
            counts=i;
    }
    if(counts==-3){
        record1.push_back(persona(b,p,n));
        NRecord++;
    }
    else{
        if(record1[counts].punteggio<p)
            record1[counts].punteggio=p;
    }
    file1<<NRecord<<endl;
    for (const auto& record1 : record1) {
        file1<<record1.username<<endl;
        file1<<record1.punteggio<<endl;
        file1<<record1.naz1<<endl;
    }
    NRecord=0;
    file1.close();

}


