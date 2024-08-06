#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#define BGRN "\e[1;32m"
#define BRED "\e[1;31m"
#define reset "\e[0m"
#define TAMANHO 6

using namespace std;

string mina[TAMANHO][TAMANHO]; // a mina com os elementos escondidos
string minaN[TAMANHO][TAMANHO]; // a mina visivel para os jogadores

double pista_prob = 0.05, armadilha_prob = 0.07, diamante_prob = 0.40, armadilha_prob2 = 0.07, genio_prob = 0.05, troll_prob = 0.05;

int total_casas, pistas, armadilhas, armadilhas2, diamantes, j, k, pontos_jogador1, pontos_jogador2, pontos_jogador3, pontos_jogador4, troll, genio;

// função para distribuir aleatoriamente pistas, armadilhas, e diamantes na mina
void distribuicao_elementos() {
    total_casas = TAMANHO * TAMANHO;
    pistas = total_casas * pista_prob;
    armadilhas = total_casas * armadilha_prob;
    armadilhas2 = total_casas * armadilha_prob2;
    diamantes = total_casas * diamante_prob;
    troll = total_casas * troll_prob;
    genio = total_casas * genio_prob;

    // mina preenchida com pedras
    for (j = 0; j < TAMANHO; j++) {
        for (k = 0; k < TAMANHO; k++) {
            mina[j][k] = "🪨";
        }
    }

    // pistas colocadas aleatoriamente
    while (pistas > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "📜";
            pistas--;
        }
    }
    
    // armadilhas (buracos) colocadas aleatoriamente
    while (armadilhas > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "🕳";
            armadilhas--;
        }
    }
    // armadilhas (esconderijo) colocadas aleatoriamente
    while (armadilhas2 > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "🚪";
            armadilhas2--;
        }
    }

    // diamantes colocados aleatoriamente
    while (diamantes > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "💎"; 
            diamantes--;
        }
    }

    //genio colocado aleatoriamente
    while (genio > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "🧞"; 
            genio--;
        }
    }

    //troll colocado aleatoriamente
    while (troll > 0) {
        j = rand() % TAMANHO;
        k = rand() % TAMANHO;
        if (mina[j][k] == "🪨") {
            mina[j][k] = "🧌"; 
            troll--;
        }
    }
}

// função para mostrar o estado atual da mina
void imprimir_mina(const string mina[TAMANHO][TAMANHO]) {
    for (j = 0; j < TAMANHO; j++) {
        for (k = 0; k < TAMANHO; k++) {
            cout << "  "<< mina[j][k] << "  ";
        }
        cout << endl;
    }
}

//função para a pista ficar 2 segundos na tela
void mostrar_pista(){
    imprimir_mina(mina);
    Sleep(2000);
}

