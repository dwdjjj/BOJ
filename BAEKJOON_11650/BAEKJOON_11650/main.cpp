#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b){
    if(a==b)
        return a.second<b.second;
    else
        return a<b;
}
int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<pair<int, int>>P;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        P.push_back(make_pair(x, y));
        //P[i].first = x;
        //P[i].second = y;
    }
    
    sort(P.begin(), P.end(), compare);
    
    for(int i=0; i<N; i++){
        cout << P[i].first << " " << P[i].second << "\n";
    }
    
    return 0;
}
