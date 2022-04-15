#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*int maxProduct(void)
{
        //두개
        int case1 = v[0] * v[N - 1]; //양 끝
        int case2 = v[N - 1] * v[N - 2]; //정렬했을 때 제일 큰 수 두개
        int case3 = v[0] * v[1]; //정렬했을 때 제일 작은 수 두개
        //세개
        int case4 = v[N - 1] * v[N - 2] * v[N - 3]; //정렬했을 때 큰 수 세개
        int case5 = v[0] * v[1] * v[2]; //정렬했을 때 작은 수 세개
        int case6 = v[0] * v[N - 1] * v[N - 2]; //제일 작은 수, 큰 수 두개
        int case7 = v[0] * v[1] * v[N - 1]; //작은 수 두개, 제일 큰 수
        return max({ case1, case2, case3, case4, case5, case6, case7});
}*/

int main(int argc, const char * argv[]) {
    
    int n; cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ans = max(v[n-1]*v[n-2],v[n-1]*v[n-2]*v[n-3]);
    if(v[0]*v[1]>0)
    {
        ans = max(v[0]*v[1], ans);
        ans = max(v[0]*v[1]*v[n-1], ans);
    }
    cout << ans;
    
    return 0;
}
