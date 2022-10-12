#include <iostream>
#include <string>
using namespace std;
string s;
bool flag=true;
int cnt_zero=0, cnt_one=0, cnt=0;
int main(int argc, const char * argv[]) {
    cin >> s;
    if (s[0]=='0') cnt_zero++;
    else cnt_one++;
    
    for (int i=1; i<s.length(); i++) {
        if(s[i] != s[i-1]){
            if (s[i]=='0') cnt_zero++;
            else cnt_one++;
        }
    }
    cout << min(cnt_zero, cnt_one);
    //    for (int i=0; i<s.length(); i++) {
    //        if (s[i]=='0') {
    //            cnt_zero++;
    //        }
    //        else if(s[i]=='1'){
    //            cnt_one++;
    //        }
    //    }
//    if(cnt_one==s.length() || cnt_zero==s.length()) flag = false;
//
//    if(!flag) cout << '0' << "\n";
//
    
//    else if(flag){
//        if(cnt_zero<cnt_one){
//            for (int i=0; i<s.length(); i++) {
//                if (s[i]=='0') {
//                    s[i]='1';
//                    if (s[i+1]=='1') cnt++;
//                }
//            }
//        }
//        if(cnt_zero>cnt_one){
//            for (int i=0; i<s.length(); i++) {
//                if (s[i]=='1') {
//                    s[i]='0';
//                    if (s[i+1]=='0') cnt++;
//                }
//            }
//        }
//        cout << cnt;
//    }
    return 0;
}
