#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int n;
int main(int argc, const char * argv[]) {
    /*vector<string> v;
    map<string, bool> m;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string name, inout;
        cin >> name >> inout;
        if(inout == "enter") m[name]=true;
        else m[name]=false;
        
        if(m[name]) v.push_back(name);
    }
    
    sort(v.begin(), v.end(), greater<string>());
    
    for(int i=0; i<v.size(); i++){
        if(m[v[i]]) cout << v[i] << "\n";
    }*/
    
    set<string> s;
    cin >> n;
    
    while(n--){
        string name, inout;
        cin >> name >> inout;
        
        if(inout=="enter") s.insert(name);
        else s.erase(name);
    }
    
    for(auto iterator=s.rbegin(); iterator !=s.rend(); iterator++)
        cout << *iterator << "\n";
    
    return 0;
}
