#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSign(int a) {
    if (a < 0) return -1;
    if (a > 0) return 1;
    return 0;
}

vector<int> simplify(const vector<int>& heights) {
    int minHeight = INT32_MAX;
    for (auto it = heights.cbegin(); it != heights.cend(); it++)
        if (*it < minHeight)
            minHeight = *it;
    minHeight--;

    int sign = getSign(heights[1] - heights[0]);
    vector<int> newHeights(1, heights[0] - minHeight);

    // remove colunas iguals, escadas e colunas desnecessárias no geral
    int lastSign;
    for (int i=1; i < heights.size() - 1; i++) {
        lastSign = sign;
        sign = heights[i + 1] - heights[i];

        if (lastSign != sign && lastSign != 0)
            newHeights.push_back(heights[i] - minHeight);
    }

    return newHeights;
}

int solve(const vector<int>& heights) {
    
}

int main() {
    // Lê a quantidade de alturas
    int nHeights;
    cin >> nHeights;

    // Lê as alturas
    vector<int> heights(nHeights);
    for (int i=0; i<nHeights; i++)
        cin >> heights[i];
    
    // Simplifica o histograma sem que perca suas propriedades
    heights = simplify(heights);

    cout << solve(heights);
    return 0;
}