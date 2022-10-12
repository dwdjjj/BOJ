#include <string>
#include <iostream>
#include <vector>
using namespace std;
bool compare(string a, string b){ // 메인에서 소문자 대문자 체크하는 것 vs 함수로 정의하는 것 후자가 나아보이긴해 일단?
    for(int i=0; i<a.size(); i++){
        if('a'<=a[i]&&a[i]<='z')
            a[i]-='a';
        else a[i] -= 'A';
    }
    for(int i=0; i<b.size(); i++){
        if('a'<=b[i]&&b[i]<='z')
            b[i]-='a';
        else b[i] -= 'A';
    }
    if(a[0]==b[0])
        return a<b;
    else
        return a<b;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    while(n!=0){
    
        vector<string>word(n);
        for(int i=0; i<n; i++){
            cin >> word[i];
        }
        
        sort(word.begin(), word.end(), compare);
        
        cout << word[0] << "\n";
        
        cin >> n;
    }
    
    return 0;
}
