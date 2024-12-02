#include <iostream>
#include "parola.h"
#include <cstdio>
#include <string>
#include <fstream>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
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
//#include "Record.h"
using namespace std;

int main()
{
    while(true){

        cout<<endl;
        cout<<endl;
        cout<<endl;
        printf("%s",BIANCO);
        cout<<"                                    _     _  _______  ______    ______   ___      _______ \n";
        Sleep(100);
        printf("%s",GIALLO_G);
        cout<<"                                   | | _ | ||       ||    _ |  |      | |   |    |       |\n";
        Sleep(100);
        printf("%s",ROSSO);
        cout<<"                                   | || || ||   _   ||   | ||  |  _    ||   |    |    ___|\n";
        Sleep(100);
        printf("%s",ROSA);
        cout<<"                                   |       ||  | |  ||   |_||_ | | |   ||   |    |   |___ \n";
        Sleep(100);
        printf("%s",VERDE);
        cout<<"                                   |       ||  |_|  ||    __  || |_|   ||   |___ |    ___|\n";
        Sleep(100);
        printf("%s",AZZURRO);
        cout<<"                                   |   _   ||       ||   |  | ||       ||       ||   |___ \n";
        Sleep(100);
        printf("%s",BLU);
        cout<<"                                   |__| |__||_______||___|  |_||______| |_______||_______|\n";
        Sleep(2500);
        printf("%s",BIANCO);
        cout<<"                                                                                                     caricamento...\n";
        Sleep(1000);
        cout<<endl;
        cout<<endl;
        cout<<endl;
        system("pause");
        Sleep(750);
        system("cls");
    /*
        cout<<"$$\      $$\  $$$$$$\  $$$$$$$\  $$$$$$$\  $$\       $$$$$$$$\ \n";
        cout<<"$$ | $\  $$ |$$  __$$\ $$  __$$\ $$  __$$\ $$ |      $$  _____|\n";
        cout<<"$$ |$$$\ $$ |$$ /  $$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |\n";
        cout<<"$$ $$ $$\$$ |$$ |  $$ |$$$$$$$  |$$ |  $$ |$$ |      $$$$$\\n";
        cout<<"$$$$  _$$$$ |$$ |  $$ |$$  __$$< $$ |  $$ |$$ |      $$  __|\n";
        cout<<"$$$  / \$$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |\n";
        cout<<"$$  /   \$$ | $$$$$$  |$$ |  $$ |$$$$$$$  |$$$$$$$$\ $$$$$$$$\\n";
        cout<<"\__/     \__| \______/ \__|  \__|\_______/ \________|\________|\n";
        cout<<endl; */

        string ParolaVera;
        int N_Vera=0;
        Parola(ParolaVera,N_Vera);
    }
    return 0;
}
//luchezza parola per controllo
