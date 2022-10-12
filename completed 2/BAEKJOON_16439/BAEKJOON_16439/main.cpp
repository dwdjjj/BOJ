#include <algorithm>
#include <iostream>
using namespace std;
const int maxN = 30+5;

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    
    int arr[maxN][maxN];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    int maxsum = 0;
    for(int i=1; i<=M; i++){
        for(int j=i+1; j<=M; j++){
            for(int k=j+1; k<=M; k++){
                int sum = 0;
                for(int l=1; l<=N; l++){
                    sum += max({arr[l][i], arr[l][j], arr[l][k]});
                }
                maxsum = max(maxsum, sum);
            }
        }
    }
    cout << maxsum;
    return 0;
}
