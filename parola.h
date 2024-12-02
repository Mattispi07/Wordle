#ifndef PAROLA_H_INCLUDED
#define PAROLA_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
class Parola{
private:
    string ParolaMia;
    char L[1];
    int N_Vera;
    int Lunghezza_File=49;
    vector<string> parole;
    int Punteggio=0;
    int crediti=0;
    string Username;
    int Lingua=1;
    int Mod=0;
    bool ModNotte=true;
    int tentativi;
public:
    string ParolaVera;
    void PrendiLettera();
    void InserisciLettera(int);
    void ControllaLettera();
    void StampaParola();
    void ControllaParola();
    void Vittoria();
    Parola(string,int);
    void Inizializza_Parola();
    void GeneraParola();
    void CreaVettore();
    void LeggiComando();
    void letteraCredito();
    void StampaMenu();
    void toString();
    void istruzioni();
    void InsMod();
    void mod_notte();
};

#endif // PAROLA_H_INCLUDED
