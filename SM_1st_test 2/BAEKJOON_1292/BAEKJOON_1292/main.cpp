#include <vector>
#include <iostream>
using namespace std;
vector<int> v;
int a, b, sum = 0;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    
    for (int i=1; i<=b; i++) {
        for(int j=0; j<i; j++) {
            v.push_back(i);
        }
    }
    for (int i=a-1; i<b; i++) {
        sum += v[i];
    }
    cout << sum;
    return 0;
}
