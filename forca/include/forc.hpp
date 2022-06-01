#ifndef FORC_HPP
#define FORC_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Forca {
    string palavra_secreta;
    string dificuldade;
    //criar vector de palavras

    public:
    //criar metodo para carregar palavras do arquivo para o vector
    bool verifica_score(string scores);
    bool verifica_palavras(string palavras);
    void abertura(bool validade_score, bool validade_palavras);
    int menu ();
    void imprime_score(string scores);
    int escolhe_dificuldade();
    string sorteia_palavra(string dificuldade); // sorteia palavra secreta
    string gera_dica (string palavra, string d);  //recebe palavra secreta e dificuldade, 

    // setters e getters
    void set_dificuldade(int d);
};

#endif