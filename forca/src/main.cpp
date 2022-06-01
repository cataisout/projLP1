#include <iostream>
#include <fstream>
#include <locale.h>
#include "../include/forc.hpp"

using namespace std;



int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");

    string palavras = argv[1];
    string scores = argv[2];
    int dificuldade;

    Forca* jogo = new Forca();
    jogo->abertura(jogo->verifica_score(scores), jogo->verifica_palavras(palavras));
    
    int escolha = 2;
    while (escolha == 2){               // ***modularizar isso em uma função fora da classe Forca
        escolha = jogo->menu();
        if (escolha == 1)
            break;
        jogo->imprime_score(scores);
    }

    jogo->set_dificuldade(jogo->escolhe_dificuldade());







    return 0;
}
