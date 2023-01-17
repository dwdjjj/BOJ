#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.size()==b.size())
        return a<b;
    else
        return a.size()<b.size();
}
int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<string>word(N);
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        word[i] = s;
    }
    
    sort(word.begin(),word.end(),compare);
    // word.erase(unique(word.begin(),word.end()),word.end());
    // 위 코드 쓰면 출력초과뜨던데 쓰레기값이 남네머네 그걸 지워주는게 erase네하던데 왜 안될까요?
    string tmp;
    for(int i=0; i<N; i++){
        tmp = word[i];
        if(tmp!=word[i+1])
        {
            cout << word[i] << "\n";
        }
        else
            continue;
    }
    
    return 0;
}
