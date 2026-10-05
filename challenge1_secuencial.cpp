#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    long long suma = 0;
    for (long long v : a) suma += v;
    cout << "Suma secuencial: " << suma << endl;
    return 0;
}
