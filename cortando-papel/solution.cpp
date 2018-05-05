#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

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
        sign = getSign(heights[i + 1] - heights[i]);

        if (lastSign != sign && lastSign != 0)
            newHeights.push_back(heights[i] - minHeight);
    }

    // O último deve ser sempre parte do vetor
    newHeights.push_back(heights[heights.size() - 1] - minHeight);

    return newHeights;
}


int solve(const vector<int>& heights) {
    unordered_multimap<int, int> heightMap;

    int valley = 0; // vales estão nos pares
    if (heights[1] - heights[0] < 0 ) // se o segundo é maior que o primeiro
        valley = 1; // vales estão nas casas ímpares

    int maxHeight = 0;
    for (int i=0; i<heights.size(); i++) {
        heightMap.insert({heights[i], i}); // Mapeia a posição atual à altura atual
        
        if (maxHeight < heights[i]) // encontra a maior altura
            maxHeight = heights[i];
    }

    int maxPieces = 2,
        pieces = 1; // corte fora do papel resulta em 1 pedaço
    // vai descendo as alturas
    for (int currentHeight = maxHeight; currentHeight > 0; currentHeight--) {
        auto cols = heightMap.equal_range(currentHeight); // índices das colunas com a altura atual
        for (auto columnInterator = cols.first; columnInterator != cols.second; columnInterator++) {
            int currentColumnIndex = columnInterator->second;
            if (currentColumnIndex % 2 - valley == 0) // se a coluna atual é um vale
                pieces--;
            else
                pieces++;
        }

        if (pieces > maxPieces)
            maxPieces = pieces;
    }

    return maxPieces;
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