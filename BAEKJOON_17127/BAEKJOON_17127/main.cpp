#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[18];

int f(int left, int right) {
    int group = 1;
    for (int i = left; i <= right; i++) {
        group *= arr[i];
    }
    return group;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    int M = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                int sum = f(1, i) + f(i+1, j) + f(j+1, k) + f(k+1, n);
                M = max(sum, M);
            }
        }
    }
    cout << M;
    return 0;
}
