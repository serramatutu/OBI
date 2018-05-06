#include <iostream>

using namespace std;

int main() {
    int nRounds;
    cin >> nRounds;

    int winner = 0; // dario se > 0 e xerxes se < 0
    int d, x; // jogadas de dario e xerxes
    for (int i=0; i<nRounds; i++) {
        cin >> d >> x;

        if (x == (d + 1) % 5 || x == (d + 2) % 5) // dario ganha
            winner++;
        else
            winner--;
    }

    if (winner > 0)
        cout << "dario";
    else
        cout << "xerxes";

    return 0;
}