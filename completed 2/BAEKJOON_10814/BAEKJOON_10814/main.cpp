#include <algorithm>
#include <iostream>
#include <vector>
//웨안뒈;
using namespace std;
bool compare(pair<int,int>a, pair<int,int>b){
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second<b.second;
}
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    vector<pair<int, int>>v(n);
    vector<string>people(n);
    
    int age; string name;
    for(int i=0; i<n; i++){
        cin >> age >> name;
        v[i].first = age;
        v[i].second = i;
        people[i] = name;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<n; i++){
        cout << v[i].first << " " << people[v[i].second] <<"\n";
    }
    
    return 0;
}
