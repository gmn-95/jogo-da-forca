#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

using namespace std;

string inicio();
//sub-rotina criada para captar a dica e a palavra/frase, verificar o tamanho do mesmo, e substituir..
//... a palavra/frase secreta por "_____". Está sub-rotina vai retornar a dica.

int jogar(string Dica);
//sub-rotina criada para mostrar a quantdade de chances disponíveis, receber a letra que o usuário quer chutar..
//...e ir mostrando as letras que ele acertar

void resultado(int acertos);
//conferir e mostrar se o usuário acertou ou se errou

void instrucao();
//mostra ao usuário como funciona o jogo

void jogo();
//reune as sub-rotinas inicio(); int jogar(string Dica); void resultado(int acertos); void instrucao();
// em uma só sub-rotina

void limparBuffer(void);
//limpar o buffer do teclado

void zerar();
//reseta as variáveis globais quando

char palavra[30], letra[1], secreta[30];
int tamanho = 0, i = 0, chances = 6, escolha;
bool acerto = false;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    MENU:
    cout << "1 - jogar\n";
    cout << "2 - instruções\n";
    cout << "3 - Sair\n";
    cout << "--> ";
    cin >> escolha;
  //  zerar();
    switch(escolha){
        case 1:

            jogo();
            zerar();
            system("sleep 3");
            system("clear");
            goto MENU;

        break;

        case 2:
            instrucao();
            cout << "\nPressione enter para continuar...\n";
            getchar();
            limparBuffer();
            system("clear");
            goto MENU;

        break;

        case 3:
            cout << "\nPrograma finalizado...\n\n";
            exit(0);
        break;
    }

    return 0;
}

string inicio(){
    string dica;
    //armazenar a palavra secreta
    cout << "\nDigite a palavra/frase secreta: ";
    cin >> palavra;
    limparBuffer();

    //armazenar a dica
    cout << "\nDigite a dica: ";
    cin >> dica;
    limparBuffer();
    system("clear");

    //verificar o tamanho da palvra
    // \0 (caractere do ENTER, indica que ali terminou a string)
    while(palavra[i] != '\0'){

        //passar para a proxima posição da palavra
        i++;
        //tamanho da palavra
        tamanho++;
    }
        //preencher o vetor secreto com traços (-). Auxiliar no visual do jogo
        for (i = 0; i < tamanho; i++){
            secreta[i] = '_';
        }
    return dica;
}

int jogar(string Dica){
    int acertos = 0;
    string cabeca = " ", bEsq = " ", bDir = " ", pernDir = " ", pernEsq = " ", tronco = " ";
    //rotina do jogo
    //enquando o jogador ainda tiver chances e ainda não acertou a palavra, o loop executará
    while((chances > 0) && (acertos < tamanho)){

        //mostrar as chances e a dica para o usuário
        cout << "---|";
        cout << "\n| ";
        cout << cabeca << "\n| " << bEsq << tronco << bDir << "\n| " << pernEsq << pernDir << "\n";
        cout << "|______\n";
        cout << "Chances restantes: " << chances << "\n\n";
        cout << "\nA dica é: " << Dica;

        //mostrar a o tamanho da palavra em traços (-).Conforme o usuário vai acertando as letras,
        //os traços serão substituidos pela letra acertada
        cout << "\nDigite uma letra: ";
        for (i = 0; i < tamanho; i++){
            cout << secreta[i];
        }
        //ler a letra que o usário escolher
        cout << "\n-->: ";
        cin >> letra[0];
        limparBuffer();

        //percorrer todo o vetor palavra e comparar se exite a letra escolhida na palavra secreta
        for(i = 0; i < tamanho; i++){

            //verificar se a letra existe na palavra secreta
            if (palavra[i] == letra[0]){

                //se ela existir, acerto é verdadeiro, e o vetor secreta mostrará a letra acertada e em qual
                //posição da palavra
                acerto = true;
                secreta[i] = palavra[i];
                acertos++;
            }
        }

        //se o usuário errar a letra, ele perderá uma chance (obs, a pessoa tem 6 chances)
        if(!acerto){
            chances--;
            if(cabeca == " ")
                cabeca = " 0";
            else if(cabeca == " 0" && bEsq == " ")
                bEsq = "/";
            else if(cabeca == " 0" && bEsq == "/" && tronco == " ")
                tronco = "|";
            else if(cabeca == " 0" && bEsq == "/" && tronco == "|" && bDir == " ")
                bDir = "\\";
            else if(cabeca == " 0" && bEsq == "/" && tronco == "|" && bDir == "\\" && pernEsq == " ")
                pernEsq = "/";
            else if(cabeca == " 0" && bEsq == "/" && tronco == "|" && bDir == "\\" && pernEsq == "/" && pernDir == " ")
                pernDir = " \\";

        }
        acerto = false;
        system("clear");

    }
    return acertos;
}

void resultado(int acertos){
    //se a quantidade de acertos for igual ao tamanho da palavra, então o jogador acertou a palavra secreta
    //caso ao contrário ele perderá
    if(acertos == tamanho){
        cout << "\nPalavra/frase secreta era: " << palavra;
        cout << "\nVocê ACERTOU!\n";
    }
    else if(acertos != tamanho){
        cout << "\nPalavra/frase secreta era: " << palavra;
        cout << "\nVocê ERROU!\n";
    }
}

void instrucao(){
    cout << "JOGO DA FORCA: Digite uma palavra ou frase para que seu amigo tente adivinhar!\n\n";
    cout << "OBS: Caso deseja escrever uma frase, ao invés de dar espaços entre as palavras\n";
    cout << "utilize o sinal de menos '-'.   Exemplo: 2-homens-e-meio\n";
}

void jogo(){
    int acert;
    string dic;
    dic = inicio();
    acert = jogar(dic);
    resultado(acert);
}

void zerar(){

  palavra[30], letra[1], secreta[30];
  tamanho = 0, i = 0, chances = 6, escolha;
  acerto = false;

}

void limparBuffer(void){
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}
