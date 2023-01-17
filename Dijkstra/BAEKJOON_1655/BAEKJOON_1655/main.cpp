#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int n;
priority_queue<int, vector<int>, less<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (pq1.size() != pq2.size()) pq2.push(-x);
            else pq1.push(x);
            
            if ((pq1.size() + pq2.size())%2 == 0) {
                int tmp = min(pq1.top(), -pq2.top());
                cout << tmp << "\n";
            }
            else cout << pq1.top() << "\n";
        }
    return 0;
}

