#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<vector<int>>arr(N,vector<int>(3,0));
    vector<int> sum(N,0);
    vector<bool> visited(N,0);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int j=0; j<3; j++){
        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                if(arr[i][j]==arr[k][j]){
                    if(i!=k)
                        visited[i]=true;
                }
                else visited[k]=false;
            }
            if(!visited[i])
            {
                sum[i]+=arr[i][j];
            }
            
        }
    }
    
    for(int i=0; i<N; i++){
        cout << sum[i] <<"\n";
    }
        
    
    return 0;
}
