#include "../include/forc.hpp"

bool Forca::verifica_palavras(string palavras) {
    ifstream file_palavras;
    file_palavras.open(palavras);
    string linha;
    while (getline(file_palavras, linha)) { //verifica cada palavra do arquivo de palavrea
        for (int i = 0; i < linha.size(); i++) { //verifica cada letra da palavra sendo analisada
            int letra_int = (int)linha[i]; // transforma letra em int para comparar com valores da tabela ASCII
            bool valid; //criterio 1 de avaliação - se é letre ou hifen -
            if ((letra_int >= 65 && letra_int <= 90) || (letra_int >= 97 && letra_int <= 122) || (letra_int == 45)) {
                valid = true;
            }
            if (valid &&  (linha.size()>=4)) {}   //criterio 2 -se tem pelo menos 4 letras- 
            else {
                /*se existir uma palavra invalida no arquivo,mensagem de erro é exibida, 
                loop termina, fecha o arquivo e função retorna falso*/
                file_palavras.close();
                return false;
            }

        }

    }
    return true; //se nenhuma palavra for invalida, função retorna verdadeiro
}

//verifica validade de arquivo de scores
// falta verificar se espaços com nome, dificuldade ou pontuação estão vazios
bool Forca::verifica_score(string scores) {
    fstream file_scores;
    file_scores.open(scores);
    string linha;
    
    while(getline(file_scores, linha)) { // conta quantidade de ; por linha 
        int count = 0;
        for (int i = 0; i < linha.size(); i++) {
            int alvo = 59;
            int letra_int = (int)linha[i];
            if (letra_int == alvo)
                count++;
        }
        if (count < 3 || count > 3){ //se a quantidade de ; for maior ou menor que 3 (por linha), função retorna falso 

            return false;
        }
    }

    return true;
}

//interface gráfica mostrando validação de arquivos de scores e palavras
void Forca::abertura(bool validade_score, bool validade_palavras) {
    cout<< ">  Lendo arquivos de palavras e scores, por favor aguarde..\n";
    cout<< "-----------------------------------------------------------------\n";
    if (validade_palavras && validade_score){
        cout<< ">  Arquivos OK!\n";
    }else if (!validade_palavras && !validade_score){
        cout<< ">  Arquivo de Palavras e Scores inválido!";
        exit(-1);
    }else if(!validade_palavras){
        cout<< ">  Arquivo de Palavras inválido!";
        exit(-1);
    }else{
        cout<< ">  Arquivo de Scores inválido!";
        exit(-1);
    }
    cout<< "-----------------------------------------------------------------\n";
    return;
}

//interface gráfica do menu de escolhas do jogador
int Forca::menu () {
    int escolha;
    bool escolha_invalida = true;
    cout << "\n\n<><><><><><><><> - JOGO DA FORCA - <><><><><><><><>\n\n ";
    while(escolha_invalida) {
        cout << "Escolha a opção desejada:\n\n";
        cout << "1 - Inciar jogo \n2 - Ver scores anteriores\nSua escolha:  ";
        cin >> escolha;
        if (escolha == 1 || escolha == 2)
            escolha_invalida = false;
        else    
            cout << "\n\n\nXXXXXXX - Digite uma escolha válida! - XXXXXXX\n\n\n";
    }
    return escolha;
}

void Forca::imprime_score(string scores) {
    fstream file_scores;
    file_scores.open(scores);
    string linha;
    cout << "\n\n<><><><><><><><> - SCORES ANTERIORES - <><><><><><><><>\n\n ";
    
    while(getline(file_scores, linha)) { // imprime o conteudo de cada linha
        cout << linha << endl;
    }

}

int Forca::escolhe_dificuldade() {
    int escolha = 0;
    
    cout << "\n\n<><><><><><><><> - VAMOS INICIAR - <><><><><><><><>\n\n ";

    while (escolha != 1 && escolha != 2 && escolha != 3) {
        cout << "Escolha o nível de dificuldade\n";
        cout << "1 - Fácil\n2 - Médio\n3 - Dificil\n";
        cout << "\nSua esolha: ";
        cin >> escolha;    
        if (escolha != 1 && escolha != 2 && escolha != 3){
            cout << "\n\n\nXXXXXXX - Digite uma escolha válida! - XXXXXXX\n\n\n";
        }else{
            break;
        }
    }
    return escolha;
}

// setters e getters
void Forca::set_dificuldade(int d) {
    if (d == 1){
        dificuldade = "Fácil";
    }else if (d == 2){
        dificuldade = "Médio";
    }else{
        dificuldade = "Dificil";
    }

}

string Forca::sorteia_palavra(string dificuldade){

}