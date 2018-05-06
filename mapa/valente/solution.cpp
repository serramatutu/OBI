#include <iostream>
#include <vector>

using namespace std;

int main() {
    int width, height;
    cin >> width >> height;

    // inicializa a matriz que será o mapa
    // true -> pisado | false -> não pisado
    // Tamanhos + 2 para não se preocupar com exceção de acesso nas bordas
    vector<vector<bool>> map(height + 2, vector<bool>(width + 2));

    int currX, currY;
    char tile;
    for (int i=1; i<width+1; i++) {
        for (int j=1; j<height+1; j++) {
            cin >> tile;

            if (tile == '.')
                map[i][j] = false;
            else if (tile == 'H')
                map[i][j] = true;
            else if (tile == 'o'){
                map[i][j] = true;
                currX = i;
                currY = j;
            }
        }
    }

    // 0 - direita
    // 1 - cima
    // 2 - esquerda
    // 3 - abaixo
    // 4 - not initialized
    vector<int> xDirs {1, 0, -1, 0, 0};
    vector<int> yDirs {0, 1, 0, -1, 0};

    int lastDirection = -1;
    bool found;
    do {
        // checa por todas as direções
        found = false;
        for (int d=0; d<=3 && !found; d++) {
            if (d == lastDirection) // não volta
                continue;
            
            if (map[currX + xDirs[d]][currY + yDirs[d]]) { // se a hermione passou por aqui
                currX += xDirs[d];
                currY += yDirs[d];

                lastDirection = (d + 2) % 4;
                found = true;
            }
        }
    } 
    while (found);

    cout << currX << " " << currY;
}