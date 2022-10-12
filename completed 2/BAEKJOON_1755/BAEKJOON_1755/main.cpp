#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int, string>a, pair<int, string>b){
    if(a.first!=b.first)
        return a.second<b.second;
    else
        return a.second<b.second;
}
int main(int argc, const char * argv[]) {
    
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int M, N;
    cin >> M >> N;
    
    vector<pair<int, string>>v(N-M+1);
    
    for(int i=0; i<N-M+1; i++){
        // v.push_back(make_pair(M+i, arr[(M+i)/10] + arr[(M+i)%10]));
        v[i].first = M+i;
        if((M+i)/10 == 0) v[i].second = arr[(M+i)%10];
        else v[i].second = arr[(M+i)/10] + arr[(M+i)%10];
    }
    sort(v.begin(), v.end(), compare);
    
    int count=0;
    for(int i=0; i<N-M+1; i++){
        cout << v[i].first << " ";
        count++;
        if(count%10==0) cout << "\n";
    }
    
    return 0;
}
