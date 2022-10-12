#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main (int argc, const char * argv[]) {
    string new_id;
    string answer = "";
    cin >> new_id;
    // 대문자를 소문자로
    for (int i=0; i<new_id.size(); i++) {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = new_id[i] - 'A' + 'a';
    }
    
    // 소문자, 숫자, -, _, . 택하기
    for (int i=0; i<new_id.size(); i++) {
        if((new_id[i] >= 'a' && new_id[i] <= 'z')
           || (new_id[i] >= '0' && new_id[i] <= '9')
           || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer.push_back(new_id[i]);
        }
    }
    
    // 마침표 두번연속시 하나 지우기
    for(int i=1; i<answer.size(); i++) {
        if (answer[i-1] == '.' && answer[i] == '.') {
            answer.erase(answer.begin() + i);
        }
    }
    cout << answer << "\n";
    // 시작 끝 마침표 지우기
    while(answer[0] == '.') answer.erase(answer.begin());
    if(answer[answer.size() - 1] == '.') answer.erase(answer.end() - 1);
    cout << answer << "\n";
    // 빈 문자열은 a로
    if(!answer.size()) answer.push_back('a');
    
    //15자 넘으면 뒷문자들 제거 이후 끝 마침표 제거
    if(answer.size() > 15) {
        answer.erase(answer.begin() + 15, answer.end());
        if(answer[answer.size() - 1] == '.') answer.erase(answer.end() - 1);
    }
    // 2글자 이하면 3자될때까지 마지막 문자 추가
    if(answer.size() <= 2) {
        char tmp = answer[answer.size() - 1];
        while(answer.size() != 3) {
            answer.push_back(tmp);
        }
    }
    
    cout << answer;
    return 0;
}
