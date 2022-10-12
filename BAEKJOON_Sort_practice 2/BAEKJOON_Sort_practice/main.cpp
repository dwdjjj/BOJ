#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<pair<string, int>>v;

bool is_digits(const string &a){
    if('0'<=a[0]&&a[0]<='9') return true;
    else return false;
}

bool cmp(const pair<string, int>&a, const pair<string, int>&b){
    return a.second<b.second;
}

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(is_digits(s1)) v.push_back({s2, stoi(s1.c_str())/2});
        else v.push_back({s1, stoi(s2.c_str())});
    }

    sort(v.begin(), v.end(), cmp);
    
    int length = (signed)v.size();
    
    for(int i=0; i<length; i++){
        cout << v[i].first << "\n";
    }
    
    return 0;
}
