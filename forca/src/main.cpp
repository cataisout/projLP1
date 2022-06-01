#include <iostream>
#include <fstream>
#include <locale.h>
#include "../include/forc.hpp"

using namespace std;



int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");

    string palavras = argv[1];
    string scores = argv[2];


    Forca* jogo = new Forca(palavras, scores);
 
    jogo->abertura(jogo->verifica_score(), jogo->verifica_palavras());
    
    int escolha = 2;
    while (escolha == 2){               // ***modularizar isso em uma função fora da classe Forca
        escolha = jogo->menu();
        if (escolha == 1)
            break;
        jogo->imprime_score();
    }

    jogo->escolhe_dificuldade();
    
    string dificuldade;
    dificuldade = jogo->get_dificuldade();
    cout << dificuldade;




    return 0;
}
