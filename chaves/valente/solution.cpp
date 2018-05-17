#include <iostream>
#include <string>

using namespace std;

int main() {
    int nLinhas;
    cin >> nLinhas;

    string linha;
    string todo;

    while (getline(cin, linha))
        todo += linha;

    int opened = 0;
    for (auto atual=todo.cbegin(); atual != todo.cend(); atual++) {
        if (*atual == '{') {
            opened++;
        }
        else if (*atual == '}') {
            opened--;

            if (opened < 0) {
                cout << 'N';
                return 0;
            }
        }
    }

    if (opened != 0)
        cout << 'N';
    else
        cout << 'S';

    return 0;
}