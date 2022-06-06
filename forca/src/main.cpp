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
    system("Color 0A");
    jogo->abertura(jogo->verifica_score(), jogo->verifica_palavras());
    
    int escolha = 2;
    while (escolha == 2){               // ***modularizar isso em uma função fora da classe Forca
        escolha = jogo->menu();
        system("cls");
        if (escolha == 1){
          system("cls"); 
          break;
          }
        jogo->imprime_score();
    }
    jogo->escolhe_dificuldade();
    jogo->carrega_palavras();
    jogo->sorteia_palavra();
    int erros = 0;
    int pontos = 0;
    

    system("cls");
    while (erros < 6) {
      erros = jogo->get_erros();
      jogo->imprime_boneco();
      cout << endl;
      jogo->imprime_secreta();
      pontos = jogo->get_pontos();
      cout << "Pontos: " << pontos << endl;
      if(erros > 5){
        cout << "\n\nO jogo acabou, a palavra era ";
        string a = jogo->get_secreta();
        cout << a;
        break;
      }
      if(jogo->condicao_vitoria() == true ){
        cout << "Voce venceu! A palavra era " << jogo->get_secreta()<<endl;
        cout << "Pontuacao final: " << jogo->get_pontos() << endl;

        break;
      } 
      jogo->le_chute(); 
      system("cls");
    }
    
  
  }  
