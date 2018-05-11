#include <iostream>
#include <vector>

using namespace std;

vector<int> moradores;
// vetor de acompanhamento para programação dinâmica
vector<long> anteriores;
int ultimoCorreto;

// atualiza o vetor até estar correto
// até o andar desejado
void update(int andar) {
    while (ultimoCorreto < andar) {
        // corrige o primeiro errado
        anteriores[ultimoCorreto + 1] = anteriores[ultimoCorreto] + moradores[ultimoCorreto + 1];
        // ele agora está certo
        ultimoCorreto++;
    }
}

int get(int andar) {
    update(andar); // atualiza até o atual, caso ainda não o tenha feito
    return anteriores[andar];
}

int main() {
    int nAndares, nEventos;
    cin >> nAndares >> nEventos;

    moradores.reserve(nAndares);
    anteriores.reserve(nAndares);

    // Lê a quantidade inicial de pessoas em cada andar
    int sum = 0;
    for (int i=0; i<nAndares; i++) {
        int pessoas;
        cin >> pessoas;
        sum += pessoas;
        moradores.push_back(pessoas);
        anteriores.push_back(sum);
    }
    ultimoCorreto = nAndares - 1;

    // lê as instruções de bombeiro ou mudança
    for (int i=0; i<nEventos; i++) {
        int cmd, // instrução (bombeiro ou mudança)
            andar; 

        cin >> cmd >> andar;
        andar--; // adequa o andar ao vetor

        if (cmd == 0) { // Mudança
            int pessoas;
            cin >> pessoas;

            int delta = pessoas - moradores[andar];
            update(andar); // atualiza tudo até o atual, caso ainda não esteja atualizado
            moradores[andar] = pessoas;
            anteriores[andar] += delta;
            ultimoCorreto = andar; // a partir do atual, está desatualizado
        }
        else { // Bombeiro
            cout << get(andar) << endl;
        }
    }

}