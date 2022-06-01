#ifndef FORC_HPP
#define FORC_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Forca {
    string arquivo_palavras, arquivo_score;
    string palavra_secreta;
    string dificuldade;
    vector <string> palavras;

    public:
    Forca(string arq_palavras, string arq_score); //construtor recebe nome dos arquivos de palavras e score
    bool verifica_score();
    bool verifica_palavras();
    void abertura(bool validade_score, bool validade_palavras);
    int menu ();
    void imprime_score();
    void escolhe_dificuldade();
    string sorteia_palavra(string dificuldade); // sorteia palavra secreta
    string gera_dica (string palavra, string d);  //recebe palavra secreta e dificuldade, 
    void carrega_palavras(); //carrega palavras do arquivo para um vector
    
    // setters e getters
    string get_dificuldade();

};

#endif