#ifndef FORC_HPP
#define FORC_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

class Forca {
    string arquivo_palavras, arquivo_score;
    string palavra_secreta;
    string dificuldade;
    string chutes_certos = {'$','$','$','$','$','$','$','$','$','$','$','$','$','$','$','$'};
    char chute = '%';
    int erros = 0;
    int pontos = 0;
    int tentativas = 1;
    int contador_acertos = 0;
    int contador_turnos = 1;
    vector <string> palavras;
    vector <string> palavras_jogadas;

    public:
    Forca(string arq_palavras, string arq_score); //construtor recebe nome dos arquivos de palavras e score
    bool verifica_score();
    bool verifica_palavras();
    void abertura(bool validade_score, bool validade_palavras);
    int menu ();
    void imprime_score();
    void escolhe_dificuldade();
    void sorteia_palavra(); // sorteia palavra secreta
    string gera_dica (string palavra, string d);  //recebe palavra secreta e dificuldade, 
    void carrega_palavras(); //carrega palavras do arquivo para um vector
    void imprime_secreta();
    bool verifica_letra(char letra_palavra);
    void le_chute();
    void gera_dica ();
    void imprime_boneco();
    bool condicao_vitoria();    
    void remove_palavra();
// setters e getters
    string get_dificuldade();
    int get_erros();
    int get_pontos();
    string get_secreta();

    

};

#endif