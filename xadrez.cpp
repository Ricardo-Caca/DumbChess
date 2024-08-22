#include <iostream>
#include <unistd.h>
using namespace std;

// 0 = casa vazia
// 1 = peão preto
// 2 = cavalo preto
// 3 = bispo preto
// 4 = torre preto
// 5 = dama preto
// 6 = rei preto

// 7 = peão branco
// 8 = cavalo branco
// 9 = bispo branco
// 10 = torre branco
// 11 = dama branco
// 12 = rei branco

//Xadrez do Caca
void letreiro(){
char barra = 92;
cout <<                      "      ___  "   << " _   "              << " __   "             << " ____ "  << "____  "  << "  " << endl;
cout << barra << "  / "        << "|   | "   << "| "<< barra <<"  "  << "|  |  "             << "|     "  << "   /  "  << "  " << endl;
cout << " "<< barra << "/  "   << "|---| "   << "|  "<< barra <<" "  << "|__|  "             << "|---- "  << "  /   "  << "  " << endl;
cout << " /" << barra << "  "  << "|   | "   << "|  / "              << "|  "<< barra <<"  " << "|     "  << " /    "  << "  " << endl;
cout << "/  " << barra << " "  << "|   | "   << "|_/  "              << "|   "<< barra <<" " << "|____ "  << "/___  "  << "  " << endl;

cout << "          " << " _   "              << " ___ " << endl;
cout << "          " << "| "<< barra << "  " << "|   |" << endl;
cout << "          " << "|  "<< barra << " " << "|   |" << endl;
cout << "          " << "|  / "              << "|   |" << endl;
cout << "          " << "|_/  "              << "|___|" << endl;

cout << "    " << " ___ "<< " " <<  "___  "   << " "   << " ___ " << " "    <<  "___"      << endl;
cout << "    " << "|   " << " " << "|   | "   << " "   << "|   "  << " "    << "|   | "    << endl;
cout << "    " << "|   " << " " << "|---| "   << " "   << "|   "  << " "    << "|---| "    << endl;
cout << "    " << "|   " << " " << "|   | "   << " "   << "|   "  << " "    << "|   | "    << endl;
cout << "    " << "|___" << " " << "|   | "   << " "   << "|___"  << " "    << "|   | "    << endl;
cout << endl;
}

//Aloca as peças iniciais no tabuleiro
void alocandoPecas(int tabuleiro[8][8]){
    int i,j;
    //colocando as posições 0
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            tabuleiro[i][j] = 0;
        }
    }
    //colocando as peças pretas
    tabuleiro[0][0] = 4;
    tabuleiro[0][1] = 2;
    tabuleiro[0][2] = 3;
    tabuleiro[0][3] = 5;
    tabuleiro[0][4] = 6;
    tabuleiro[0][5] = 3;
    tabuleiro[0][6] = 2;
    tabuleiro[0][7] = 4;

    //colocando as peças brancas
    tabuleiro[7][0] = 10;
    tabuleiro[7][1] = 8;
    tabuleiro[7][2] = 9;
    tabuleiro[7][3] = 11;
    tabuleiro[7][4] = 12;
    tabuleiro[7][5] = 9;
    tabuleiro[7][6] = 8;
    tabuleiro[7][7] = 10;

    // peoes brancos/pretos
    for(i=0;i<8;i++){
        //peoes
        tabuleiro[1][i] = 1;
        tabuleiro[6][i] = 7;
    }
}

//Printa o Tabuleiro "Traduzido" em texto || traduzindo numeros em letras
void printTabuleiro(int tabuleiro[][8]){
int i,j;
//saida de dados
for(i=0;i<8;i++){
        cout << "  -----------------------------------------" << endl;
    for(j=0;j<8;j++){
        if(j==0){
        cout << i+1;
        }
    switch(tabuleiro[i][j]){
        case 0:
            cout << " | " << "  ";
            break;
        case 1:
            cout << " | " << "PP";
            break;
        case 2:
            cout << " | " << "CP";
            break;
        case 3:
            cout << " | " << "BP";
            break;
        case 4:
            cout << " | " << "TP";
            break;
        case 5:
            cout << " | " << "DP";
            break;
        case 6:
            cout << " | " << "RP";
            break;
        case 7:
            cout << " | " << "PB";
            break;
        case 8:
            cout << " | " << "CB";
            break;
        case 9:
            cout << " | " << "BB";
            break;
        case 10:
            cout << " | " << "TB";
            break;
        case 11:
            cout << " | " << "DB";
            break;
        case 12:
            cout << " | " << "RB";
            break;
        default:
            cout << " ERRO";
            break;
        }
    }
    cout << " |" << endl;
}
cout << "    a    b    c    d    e    f    g    h" << endl;
}

//Converte a letra da jogada em numero
int conversorLetra(char letra){
if(letra=='a' || letra=='A'){
    return 0;
}
else if (letra=='b' || letra=='B'){
    return 1;
}
else if (letra=='c' || letra=='C'){
    return 2;
}
else if (letra=='d' || letra=='D'){
    return 3;
}
else if (letra=='e' || letra=='E'){
    return 4;
}
else if (letra=='f' || letra=='F'){
    return 5;
}
else if (letra=='g' || letra=='G'){
    return 6;
}
else if (letra=='h' || letra=='H'){
    return 7;
}
else{
    return 9;
}
}

