#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Student {
    int Korean, English, Math; // a국어 b영어 c수학
    string name;
};
bool compare(Student &A, Student &B){
    if(A.Korean!=B.Korean) return A.Korean>B.Korean;
    else if(A.English!=B.English) return A.English<B.English;
    else if(A.Math!=B.Math) return A.Math>B.Math;
    else return A.name<B.name;
}
int main(int argc, const char * argv[]) {
    
    int N;
    cin>>N;
    Student S[N];
    for(int i=0; i<N; i++){
        cin >> S[i].name;
        cin >> S[i].Korean;
        cin >> S[i].English;
        cin >> S[i].Math;
    }
    sort(S, S+N, compare);
    for(int i=0; i<N; i++){
        cout << S[i].name << "\n";
    }
    return 0;
}
