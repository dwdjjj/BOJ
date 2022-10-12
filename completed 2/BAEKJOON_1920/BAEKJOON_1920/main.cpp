#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int>A; vector<int>target;
int n, m;
bool is_possible(int mid, int target){
    if(A[mid]<target) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    cin >> m;
    for(int i=0; i<m; i++){
        int b; cin >> b;
        target.push_back(b);
    }
    for(int i=0; i<m; i++){
        int left = 0, right = n-1, mid=0, ans = 0;
        bool flag = false;
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target[i]){
                flag = true;
                break;
            }
            if(is_possible(mid, target[i])){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(flag) cout << 1 << "\n";
        else cout << 0 << "\n";

    }
        return 0;
}
