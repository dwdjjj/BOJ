#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<vector<char>>v(N,vector<char>(N,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> v[i][j];
        }
    }
    int K;
    cin >> K;
    if(K==1)
    {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
    if(K==2){
        for(int i=0; i<N; i++){
            for(int j=N-1; j>=0; j--){
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
    if(K==3){
        for(int i=N-1; i>=0; i--){
            for(int j=0; j<N; j++){
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
