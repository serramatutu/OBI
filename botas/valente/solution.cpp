/* Link para o problema: 
https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/botas/
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct bota {
    int dir = 0;
    int esq = 0;
};

int main() {
    int count;
    cin >> count;

    map<int, bota> botas;
    for (int i=0; i<count; i++) {
        char lado;
        int tamanho;
        cin >> tamanho >> lado;

        if (lado == 'D')
            botas[tamanho].dir += 1;
        else
            botas[tamanho].esq += 1;
    }

    int validPairs = 0;
    for (auto it = botas.cbegin(); it != botas.cend(); it++)
        validPairs += min(it->second.esq, it->second.dir);

    cout << validPairs;

    return 0;
}