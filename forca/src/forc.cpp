#include "../include/forc.hpp"



Forca::Forca(string arq_palavras, string arq_score) {
    arquivo_palavras = arq_palavras;
    arquivo_score = arq_score;
}

bool Forca::verifica_palavras() {
    ifstream file_palavras;
    file_palavras.open(arquivo_palavras);
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
bool Forca::verifica_score() {
    fstream file_scores;
    file_scores.open(arquivo_score);
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
        cout<< ">  Arquivo de Palavras e Scores invalidos!";
        exit(-1);
    }else if(!validade_palavras){
        cout<< ">  Arquivo de Palavras invalido!";
        exit(-1);
    }else{
        cout<< ">  Arquivo de Scores invalido!";
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
        cout << "Escolha a alternativa desejada:\n\n";
        cout << "1 - Inciar jogo \n2 - Ver scores anteriores\nSua escolha:  ";
        cin >> escolha;
        if (escolha == 1 || escolha == 2)
            escolha_invalida = false;
        else    
            cout << "\n\n\nXXXXXXX - Digite uma escolha valida! - XXXXXXX\n\n\n";
    }
    return escolha;
}

void Forca::imprime_score() {
    fstream file_scores;
    file_scores.open(arquivo_score);
    string linha;
    cout << "\n\n<><><><><><><><> - SCORES ANTERIORES - <><><><><><><><>\n\n ";
    
    while(getline(file_scores, linha)) { // imprime o conteudo de cada linha
        cout << linha << endl;
    }

}

void Forca::escolhe_dificuldade() {
    int escolha = 0;
    
    cout << "\n\n<><><><><><><><> - VAMOS INICIAR - <><><><><><><><>\n\n ";

    while (escolha != 1 && escolha != 2 && escolha != 3) {
        cout << "Escolha o nivel de dificuldade\n";
        cout << "1 - Facil\n2 - Medio\n3 - Dificil\n";
        cout << "\nSua esolha: ";
        cin >> escolha;    
        if (escolha != 1 && escolha != 2 && escolha != 3){
            cout << "\n\n\nXXXXXXX - Digite uma escolha válida! - XXXXXXX\n\n\n";
        }else{
            break;
        }
    }
    if (escolha == 1){
        dificuldade = "Facil";
    }else if (escolha == 2){
        dificuldade = "Medio";
    }else{
        dificuldade = "Dificil";
    }
}
 


void Forca::carrega_palavras() {
    ifstream file_palavras;
    file_palavras.open(arquivo_palavras);
    string linha;
    while (getline(file_palavras, linha)) {
      for (int i = 0; i < linha.size(); i++) { //deixa todas as palavras com letras maiúsculas, para padronização
          linha[i] = toupper(linha[i]);
      }
      
      
        palavras.push_back(linha);
  }
}

void Forca::sorteia_palavra(){

    unsigned seed = time(0);
    srand(seed);

    int pos = rand() % palavras.size();
    palavra_secreta = palavras.at(pos);
    palavras_jogadas.push_back(palavra_secreta);
}

// setters e getters
    string Forca::get_dificuldade() {
        return dificuldade;
    }



bool Forca::verifica_letra(char letra_palavra){
  bool acerto = false;
		if(chute == letra_palavra) {
			acerto = true;
      contador_acertos++;
		}

  return acerto;
}


void Forca::imprime_secreta(){
  for(int i = 0; i < palavra_secreta.size() ;i++){
    if(verifica_letra(palavra_secreta[i])){
      chutes_certos[i] = chute;
    }
    if(i == palavra_secreta.size()-1){
      contador_acertos = 0;
      contador_turnos++;
    }
    if(chutes_certos[i] == '$'){
      cout << "_";
    }else{
      cout << chutes_certos[i];
    }
  }
  cout << endl;
}

void Forca::le_chute() {
    tentativas++;
    cout << "Digite seu chute: ";
    cin >> chute;
    chute = toupper(chute); //transforma chute em maiusculo para evitar erros
    for(int i = 0; i < palavra_secreta.size();i++){
        if(verifica_letra(palavra_secreta[i])){
          pontos++;
        }else if(contador_acertos == 0 && i == palavra_secreta.size()-1){
          cout << "\tPoxa, essa letra nao esta na palavra! Tente novamente.\n";
          pontos--;
          erros++;
        }
    }
}

//VITORIA FAMILIA TUDO NOSSO NADA DELES!!!

void Forca::imprime_boneco(){
  cout << endl;
  cout << "XXXXXXXXXXXXXXX - TURNO " << contador_turnos<< " - XXXXXXXXXXXXXXX" << endl;
  cout << endl;
  if(erros == 0){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 1){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 2){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /       "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 3){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|      "<< endl;
  	cout << " |              "<< endl;
    cout << " |              "<< endl;
  	cout << "_|___           ";
  	cout << endl << endl;
  }else  if(erros == 4){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 5){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |      /       "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }else  if(erros == 6){
    cout << "  _______       "<< endl;
  	cout << " |/      |      "<< endl;
  	cout << " |       o      "<< endl;
  	cout << " |      /|\\    "<< endl;
  	cout << " |      / \\    "<< endl;
  	cout << " |              "<< endl;
  	cout << " |              "<< endl;
  	cout << "_|___           "<< endl;
  	cout << endl << endl;
  }
}

void Forca::gera_dica () {
        unsigned seed = time(0);
        srand(seed);

    if (dificuldade == "Facil") {
        int qtd_dica = 2;//(rand() % (palavra_secreta.size()/5));
        int cont = 0;
        if (qtd_dica > 0) {
            for (int i = 0; i < palavra_secreta.size(); i++) {
                int int_letra = (int)palavra_secreta[i];
                if (int_letra != 65 && int_letra != 69 && int_letra != 73 && int_letra != 79 && int_letra != 85) {
                    cout << "dica: " << (char)int_letra << endl;
                    cont++;
                }

                if (cont == qtd_dica){
                    break;
                }
            }
        }
    }else if (dificuldade == "Medio"){

    }

}

int Forca::get_erros(){
  
  return erros;
}

int Forca::get_pontos(){
  return pontos;  
                  
}  
string Forca::get_secreta(){
    return palavra_secreta;
}

bool Forca::condicao_vitoria(){
  int BO = 0;
  BO = 0;
  for(int i = 0; i < palavra_secreta.size();i++){
    if(chutes_certos[i] == '$'){
      BO++;
    }
  }
  if(pontos == palavra_secreta.size()){

    pontos = pontos+2;
    if (erros == 0) {
      pontos++;
    }
    return true;
  }else if(BO == 0){
    return true;
  }else{
    return false;
  }
  
}

/*void Forca::remove_palavra() {
  palavras.erase(pos_secreta);
}*/