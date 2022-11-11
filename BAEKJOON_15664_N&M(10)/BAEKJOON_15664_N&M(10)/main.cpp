#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
vector<int> res;
vector<bool> visited = {false,};
void f(int idx, int cnt) {
    if(cnt == m) {
        for(int i=0; i<m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for(int i = idx; i < n; i++) {
        if(!visited[i] && tmp != v[i]) {
            visited[i] = true;
            res[cnt] = v[i];
            tmp = res[cnt];
            f(i, cnt+1);
            visited[i] = false;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    v.resize(n);
    res.resize(m);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    f(0, 0);
    return 0;
}
