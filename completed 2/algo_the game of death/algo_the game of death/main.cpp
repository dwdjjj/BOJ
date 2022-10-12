#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    //안되넹;
    int N, K;
    cin >> N >> K;

    // int Select[N];
    vector<int> Select(N,0);
    // bool isVisited[N]={0,};
    vector<bool> isVisited(N,false);
    
    for(int i=0; i<N; i++){
        cin >> Select[i];
    }
    
    int now = 0, next = 0;
    int count=0;
    
    while(next != K){
        count++;
        next = Select[now];
        now = next;
        if(isVisited[now]) break;
        isVisited[now]=true;
    }
    cout << (now==K?count:-1);
    
    return 0;
}
