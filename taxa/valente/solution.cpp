#include <iostream>
#include <iomanip>

#include <vector>

using namespace std;

int N, 
    minTax, 
    totalArea = 0;
    
float F;

vector<int> areas;

int main() {
    cin >> N >> F;

    areas.reserve(N);
    for (int i=0; i<N; i++) {
        int area;
        cin >> area;
        totalArea += area;
        areas.push_back(area);
    }

    cout << std::setprecision(2) << minTax * F << endl;
}