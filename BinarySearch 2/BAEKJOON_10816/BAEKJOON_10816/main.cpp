#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;
int N, M;
unordered_map<int, int>um;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    cin >> N;
    while(N--){
        int number;
        cin >> number;
        um[number]++;
    }
    cin >> M;
    while(M--){
        int findnum;
        cin >> findnum;
        cout << um[findnum] << " ";
    }
    return 0;
}