//verifica se a peça que quer mover é preta
bool movimentopreto(int letra1, int cordenada1, int tabuleiro[][8], int quantjogadas){
    //verifica se é a jogada do preto
    if(quantjogadas%2!=0){
        //verifica se a peça que deseja mover é preta
        if(tabuleiro[cordenada1][letra1] == 1 || tabuleiro[cordenada1][letra1] == 2 || tabuleiro[cordenada1][letra1] == 3 || tabuleiro[cordenada1][letra1] == 4 || tabuleiro[cordenada1][letra1] == 5 || tabuleiro[cordenada1][letra1] == 6){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}

//verifica se a peça que quer mover é branca
bool movimentobranco(int letra1, int cordenada1, int tabuleiro[][8], int quantjogadas){
    //verifica se é a jogada do branco
    if(quantjogadas%2 == 0){
        //verifica se a peça que deseja mover é branca
        if(tabuleiro[cordenada1][letra1] == 7 || tabuleiro[cordenada1][letra1] == 8 || tabuleiro[cordenada1][letra1] == 9 || tabuleiro[cordenada1][letra1] == 10 || tabuleiro[cordenada1][letra1] == 11 || tabuleiro[cordenada1][letra1] == 12){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}

//Verifica se o movimento da peça digitada é possivel
bool movimentopossivel(int letra1, int cordenada1, int letra2, int cordenada2, int tabuleiro[][8], int quantjogadas){
    //verifica se a jogada foi feita dentro do tabuleiro
if (letra1==9 || letra2==9 || cordenada1>7 || cordenada2>7){
    return false;
}
    //verifica se a jogada foi no mesmo lugar
else if(cordenada1 == cordenada2 && letra1 == letra2){
    return false;
}
    //verifica se a peça que quer mover é branca
else if(movimentobranco(letra1, cordenada1, tabuleiro, quantjogadas) == false){
    return false;
}
    //verifica se a peça que quer mover é preta
else if(movimentopreto(letra1, cordenada1, tabuleiro, quantjogadas) == false){
    return false;
}
    //verifica se realmente esta movimentando uma peça
else if(tabuleiro[cordenada1][letra1] == 0){
    return false;
}
else{
    return true;
}
}

//Altera a matriz do tabuleiro de acordo com a jogada feita
void movimento(int letra1, int cordenada1, int letra2, int cordenada2, int tabuleiro[][8]){
tabuleiro[cordenada2][letra2] = tabuleiro[cordenada1][letra1];
tabuleiro[cordenada1][letra1] = 0;
system("cls");
}

//Main do jogo
void novojogo(){
int i,j, quantjogadas=0;
string jogada1;
string jogada2;
int letra1;
int letra2;
int cordenada1;
int cordenada2;
int tabuleiro[8][8];

//tela de loading
cout << "Carregando";
for(i=0;i<7;i++){
    cout << ".";
    usleep(200000);
}

alocandoPecas(tabuleiro);

system("cls");

printTabuleiro(tabuleiro);
do{
//ver se é a vez do branco ou preto
if(quantjogadas%2==0){
    cout << "Vez do branco" << endl;
}
else{
    cout << "Vez do Preto" << endl;
}

do{
//entrada da jogada
cout << "Digite a peça que quer mover: ";
cin >> jogada1;

cout << "Digite para onde a peça irá: ";
cin >> jogada2;

//Separação do char para a peca
cordenada1 = jogada1[1] - '0';
cordenada2 = jogada2[1] - '0';

letra1 = conversorLetra(jogada1[0]);
cordenada1 = cordenada1 - 1;

letra2 = conversorLetra(jogada2[0]);
cordenada2 = cordenada2 - 1;
movimentopreto(letra1, cordenada1, tabuleiro, quantjogadas);
//vificando se o movimento é possivel
if(movimentopossivel(letra1, cordenada1, letra2, cordenada2, tabuleiro, quantjogadas) == false){
    cout << "Movimento impossível" << endl;
}
}while(movimentopossivel(letra1, cordenada1, letra2, cordenada2, tabuleiro, quantjogadas) == false);
movimento(letra1, cordenada1, letra2, cordenada2, tabuleiro);
quantjogadas++;
printTabuleiro(tabuleiro);
}while (quantjogadas != 40);
}

//menu
void menu(){
char select;

letreiro();
cout << "1 - Novo jogo" << endl;
cout << "2 - Regras do jogo" << endl;
cout << "3 - Sair" << endl;

do{
cout << "-- ";
cin >> select;
switch(select){
    case '1':
        novojogo();
        break;
    case '2':
        cout << "-----REGRAS-----" << endl;
        cout << "---Movimentos---" << endl;
        cout << "Cavalo - Move em L" << endl;
        cout << "Torre - Move em linha reta" << endl;
        cout << "Peão - Primeiro movimento pode ser 1 ou 2 casas para frente, depois so move 1 casa, so captura nas 2 diagonais da frente" << endl;
        cout << "Bispo - Move na diagonal" << endl;
        cout << "Dama - Move em linha reta e diagonal" << endl;
        cout << "Rei - Move 1 casa para todos os lados" << endl;
        cout << "  ---Jogo---" << endl;
        cout << "- Vai aparecer para digitar a cordenada da peça que você quer mover, e logo em seguida para onde essa peça ira" << endl;
        cout << "- Para evitar erros, não digite mais do que 2 caracteres e nada maior que 8 e h" << endl;
        break;
    case '3':
        break;
    case '9':
        cout << "Gabriel Lindo <3 !!" << endl;
        break;
    default:
        cout << "ERRO - Digite um numero do menu" << endl;
        menu();

}
}while(select != '3');
}

//-------------------------FUNÇÕES-------------------------//

int main(){
setlocale(LC_ALL, "");
menu();
}
