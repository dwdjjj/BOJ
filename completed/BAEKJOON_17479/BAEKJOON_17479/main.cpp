#include <map>
#include <iostream>
using namespace std;
typedef long long ll;
int a,b,c;
ll normal=0, special=0, service=0;

int main(int argc, const char * argv[]) {
    cin >> a >> b >> c;
    map<string,int>A,B,C;
    while(a--){
        string s; int n;
        cin >> s >> n;
        A.insert({s,n});
    }
    while(b--){
        string s; int n;
        cin >> s >> n;
        B.insert({s,n});
    }
    while(c--){
        string s;
        cin >> s;
        C.insert({s,1});
    }
    int N; cin >> N;
    while(N--){
        string order; cin >> order;
        if(A.find(order)!=A.end()) normal += A[order];
        else if(B.find(order)!=B.end()) special += B[order];
        else service += 1;
    } //총 입력
    if(normal<20000 && special) cout << "No";
    else if(normal+special<50000 && service) cout << "No";
    else if(service>1) cout << "No";
    else cout << "Okay";
    return 0;
}

