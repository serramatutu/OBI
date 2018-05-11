#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nAndares, nEventos;
    cin >> nAndares >> nEventos;

    vector<int> moradores;
    moradores.reserve(nAndares);

    // vetor de acompanhamento para programação dinâmica
    vector<long> prev;
    prev.reserve(nAndares);
    int lastCorrect = nAndares;

    // Lê a quantidade inicial de pessoas em cada andar
    int sum = 0;
    for (int i=0; i<nAndares; i++) {
        int pessoas;
        cin >> pessoas;
        sum += pessoas;
        moradores.push_back(pessoas);
        prev.push_back(sum);
    }

    // lê as instruções de bombeiro ou mudança
    for (int i=0; i<nEventos; i++) {
        int cmd, // instrução (bombeiro ou mudança)
            andar; 

        cin >> cmd >> andar;
        andar--; // adequa o andar ao vetor

        if (cmd == 0) { // Mudança
            int pessoas;
            cin >> pessoas;

            // atualiza o atual
            int delta = pessoas - moradores[andar];
            moradores[andar] = pessoas;
            prev[andar] += delta;
            // invalida todos os à frente
            lastCorrect = andar;
        }
        else { // Bombeiro
            // atualiza o vetor até estar correto
            // até o andar desejado
            while (lastCorrect < andar) {
                // corrige o primeiro errado
                prev[lastCorrect + 1] = prev[lastCorrect] + moradores[lastCorrect + 1];
                // ele agora está certo
                lastCorrect++;
            }

            cout << prev[andar] << endl;
        }
    }

}