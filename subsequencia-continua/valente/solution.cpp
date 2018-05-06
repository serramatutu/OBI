#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int nElems;
    cin >> nElems;

    int max = 1;
    int currentLength = 1;
    int last = 1000000; // nunca será maior que 10^5
    int current;
    for (int i=0; i<nElems; i++) {
        cin >> current;
        if (abs(current - last) <= 1) // se é contínuo
            currentLength++;
        else
            currentLength = 1;

        if (currentLength > max)
            max = currentLength;

        last = current;
    }

    cout << max;
    
    return 0;
}