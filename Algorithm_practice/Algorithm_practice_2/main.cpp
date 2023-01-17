#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int MAX = 0;
int arr[35][35]={0,};
void f(int i, int count, int score[]){
    int tmp[35];
    
    for(int j=0; j<M; ++j){
        tmp[j] = max(score[j], arr[j][i]);
    }
    if(count==3){
        int sum = 0;
        for(int j=0; j<M;j++){
            sum += tmp[j];
        }
        MAX = max(MAX,sum);
        return;
    }
    for(int j=i+1; j<M; ++j){
        f(j, count+1, tmp);
    }
    return;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin >> N >> M;
    int score[35]={0,};

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        f(i, 1, score);
    }
    cout << MAX << "\n";
    return 0;
}
