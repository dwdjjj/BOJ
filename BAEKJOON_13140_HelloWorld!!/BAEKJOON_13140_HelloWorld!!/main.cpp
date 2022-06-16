#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
vector<int>v;
int arr[2][5] = {{0, 1, 2, 2, 3}, {4, 3, 5, 2, 6}};
bool flag = true;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i=0; i<10; i++) v.push_back(i);
    
    do {
        if (!flag) {
            break;
        }
        if (v[0] == 0 || v[4] == 0) continue;
        
        int sumH = 0, sumW = 0;
        
        sumH = 10000 * v[arr[0][0]] + 1000 * v[arr[0][1]] + 100 * v[arr[0][2]] + 10 * v[arr[0][3]] + v[arr[0][4]];
        sumW = 10000 * v[arr[1][0]] + 1000 * v[arr[1][1]] + 100 * v[arr[1][2]] + 10 * v[arr[1][3]] + v[arr[1][4]];
        
        if (sumH + sumW == N) {
            flag = false;
            cout << "  " << sumH << "\n";
            cout << "+ " << sumW << "\n";
            cout << "-------" << "\n";
            cout << (N > 100000 ? " " : "  ") << N;
        }
        
    }
    while (next_permutation(v.begin(), v.end()));
    if (flag) {
        cout << "No Answer";
    }
    return 0;
}
