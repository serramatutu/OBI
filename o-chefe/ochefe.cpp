/* 
Link para o problema:
https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/chefe/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

struct Empregado {
    int idade;
    unordered_set<int> gerentes;
};

void pergunta(int e, const vector<Empregado>& ids) {
    int idade = 9999;

    // para não reprocessar aquilo que já foi processado
    unordered_set<int> processados;
    // cria a fila com todos os gerentes de 'e'
    queue<int> fila;
    for (auto g = ids[e].gerentes.cbegin(); g != ids[e].gerentes.cend(); g++)
        fila.push(*g);

    while (!fila.empty()) {
        e = fila.front(); // pega o próximo na fila a ser processado
        fila.pop(); // remove da fila

        if (ids.at(e).idade < idade) // caso sua idade seja menor que a menor idade, substitui
            idade = ids.at(e).idade;

        // coloca seus gerentes na fila
        for (auto g = ids[e].gerentes.cbegin(); g != ids[e].gerentes.cend(); g++)
            if (processados.count(*g) <= 0) { // não processa um mesmo elemento duas vezes
                processados.insert(*g);
                fila.push(*g);
            }
    }

    if (idade > 100)
        cout << '*';
    else
        cout << idade;
}

int main() {
    int qtdEmpregados, qtdDiretos, qtdInstrucoes;
    cin >> qtdEmpregados >> qtdDiretos >> qtdInstrucoes;
    
    vector<Empregado> ids(qtdEmpregados);
    vector<int> id_map(qtdEmpregados); // Mapa de ID de empregado para posição na árvore

    // lê as idades
    vector<int> idades(qtdEmpregados);
    for (int i=0; i<qtdEmpregados; i++) {
        Empregado e;
        cin >> e.idade;
        ids[i] = e;
        id_map[i] = i;
    }

    int g, s;
    for (int i=0; i<qtdDiretos; i++) {
        cin >> g >> s;
        g--;
        s--;
        ids[s].gerentes.insert(g);
    } 

    // lê as instruções
    char instrucao;
    for (int i=0; i<qtdInstrucoes; i++) {
        cin >> instrucao;

        if (instrucao == 'T') { // troca
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            // troca a idade
            int idadeaux = ids[id_map[a]].idade;
            ids[id_map[a]].idade = ids[id_map[b]].idade;
            ids[id_map[b]].idade = idadeaux;

            int map_aux = id_map[a];
            id_map[a] = id_map[b];
            id_map[b] = map_aux;
        }
        else if (instrucao == 'P') { // pergunta
            int e;
            cin >> e;
            e--;
            pergunta(id_map[e], ids);
            cout << endl;
        }
    }

    return 0;
}