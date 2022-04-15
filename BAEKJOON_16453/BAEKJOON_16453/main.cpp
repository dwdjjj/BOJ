#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, l;
vector<int> fruits;
int main(int argc, const char * argv[]) {
    cin >> n >> l;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        fruits.push_back(x);
    }
    
    sort(fruits.begin(), fruits.end());
    for (int i=0; i<fruits.size()-1; i++) {
        if (fruits[i] == l) {
            if (fruits[i+1] - l == 1) l++;
        }
    }
    cout << l;
    return 0;
}

