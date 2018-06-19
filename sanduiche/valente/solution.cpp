#include <iostream>
#include <vector>

int n, d;

int min = 0;
int max = 0;
long int sum;
int qtd = 0;

bool minRepeat = false;
bool maxRepeat = false;

std::vector<int> pieces;

void increaseMax() {
    max++;
    if (max / n >= 1) {
        max = 0;
        maxRepeat = true;
    }
    sum += pieces[max];
}

void increaseMin() {
    sum -= pieces[min];
    min++;
    if (min / n >= 1) {
        min = 0;
        minRepeat = true;
    }
}


int main() {
    std::cin >> n >> d;

    pieces.reserve(n);

    for (int i=0; i<n; i++) {
        int current;
        std::cin >> current;

        pieces.push_back(current);
    }

    sum = pieces[0];
    
    while (!(maxRepeat && minRepeat) && (!maxRepeat || max < min)) {
        if (sum < d) {
            increaseMax();
        }
        else if (sum > d) {
            increaseMin();
        }
        else { // sum == d
            qtd++;
            increaseMin();
        }
    }

    std::cout << qtd;

    return 0;
}