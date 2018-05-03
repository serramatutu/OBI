#include <iostream>
#include <vector>


using namespace std;

vector<int> simplify(const vector<int>& heights) {

}

int main() {
    // Lê a quantidade de alturas
    int nHeights;
    cin >> nHeights;

    vector<int> heights(nHeights);

    // Lê as alturas
    int height;
    for (int i=0; i<nHeights; i++) {
        cin >> height;
        heights.push_back(height);
    }

    for(auto it = heights.cbegin(); it != heights.cend(); it++)
        cout << *it;

    return 0;
}