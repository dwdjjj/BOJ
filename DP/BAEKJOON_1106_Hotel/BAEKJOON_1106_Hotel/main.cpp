#include <vector>
#include <iostream>
using namespace std;
int c, n;
int cache[20][1000];
#define INF 987654321
vector<pair<int, int>> city;

int f(int idx, int nowCustom) {
    
    if(nowCustom>=c) return 0;
    
    if (idx >= n) {
        if (nowCustom < c) {
            return INF;
        }
    }
    
    int&ret = cache[idx][nowCustom];
    
    if (ret != -1) return ret;
    ret=INF;
    
    for(int i=0; ;i++){
        ret=min(ret,f(idx+1,nowCustom+city[idx].second*i)+city[idx].first*i);
        if(nowCustom+city[idx].second*i>c) break;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> c >> n;
    for (int i=0; i<20; i++) {
        for (int j=0; j<1000; j++) {
            cache[i][j] = -1;
        }
    }
    
    for (int i=0; i<n; i++) {
        int cost, customer;
        cin >> cost >> customer;
        city.push_back({cost, customer});
    }
    cout << f(0, 0);
    return 0;
}
