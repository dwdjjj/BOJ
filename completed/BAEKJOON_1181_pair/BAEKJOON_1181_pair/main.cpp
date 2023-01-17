
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(const pair<int,string>a, const pair<int,string>b){
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second< b.second;
} // compare라는 함수를 정의해 기준을 둬서 정렬하게 바꾸기?

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<pair<int,string>>word(N);
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        int length = int(s.size());
        word[i].first = length;
        word[i].second = s;
    }
    sort(word.begin(),word.end(),compare);
    word.erase(unique(word.begin(),word.end()), word.end());
    /* string tmp;
    for(int i=0; i<N; i++){
        tmp = word[i].second;
        if(tmp!=word[i+1].second)
        {
            cout << word[i].second << "\n";
        }
        else
            continue;
    }*/
    for(int i=0; i<word.size(); i++){
        cout << word[i].second << "\n";
    }
    return 0;
}
