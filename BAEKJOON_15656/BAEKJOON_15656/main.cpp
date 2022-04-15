#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;

//vector<int> v;
//vector<int> res;

const int MAX = 10;
int arr[MAX];
int res[MAX];

void f(int x) {
    if (x == m) {
        for (int i=0; i<m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=0; i<n; i++) {
        res[x] = arr[i];
        f(x+1);
//        res.push_back(v[i]);
//        f(x+1);
//        res.pop_back();
        
    }
}
int main(int argc, const char * argv[]) { // n개중 m개 중복허용
    ios::sync_with_stdio(0);
    cin >> n >> m;
    
//    for (int i=0; i<n; i++) {
//        int x; cin >> x;
//        v.push_back(x);
//    }
//    sort(v.begin(), v.end());
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    f(0);

    return 0;
}
