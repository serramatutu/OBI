#include <iostream>

int main() {
    int a, b, targetA, targetB;
    std::cin >> a >> b >> targetA >> targetB;

    int count = 0;
    if (b != targetB) {
        a = !a;
        b = !b;

        count++;
    }

    if (a != targetA) {
        a = !a;

        count++;
    }

    std::cout << count;

    return 0;
}