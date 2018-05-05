/*
Link para o problema:
https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/game10/
*/

#include <iostream>

using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;

    if (a > d)
        cout << n - a + d;
    else
        cout << d - a;

    return 0;
}