int main() {
    srand(time(NULL));
    system("chcp 65001");
    int opcao, i;
    string jogador1, jogador2, jogador3, jogador4;
    bool sair = false;
    // escolha da quantidade e nome dos jogadores
    do {
        cout << "Quantos jogadores irão jogar:\n"; 
        cout << "2 - dois jogadores\n";
        cout << "3 - três jogadores\n";
        cout << "4 - quatro jogadores\n";
        cout << "5 - sair\n";
        cin >> opcao;
        switch (opcao) {
            case 2:
                cout << "Nome do jogador 1:\n";
                cin.get();
                getline(cin, jogador1);
                cout << jogador1 << " sua cor é: 🔵" << endl; // identificação dos jogadores
                cout << "Nome do jogador 2:\n";
                getline(cin, jogador2);
                cout << jogador2 << " sua cor é: 🟢 " << endl;
                sair = true;
                break;
            case 3:
                cout << "Nome do jogador 1:\n";
                cin.get();
                getline(cin, jogador1);
                cout << jogador1 << " sua cor é: 🔵" << endl;
                cout << "Nome do jogador 2:\n";
                getline(cin, jogador2);
                cout << jogador2 << " sua cor é: 🟢 " << endl;
                cout << "Nome do jogador 3:\n";
                getline(cin, jogador3);
                cout << jogador3 << " sua cor é: 🔴" << endl;
                sair = true;
                break;
            case 4:
                cout << "Nome do jogador 1:\n";
                cin.get();
                getline(cin, jogador1);
                cout << jogador1 << " sua cor é: 🔵" << endl;
                cout << "Nome do jogador 2:\n";
                getline(cin, jogador2);
                cout << jogador2 << " sua cor é: 🟢 " << endl;
                cout << "Nome do jogador 3:\n";
                getline(cin, jogador3);
                cout << jogador3 << " sua cor é: 🔴" << endl;
                cout << "Nome do jogador 4:\n";
                getline(cin, jogador4);
                cout << jogador4 << " sua cor é: 🟡" << endl;
                sair = true;
                break;
            case 5:
                cout << "Fim de jogo" << endl;
                sair = true;
                return 0;
                break;
            default:
                cout << "Opção inválida, selecione outra opção:" << endl;
                break;
        }
    } while (!sair);
    // contextualização do jogo 
    cout << BGRN << "Você foi convocado para a exploração de uma mina" << endl;
    cout << "que acabou de ser liberada pela prefeitura de" << endl;
    cout << "sua cidade, os mineradores que acharem diamantes" << endl;
    cout << "poderão ficar com eles! Seu objetivo" << endl;
    cout << "é encontrar a maior quantidade de quilates de diamantes." << endl;
    cout << "Boa sorte na sua busca, tome cuidado com as" << BRED << " armadilhas e o temido troll!" << endl;

    // inicializar a mina visivel para os jogadores com pedras
    for (j = 0; j < TAMANHO; j++) {
        for (k = 0; k < TAMANHO; k++) {
            minaN[j][k] = "🪨";
        }
    }

    // distribuir pistas, armadilhas e diamantes na mina escondida
    distribuicao_elementos();

    // mostrar o estado atual da mina visivel aos jogadores
    cout << reset << "MINA ATUAL: \n";
    imprimir_mina(minaN);

    //estrutura base do jogo dependendo do número de jogadores
    if (opcao == 2) {
        pontos_jogador1 = 0;
        pontos_jogador2 = 0;
        
        for (i = 1; i <= 18; i++) {
            cout << reset << jogador1 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador1+= rand() % 10 + 1;
                minaN[j][k] = "💎"; // atualizar a mina visivel
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";// atualizar a mina visivel
                pontos_jogador1-=15; // descontar 15 dos seus quilates
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";// atualizar a mina visivel
                pontos_jogador1+=15; // ganhar 15 quilates
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída!\n";
                minaN[j][k] = "🕳";// atualizar a mina visivel
                pontos_jogador1-=10; // descontar 10 dos seus quilates
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador2-=5; //desconta do adversario
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; // atualizar a mina visivel
                mostrar_pista();
                system("cls");
            } 
            else if (mina[j][k] ==  "🟢")
            {
                cout << "Um jogador já esteve aqui e levou tudo e deixou uma armadilha! \n";
                pontos_jogador1-=5;
            }
            else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🔵"; //marcar as casas ocupadas
            }
            
            // mostrar o estado atual da mina visivel
            cout << "Estado atual da mina após a jogada de " << jogador1 << ":\n";
            imprimir_mina(minaN);

            cout << jogador2 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador2+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15;
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador2-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            }
            else if (mina[j][k] == "🔵")
            {
                cout << "Um jogador já esteve aqui e levou tudo e deixou uma armadilha! \n";
                pontos_jogador2-=5;
            }
            else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🟢"; 
            }
            cout << "Estado atual da mina após a jogada de " << jogador2 << ":\n";
            imprimir_mina(minaN);
            cout << "Quantidade de quilates do(a) " << jogador1 << ": " << pontos_jogador1 << endl;
            cout << "Quantidade de quilates do(a) " << jogador2 << ": " << pontos_jogador2 << endl;
        }

        cout << reset << "Jogo finalizado!\n";
        cout << "Pontos do " << jogador1 << ": " << pontos_jogador1 << endl;
        cout << "Pontos do " << jogador2 << ": " << pontos_jogador2 << endl;

        if (pontos_jogador1 > pontos_jogador2) {
            cout << jogador1 << " venceu!\n";
        } else if (pontos_jogador2 > pontos_jogador1) {
            cout << jogador2 << " venceu!\n";
        } else {
            cout << "O jogo terminou empatado!\n";
        }
    }
    if (opcao == 3) {
        pontos_jogador1 = 0;
        pontos_jogador2 = 0;
        pontos_jogador3 = 0;
        for (i = 1; i <= 12; i++) {
            cout << reset << jogador1 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador1+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída!\n";
                minaN[j][k] = "🕳";
                pontos_jogador1-=10; 
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador2-=5; 
                pontos_jogador3-=5; 
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🔵"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }

            cout << "Estado atual da mina após a jogada de " << jogador1 << ":\n";
            imprimir_mina(minaN);

            cout << jogador2 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador2+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador2-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
                pontos_jogador3-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🟢"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }
            cout << "Estado atual da mina após a jogada de " << jogador2 << ":\n";
            imprimir_mina(minaN);

            cout << jogador3 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador3+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador3-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
                pontos_jogador2-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🔴"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }
            cout << "Estado atual da mina após a jogada de " << jogador3 << ":\n";
            imprimir_mina(minaN);
            cout << "Quantidade de quilates do(a) " << jogador1 << ": " << pontos_jogador1 << endl;
            cout << "Quantidade de quilates do(a) " << jogador2 << ": " << pontos_jogador2 << endl;
            cout << "Quantidade de quilates do(a) " << jogador3 << ": " << pontos_jogador3 << endl;
        }

        cout << reset << "Jogo finalizado!\n";
        cout << "Pontos do " << jogador1 << ": " << pontos_jogador1 << endl;
        cout << "Pontos do " << jogador2 << ": " << pontos_jogador2 << endl;
        cout << "Pontos do " << jogador3 << ": " << pontos_jogador3 << endl;

        if ((pontos_jogador1 > pontos_jogador2) && (pontos_jogador1 > pontos_jogador3)) {
            cout << jogador1 << " venceu!\n";
        } else if ((pontos_jogador2 > pontos_jogador1) && (pontos_jogador2 > pontos_jogador3)) {
            cout << jogador2 << " venceu!\n";
        } else if ((pontos_jogador3 > pontos_jogador1) && (pontos_jogador3 > pontos_jogador2)){
            cout << jogador3 << " venceu!\n";
        } else {
            cout << "O jogo terminou empatado!\n";
        }
    }

    if (opcao == 4) {
        pontos_jogador1 = 0;
        pontos_jogador2 = 0;
        pontos_jogador3 = 0;
        pontos_jogador4 = 0;
        for (i = 1; i <= 9; i++) {
            cout << reset << jogador1 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador1+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída!\n";
                minaN[j][k] = "🕳";
                pontos_jogador1-=10; 
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador2-=5; 
                pontos_jogador3-=5; 
                pontos_jogador4-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🔵"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }

            cout << "Estado atual da mina após a jogada de " << jogador1 << ":\n";
            imprimir_mina(minaN);

            cout << jogador2 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador2+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador2-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
                pontos_jogador3-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🟢"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }
            cout << "Estado atual da mina após a jogada de " << jogador2 << ":\n";
            imprimir_mina(minaN);

            cout << jogador3 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador3+= rand() % 10 + 1;
                minaN[j][k] = "💎"; 
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador3-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
                pontos_jogador2-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🔴"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }
            cout << "Estado atual da mina após a jogada de " << jogador3 << ":\n";
            imprimir_mina(minaN);

            cout << jogador4 << " escolha sua " << i << "ª coordenada (linha | coluna): ";
            cin >> j >> k;
            if (mina[j][k] == "💎") {
                cout << "Você encontrou um diamante!\n";
                srand(time(NULL));
                pontos_jogador4+= rand() % 10 + 1;
                minaN[j][k] = "💎";
            } else if (mina[j][k] == "🧌") {
                cout << "O troll te pegou!\n";
                minaN[j][k] = "🧌";
                pontos_jogador1-=15; 
            } else if (mina[j][k] == "🧞") {
                cout << "Você encontrou o gênio!\n";
                minaN[j][k] = "🧞";
                pontos_jogador1+=15; 
            } else if (mina[j][k] == "🕳") {
                cout << "Você caiu em um túnel sem saída\n";
                minaN[j][k] = "🕳"; 
                pontos_jogador4-=10;
            } else if (mina[j][k] == "🚪") {
                cout << "Você encontrou o esconderijo secreto!\n";
                minaN[j][k] = "🚪"; 
                pontos_jogador1-=5; 
                pontos_jogador2-=5;
                pontos_jogador3-=5;
            } else if (mina[j][k] == "📜") {
                cout << "Você encontrou uma pista!\n";
                minaN[j][k] = "📜"; 
                mostrar_pista();
                system("cls");
            } else {
                cout << "Nada encontrado.\n";
                minaN[j][k] = "🟡"; 
            }
            if (mina[j][k] == "🔵" ||  "🟢" || "🔴" || "🟡") {
                cout << "Casa já ocupada! \n";
            }
            cout << "Estado atual da mina após a jogada de " << jogador4 << ":\n";
            imprimir_mina(minaN);
            cout << "Quantidade de quilates do(a) " << jogador1 << ": " << pontos_jogador1 << endl;
            cout << "Quantidade de quilates do(a) " << jogador2 << ": " << pontos_jogador2 << endl;
            cout << "Quantidade de quilates do(a) " << jogador3 << ": " << pontos_jogador3 << endl;
            cout << "Quantidade de quilates do(a) " << jogador4 << ": " << pontos_jogador4 << endl;
        }

        cout << reset << "Jogo finalizado!\n";
        cout << "Pontos do " << jogador1 << ": " << pontos_jogador1 << endl;
        cout << "Pontos do " << jogador2 << ": " << pontos_jogador2 << endl;
        cout << "Pontos do " << jogador3 << ": " << pontos_jogador3 << endl;
        cout << "Pontos do " << jogador4 << ": " << pontos_jogador4 << endl;

        if ((pontos_jogador1 > pontos_jogador2) && (pontos_jogador1 > pontos_jogador3) && (pontos_jogador1 > pontos_jogador4)) {
            cout << jogador1 << " venceu!\n";
        } else if ((pontos_jogador2 > pontos_jogador1) && (pontos_jogador2 > pontos_jogador3) && (pontos_jogador2 > pontos_jogador4)) {
            cout << jogador2 << " venceu!\n";
        } else if ((pontos_jogador3 > pontos_jogador1) && (pontos_jogador3 > pontos_jogador2) && (pontos_jogador3 > pontos_jogador2)){
            cout << jogador3 << " venceu!\n";
        } else if((pontos_jogador4 > pontos_jogador1) && (pontos_jogador4 > pontos_jogador2) && (pontos_jogador4 > pontos_jogador3)){
            cout << jogador4 << " venceu!\n";
        }else {
            cout << "O jogo terminou empatado!\n";
        }
    }
    return 0;
}