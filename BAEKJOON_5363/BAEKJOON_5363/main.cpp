#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        string s;
        getline(cin,s);
        
        istringstream ss(s);
        string stringbuffer;
        vector<string> word;
        word.clear();
        
        while(getline(ss, stringbuffer, ' ')){ // 공백으로 단어들 구분해서 쪼개기
            word.push_back(stringbuffer);
        }
        
        for(int i=2; i<word.size(); i++){
            cout << word[i] << " ";
        }
        cout << word[0] << " " << word[1];
        cout << "\n";
    }
    return 0;
}
