
#include <iostream>
using namespace  std;

int main(int argc, const char * argv[]) {

    int student[30]={0,};
    bool submission[30]={0,};
    for(int i=0; i<28; i++){
        cin >> student[i]; //첫번째 학생부터 28번째 학생까지 입력받기(0번-27번student배열에 저장)
    }
    for(int i=0; i<30; i++){
        if(student[i]!=0){
            submission[student[i]-1]=true; //0~29번학생중 숫자를 입력받은 학생의 번호의 제출을 참으로
        }
    }
    for(int i=0; i<30; i++){
        if(!submission[i]) cout << i+1 << "\n";
    }
    
    return 0;
}
