#include <iostream>
#include "parola.h"
#include "Record.h"
#include "recordFacile.h"
#include "recordDifficile.h"
#include <cstdio>
#include <string>
#include <fstream>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <conio.h>
//colori
#define VERDE "\x1B[38;5;48m"
#define ROSA "\x1B[38;5;129m"
#define BLU "\x1B[38;5;27m"
#define GRIGIO "\x1B[38;5;146m"
#define ROSSO "\x1B[38;5;196m"
#define AZZURRO "\x1B[38;5;123m"
#define GIALLO_G "\x1B[38;5;220m"
#define ROSSO_G "\x1B[38;5;160m"
#define BIANCO "\x1B[38;5;255m"
#define NERO "\x1B[38;5;0m"
#define RESET "\x1B[0m"
using namespace std;
//ISTANZA RECORD;
Record rMedio;
recordFacile rFacile;
recordDifficile rDifficile;

void Parola::CreaVettore(){
    system("cls");
    printf("%s",BLU);
    cout<<"                                                          REGISTRATI"<<endl;
    mod_notte();
    cout<<"Dimmi il tuo Username:";
    cin>>Username;
    cout<<endl<<"Seleziona la lingua:"<<endl<<"1) Italiano"<<endl<<"2) Inglese"<<endl<<"3)Spagnolo"<<endl;
    cin>>Lingua;
    while(!cin.good() || Lingua<=0 || Lingua>3){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<endl<<"ATTENZIONE..."<<endl;
        Sleep(200);
        cout<<"Errore..."<<endl;
        Sleep(200);
        system("cls");
        CreaVettore();
    }
    system("cls");
//
    if(Mod==1 && Lingua==1){
        string parola;
        ifstream inputFile("InpFacile.txt");
        while(inputFile >> parola){
            parole.push_back(parola);
        }
        inputFile.close();
    }
    else if(Mod==2 && Lingua==1){
        string parola;
        ifstream inputFile("input.txt");
        while(inputFile >> parola){
            parole.push_back(parola);
        }
        inputFile.close();
    }
    else if(Mod==3 && Lingua==1){
        string parola;
        ifstream inputFile("input.txt");
        while(inputFile >> parola){

            parole.push_back(parola);
        }
        inputFile.close();
    }
    else if(Lingua==2){
            string parola;
        ifstream inputFile("InpInglese.txt");
        while(inputFile >> parola){

            parole.push_back(parola);
        }
        inputFile.close();
    }
    else if(Lingua==3){
            string parola;
        ifstream inputFile("InpSpagnolo.txt");
        while(inputFile >> parola){

            parole.push_back(parola);
        }
        inputFile.close();
    }
//
/*
        string parola;
        ifstream inputFile("input.txt");
        while(inputFile >> parola){
            parole.push_back(parola);
        }

        inputFile.close();
*/
    Inizializza_Parola();
}
void Parola::GeneraParola(){
    srand(time(0));
    int i = rand() % Lunghezza_File;
    ParolaVera=parole[i];
    parole.erase(parole.begin() + i);
    Lunghezza_File--;
    if(Mod==1)
        crediti=(ParolaVera.size()/3);
    if(Mod==3)
        tentativi=(ParolaVera.size()/2);
}
void Parola::PrendiLettera(){
    if(Lingua==1)
        cout<<"Dimmi una lettera:";
    else if(Lingua==2)
        cout<<"Tell me a letter:";
    else if(Lingua==3)
        cout<<"Dime una carta:";

    cin>>L;
    cout<<endl;
    ControllaLettera();
}
void Parola::ControllaLettera(){
    if(Mod==3){
        if(tentativi==0){
            Sleep(100);
            if(Lingua==1){
                cout<<"Hai superato i tentativi massimi"<<endl;
                cout<<"Il gioco verra' riavviato"<<endl;
                Sleep(1000);
                cout<<"                                                                             caricamento..."<<endl;
            }
            else if(Lingua==2){
                cout<<"You have exceeded the maximum attempts"<<endl;
                cout<<"The game will restart"<<endl;
                Sleep(1000);
                cout<<"                                                                             loading..."<<endl;
            }
            else if(Lingua==3){
               cout<<"Has superado el máximo de intentos."<<endl;
                cout<<"El juego se reiniciará"<<endl;
                Sleep(1000);
                cout<<"                                                                             cargando..."<<endl;
            }
            Sleep(500);
            system("cls");
            rDifficile.StampaRecord(Username,Punteggio,Lingua);
            Parola(ParolaMia,Lunghezza_File);
        }
    }
    if(L[0]=='1')
        if(crediti>0)
            letteraCredito();
        else{
            cout<<endl;
            if(Lingua==1){
                cout<<"Credito non sufficente"<<endl;
            }
            else if(Lingua==2){
                cout<<"Not enough credit"<<endl;
            }
            else if(Lingua==3){
                cout<<"No hay suficiente crédito"<<endl;
            }
            Sleep(500);
            system("cls");
            StampaParola();
        }
    else if(L[0]=='2'){
            if(Mod!=3){
                GeneraParola();
                Inizializza_Parola();
            }
            else{
                cout<<endl;
                if(Lingua==1){
                    cout<<"Funzionalita' non disponibile per la modalita' difficile"<<endl;
                }
                else if(Lingua==2){
                    cout<<"Feature not available for hard mode"<<endl;
                }
                else if(Lingua==3){
                    cout<<"Característica no disponible para el modo difícil"<<endl;
                }
                Sleep(500);
                system("cls");
                StampaParola();
            }
    }
    int letteraParola=0;
    for(int i=0; i<ParolaVera.size(); i++){
        if(L[0]==ParolaVera[i]){
            InserisciLettera(i);
            letteraParola++;
        }
    }
    if(Mod==3)
        if(letteraParola==0)
            tentativi-=1;

    ControllaParola();
    StampaParola();
}
void Parola::InserisciLettera(int i){
    ParolaMia[i]=ParolaVera[i];
}
void Parola::letteraCredito(){
    crediti--;
    int i=0;
    while(ParolaMia[i]!='?')
        i++;
    ParolaMia[i]=ParolaVera[i];
}
void Parola::StampaParola(){
    system("cls");
        cout<<"                          _     _  _______  ______    ______   ___      _______ \n";
        printf("%s",GIALLO_G);
        cout<<"                         | | _ | ||       ||    _ |  |      | |   |    |       |\n";
        printf("%s",ROSSO);
        cout<<"                         | || || ||   _   ||   | ||  |  _    ||   |    |    ___|\n";
        printf("%s",ROSA);
        cout<<"                         |       ||  | |  ||   |_||_ | | |   ||   |    |   |___ \n";
        printf("%s",VERDE);
        cout<<"                         |       ||  |_|  ||    __  || |_|   ||   |___ |    ___|\n";
        printf("%s",AZZURRO);
        cout<<"                         |   _   ||       ||   |  | ||       ||       ||   |___ \n";
        printf("%s",BLU);
        cout<<"                         |__| |__||_______||___|  |_||______| |_______||_______|\n";
        printf("%s",BIANCO);
    mod_notte();
    if(Lingua==1){
        cout<<"                                                                                                 PUNTEGGIO:"<<Punteggio<<endl;
        cout<<"                                                                                                 CREDITO:"<<crediti<<endl;
        if(Mod==3)
            cout<<"                                                                                                 TENTATIVI:"<<tentativi<<endl;
    }
    else if(Lingua==2){
        cout<<"                                                                                                 SCORE:"<<Punteggio<<endl;
        cout<<"                                                                                                 CREDIT:"<<crediti<<endl;
        if(Mod==3)
            cout<<"                                                                                                 ATTEMPTS:"<<tentativi<<endl;
    }
    else if(Lingua==3){
        cout<<"                                                                                                 PUNTAJE:"<<Punteggio<<endl;
        cout<<"                                                                                                 CRÉDITO:"<<crediti<<endl;
        if(Mod==3)
            cout<<"                                                                                                 INTENTOS:"<<tentativi<<endl;
    }
    cout<<endl<<"                                                ";
    for(int i=0; i<ParolaVera.size(); i++)
        cout<<ParolaMia[i]<<"  ";
    cout<<endl;
    PrendiLettera();
}
void Parola::ControllaParola(){
    int a=0;
    for(int i=0; i<ParolaVera.size(); i++){
        if(ParolaMia[i]=='?')
            a++;
    }
    if(a==0)
        Vittoria();
}
void Parola::Vittoria(){
    crediti++;
    Punteggio++;
    printf("%s",GIALLO_G);
    if(Lingua==1)
        cout<<"                                                   HAI VINTO!!"<<endl;
    else if(Lingua==2)
        cout<<"                                                   YOU WON!!"<<endl;
    else if(Lingua==2)
        cout<<"                                                   ¡¡GANASTE!!"<<endl;
    cout<<"                                                  ";
    mod_notte();
    for(int i=0; i<ParolaVera.size(); i++)
        cout<<ParolaMia[i]<<"  ";
    cout<<endl;
    //exit(1);
    LeggiComando();
    Inizializza_Parola();
}
Parola::Parola(string a, int N){
    //r.record();
    //CreaVettore();
    InsMod();
}
void Parola::Inizializza_Parola(){
    GeneraParola();
    /*
    cout<<"                                               INDOVINA LA PAROLA                  PUNTEGGIO:"<<Punteggio<<endl;
    cout<<"                                                                                   CREDITO:"<<crediti<<endl;
    */
    for(int i=0; i<ParolaVera.size(); i++)
        ParolaMia[i]='?';


    StampaParola();

}
void Parola::LeggiComando(){
    char ch;
    while (true) {
        if(Lingua==1)
            cout<<"                                 Premi Esc per uscire, INVIO per continuare, + per menu'"<<endl;
        else if(Lingua==2)
            cout<<"                                 Press Esc to exit, ENTER to continue, + to menu"<<endl;
        else if(Lingua==3)
            cout<<"                                 Presione Esc para salir, ENTER para continuar, + para ir al menú"<<endl;
        ch = _getch(); // Legge il carattere premuto
        if (ch == 27) { // 27 è il codice ASCII per ESC
            if(Lingua==1){
                cout<<Username<<" "<<Punteggio<<endl;
                system("cls");
                cout << "Hai premuto ESC"<<endl;
                Sleep(300);
                cout<<"SALVATAGGIO IN CORSO...."<<endl;
                Sleep(300);
                cout<<endl<<"USCITA..."<<endl;
            }
            else if(Lingua==2){
                cout<<Username<<" "<<Punteggio<<endl;
                system("cls");
                cout << "You pressed ESC"<<endl;
                Sleep(300);
                cout<<"RESCUE IN PROGRESS...."<<endl;
                Sleep(300);
                cout<<endl<<"EXIT..."<<endl;
            }
            else if(Lingua==3){
                cout<<Username<<" "<<Punteggio<<endl;
                system("cls");
                cout << "Presionaste ESC"<<endl;
                Sleep(300);
                cout<<"RESCATE EN CURSO...."<<endl;
                Sleep(300);
                cout<<endl<<"SALIDA..."<<endl;
            }
            if(Mod==1)
                rFacile.StampaRecord(Username,Punteggio,Lingua);
            else if(Mod==2)
                rMedio.StampaRecord(Username,Punteggio,Lingua);
            else if(Mod==3)
                rDifficile.StampaRecord(Username,Punteggio,Lingua);

            abort();
        } else if (ch == 43) { // 13 è il codice ASCII per INVIO
            if(Lingua==1)
                cout << "Vai al menu. Continua...\n";
            if(Lingua==2)
                cout << "Go to the menu. Continues...\n";
            if(Lingua==3)
                cout << "Ir al menú. Continúa...\n";
            system("cls");
            StampaMenu();
        }
         else if (ch == 13) { // 13 è il codice ASCII per INVIO()
            if(Lingua==1)
                cout << "Hai premuto INVIO. Continua...\n";
            else if(Lingua==2)
                cout << "You pressed ENTER. Continues...\n";
            else if(Lingua==3)
                cout << "Presionaste ENTER. Continúa...\n";
            system("cls");
            Inizializza_Parola();
        }
    }
}
void Parola::StampaMenu(){
    system("cls");
    if(Lingua==1){
        printf("%s",VERDE);
        cout<<"                                                         MENU'"<<endl;
        mod_notte();
        cout<<"                                                   1-Torna al Gioco"<<endl;
        cout<<"                                                  2-Ripristina Gioco"<<endl;
        cout<<"                                                  3-Cambio Font Schermo Notte"<<endl;
        cout<<"                                                  4-Cambio Font Schermo Giorno"<<endl;
        cout<<"                                                  5-Stampa Risultato"<<endl;
        cout<<"                                                  6-Istruzioni"<<endl;
        cout<<"                                                  7-Stampa Record"<<endl;
        cout<<"                                                  8-Esci"<<endl;
    }
    else if(Lingua==2){
        printf("%s",VERDE);
        cout<<"                                                         MENU'"<<endl;
        mod_notte();
        cout<<"                                                  1-Return to the Game"<<endl;
        cout<<"                                                  2-Reset Game"<<endl;
        cout<<"                                                  3-Changing Night Screen Font"<<endl;
        cout<<"                                                  4-Day Screen Font Change"<<endl;
        cout<<"                                                  5-Print Result"<<endl;
        cout<<"                                                  6-Instructions"<<endl;
        cout<<"                                                  7-Print Record"<<endl;
        cout<<"                                                  8-Exit"<<endl;
    }
    else if(Lingua==2){
        printf("%s",VERDE);
        cout<<"                                                         MENU'"<<endl;
        mod_notte();
        cout<<"                                                  1-Regresar al juego"<<endl;
        cout<<"                                                  2-Reiniciar juego"<<endl;
        cout<<"                                                  3-Cambiar la fuente de la pantalla nocturna"<<endl;
        cout<<"                                                  4-Cambio de fuente de pantalla de día"<<endl;
        cout<<"                                                  5-Imprimir resultado"<<endl;
        cout<<"                                                  6-Instrucciones"<<endl;
        cout<<"                                                  7-Imprimir registro"<<endl;
        cout<<"                                                  8-Salida"<<endl;
    }
    cout<<"                                                                ";
    cout<<endl;
    int a=0;
    cin>>a;
    switch(a){
        case 1:
            system("cls");
            Inizializza_Parola();
        case 2:
            cout<<Username<<" "<<Punteggio<<endl;
            system("cls");
            Parola(ParolaMia,Lunghezza_File);
        case 3:
            system("color 0F");
            mod_notte();
            system("pause");
            system("cls");
            ModNotte=true;
            StampaMenu();
        case 4:
            system("color F0");
            mod_notte();
            system("pause");
            ModNotte=false;
            system("cls");

            StampaMenu();
        case 5:
            toString();
            system("pause");
            system("cls");
            StampaMenu();
        case 6:
            istruzioni();
            system("pause");
            system("cls");
            StampaMenu();
        case 7:
            system("cls");
            printf("%s",VERDE);
            cout<<"                                                      RECORD"<<endl;
            mod_notte();
            if(Mod==1){
                for(int i=0; i<rFacile.NRecord; i++){
                    string nazionalita;
                    //cout<<rFacile.record1[i].naz1<<endl;
                    if(rFacile.record1[i].naz1==1)
                        nazionalita="ITA";
                    else if(rFacile.record1[i].naz1==2)
                        nazionalita="ING";
                    else
                        nazionalita="SPA";

                    if(rFacile.record1[i].username==Username){
                        printf("%s",GIALLO_G);
                        cout<<"Username:"<<rFacile.record1[i].username
                        <<" "<<nazionalita
                        <<" Punteggio:"<<rFacile.record1[i].punteggio<<endl;
                        mod_notte();
                    }
                    else{
                    cout<<"Username:"<<rFacile.record1[i].username
                    <<" "<<nazionalita
                    <<" Punteggio:"<<rFacile.record1[i].punteggio<<endl;
                    }
                }
            }
            else if(Mod==2){
                for(int i=0; i<rMedio.NRecord; i++){
                    string nazionalita;
                    //cout<<rFacile.record1[i].naz1<<endl;
                    if(rMedio.record1[i].naz1==1)
                        nazionalita="ITA";
                    else if(rMedio.record1[i].naz1==2)
                        nazionalita="ING";
                    else
                        nazionalita="SPA";
                    if(rMedio.record1[i].username==Username){
                        printf("%s",GIALLO_G);
                        cout<<"Username:"<<rMedio.record1[i].username
                        <<" "<<nazionalita
                        <<" Punteggio:"<<rMedio.record1[i].punteggio<<endl;
                        mod_notte();
                    }
                    else{
                        cout<<"Username:"<<rMedio.record1[i].username
                        <<" "<<nazionalita
                        <<" Punteggio:"<<rMedio.record1[i].punteggio<<endl;
                    }
                }
            }
            else if(Mod==3){
                for(int i=0; i<rDifficile.NRecord; i++){
                    string nazionalita;
                    //cout<<rFacile.record1[i].naz1<<endl;
                    if(rDifficile.record1[i].naz1==1)
                        nazionalita="ITA";
                    else if(rDifficile.record1[i].naz1==2)
                        nazionalita="ING";
                    else
                        nazionalita="SPA";
                    if(rDifficile.record1[i].username==Username){
                        printf("%s",GIALLO_G);
                        cout<<"Username:"<<rDifficile.record1[i].username
                        <<" "<<nazionalita
                        <<" Punteggio:"<<rDifficile.record1[i].punteggio<<endl;

                        mod_notte();
                    }
                    else{
                        cout<<"Username:"<<rDifficile.record1[i].username
                        <<" "<<nazionalita
                        <<" Punteggio:"<<rDifficile.record1[i].punteggio<<endl;
                    }

                }
            }
            system("pause");
            system("cls");
            StampaMenu();

        case 8:
            if(Lingua==1)
                cout<<endl<<endl<<endl<<"SALVATAGGIO IN CORSO"<<endl;
            else if(Lingua==2)
                cout<<endl<<endl<<endl<<"RESCUE IN PROGRESS"<<endl;
            else if(Lingua==1)
                cout<<endl<<endl<<endl<<"RESCATE EN CURSO"<<endl;
            if(Mod==1)
                rFacile.StampaRecord(Username,Punteggio,Lingua);
            else if(Mod==2)
                rMedio.StampaRecord(Username,Punteggio,Lingua);
            else if(Mod==3)
                rDifficile.StampaRecord(Username,Punteggio,Lingua);
            system("cls");

            abort();
    }
}
void Parola::toString(){
    cout<<"                                     Username:"<<Username<<" Punteggio:"<<Punteggio<<endl;
}
void Parola::istruzioni(){
    system("cls");
    printf("%s",AZZURRO);
    if(Lingua==1){
        cout<<"                                                     ISTRUZIONI"<<endl<<endl;
        mod_notte();
        cout<<"1 -Digita per avere un aiuto"<<endl;
        cout<<"2 -Digita per cambiare parola"<<endl;
    }
    else if(Lingua==2){
        cout<<"                                                     INSTRUCTIONS"<<endl<<endl;
        mod_notte();
        cout<<"1 -Type for help"<<endl;
        cout<<"2 -Type to change word"<<endl;
    }
    else if(Lingua==3){
        cout<<"                                                     INSTRUCCIONES"<<endl<<endl;
        mod_notte();
        cout<<"1 -Escribe para obtener ayuda"<<endl;
        cout<<"2 -Escribe para cambiar la palabra"<<endl;
    }
    system("pause");
    StampaMenu();

}
void Parola::InsMod(){
    printf("%s",ROSSO_G);
    if(Lingua==1){
        cout<<"                                                    SCEGLI LA MODALITA'"<<endl;
       /*
        cout<<"                                         ╔═╗╔═╗╔═╗╔═╗╦  ╦  ╦  ╔═╗  ╔╦╗╔═╗╔╦╗╔═╗╦  ╦╔╦╗╔═╗"<<endl;
        cout<<"                                         ╚═╗║  ║╣ ║ ╦║  ║  ║  ╠═╣  ║║║║ ║ ║║╠═╣║  ║ ║ ╠═╣"<<endl;
        cout<<"                                         ╚═╝╚═╝╚═╝╚═╝╩═╝╩  ╩═╝╩ ╩  ╩ ╩╚═╝═╩╝╩ ╩╩═╝╩ ╩ ╩ ╩"<<endl;
        */
        mod_notte();
        cout<<endl;
        cout<<"MOD 1: FACILE"<<endl;
        cout<<"-Crediti = Lunghezza parola / 3"<<endl;
        cout<<"-Parole facili"<<endl<<endl;
        cout<<"MOD 2: MEDIA"<<endl;
        cout<<"-Parola medie"<<endl<<endl;
        cout<<"MOD 3: DIFFICILE"<<endl;
        cout<<"-Parole medie"<<endl;
        cout<<"-Tentativi = Lunghezza parola / 2"<<endl<<endl;
    }
    else if(Lingua==2){
        cout<<"                                                    CHOOSE THE MODE"<<endl;
       /*
        cout<<"                                         ╔═╗╔═╗╔═╗╔═╗╦  ╦  ╦  ╔═╗  ╔╦╗╔═╗╔╦╗╔═╗╦  ╦╔╦╗╔═╗"<<endl;
        cout<<"                                         ╚═╗║  ║╣ ║ ╦║  ║  ║  ╠═╣  ║║║║ ║ ║║╠═╣║  ║ ║ ╠═╣"<<endl;
        cout<<"                                         ╚═╝╚═╝╚═╝╚═╝╩═╝╩  ╩═╝╩ ╩  ╩ ╩╚═╝═╩╝╩ ╩╩═╝╩ ╩ ╩ ╩"<<endl;
        */
        mod_notte();
        cout<<endl;
        cout<<"MOD 1: EASY"<<endl;
        cout<<"-Credits = Word Length / 3"<<endl;
        cout<<"-Easy words"<<endl<<endl;
        cout<<"MOD 2: AVERAGE"<<endl;
        cout<<"-Word mediums"<<endl<<endl;
        cout<<"MOD 3: DIFFICULT"<<endl;
        cout<<"-Word mediums"<<endl;
        cout<<"-Attempts = Word length / 2"<<endl<<endl;
    }
    else if(Lingua==3){
        cout<<"                                                    ELIGE EL MODO"<<endl;
       /*
        cout<<"                                         ╔═╗╔═╗╔═╗╔═╗╦  ╦  ╦  ╔═╗  ╔╦╗╔═╗╔╦╗╔═╗╦  ╦╔╦╗╔═╗"<<endl;
        cout<<"                                         ╚═╗║  ║╣ ║ ╦║  ║  ║  ╠═╣  ║║║║ ║ ║║╠═╣║  ║ ║ ╠═╣"<<endl;
        cout<<"                                         ╚═╝╚═╝╚═╝╚═╝╩═╝╩  ╩═╝╩ ╩  ╩ ╩╚═╝═╩╝╩ ╩╩═╝╩ ╩ ╩ ╩"<<endl;
        */
        mod_notte();
        cout<<endl;
        cout<<"MOD 1: FÁCIL"<<endl;
        cout<<"-Créditos = Longitud de la palabra / 3"<<endl;
        cout<<"-Palabras fáciles"<<endl<<endl;
        cout<<"MOD 2: PROMEDIO"<<endl;
        cout<<"-Medios de palabras"<<endl<<endl;
        cout<<"MOD 3: DIFÍCIL"<<endl;
        cout<<"-Medios de palabras"<<endl;
        cout<<"-Intentos = Longitud de palabra / 2"<<endl<<endl;
    }
    int N;
    cin>>N;
    if(N<1 || N>3){
        Sleep(100);
        if(Lingua==1){
            cout<<"ERRORE!"<<endl;
            cout<<"Modalita' non esistente"<<endl;
        }
        else if(Lingua==2){
            cout<<"ERROR!"<<endl;
            cout<<"Non-existent mode"<<endl;
        }
        else if(Lingua==3){
            cout<<"¡ERROR!"<<endl;
            cout<<"Modo inexistente"<<endl;
        }
        Sleep(1000);
        system("cls");
        InsMod();
    }
    Mod=N;
    cout<<endl<<endl<<endl<<endl<<endl;
    if(Lingua==1)
        cout<<"                                                                                             caricamento..."<<endl;
    else if(Lingua==2)
        cout<<"                                                                                             loading..."<<endl;
    else if(Lingua==3)
        cout<<"                                                                                             cargando..."<<endl;
    Sleep(1000);

    if(Mod==1)
        rFacile.record();
    else if(Mod==2)
        rMedio.record();
    else if(Mod==3)
        rDifficile.record();

    CreaVettore();
}
void Parola::mod_notte(){
    if(ModNotte==true)
        printf("%s",BIANCO);
    else
        printf("%s",NERO);
}
/*
    string a=to_string(punteggio);
    string Record1=Nome+" "+Cognome+" "+a;
*/
