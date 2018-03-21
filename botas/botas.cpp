/* Link para o problema: 
https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/botas/
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int count;
    cin >> count;

    map<int, int> botas;
    for (int i=0; i<count; i++) {
        char lado;
        int bota;
        cin >> bota >> lado;
     
        // Coloca a bota no dicionário caso ela não exista
        if (botas.count(bota) <= 0)
            botas[bota] = 1;

        if (lado == 'D')
            botas[bota] *= 2;
        else
            botas[bota] *= 3;
    }

    int validPairs = 0;
    for (auto it = botas.begin(); it != botas.cend(); it++) {
        int value = it->second;
        while (value % 6 == 0 && value != 0) { // Se tem ambos os pés
            value %= 6;
            validPairs++;
        }
    }

    cout << validPairs;

    return 0;
}