/* 
Link para o problema:
https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/chefe/
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
class NoArvore<T> {
    NoArvore* pai;
    vector<NoArvore<T>> filhos;

    NoArvore<T>::NoArvore(NoArvore* pai, const vector<NoArvore>& filhos);
};

template <typename T>
NoArvore::NoArvore(NoArvore* pai, const vector<NoArvore>& filhos) : pai(pai), filhos(filhos) {}

template <typename T>
class Floresta<T> {
    vector<NoArvore<T>> raizes;
};

int main() {

    return 0;
}