#include <vector>
#include <iostream>
using namespace std;
int numA, numB, len;
bool flag = false;
//vector<int>a;
//vector<int>b;
//vector<int>res;
int a[200002];
int b[200002];
int res1[200002];
int res2[200002];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> numA >> numB;
    for(int i=0; i<numA; i++){
        int n;
        cin >> n;
        a[i] = n;
    }
    for(int i=0; i<numB; i++){
        int n;
        cin >> n;
        b[i] = n;
    }
    int n=0;
    bool check = false;
    for(int i=0; i<numA; i++){
        for(int j=0; j<numB; j++){
            if(a[i]==b[j]){
                check = true;
                break;
            }
        }
        if(!check){
            for(int k=0; k<len; k++){
                if(a[i]==res1[k]){
                    flag = true;
                    break;
                }
            }
            if(flag) flag=false;
            else res1[n++] = a[i];
        }
        check = false;
    }
    for(int i=0; i<numB; i++){
        for(int j=0; j<numA; j++){
            if(b[i]==a[j]){
                check = true;
                break;
            }
        }
        if(!check){
            for(int k=0; k<len; k++){
                if(b[i]==res2[k]){
                    flag = true;
                    break;
                }
            }
            if(flag) flag=false;
            else res2[n++] = b[i];
        }
        check = false;
    }
    int cnt=0;
    for(int i=0; i<numA; i++){
        if(res1[i]!=0) cnt++;
    }
    for(int j=0; j<numB; j++){
        if(res2[j]!=0) cnt++;
    }
    cout << cnt;
    return 0;
}
