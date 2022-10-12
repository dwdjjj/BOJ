#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int visited[10] = {0,};
    string N;
    cin >> N;
    
    // int count=0;
    for(int i=0; i<N.size(); i++){
        if (N[i]=='9'||N[i]=='6') {
            if(visited[6]>visited[9])
                visited[9]++;
            else if(visited[6]<visited[9])
                visited[6]++;
            else
                visited[N[i]-'0']++;
        }
        else
        {
            visited[N[i]-'0']++;
        }
    }
    
    int max=0;
    for(int i=0; i<10; i++){
        if(visited[i]>max)
            max = visited[i];
    }
    cout << max;
    
    return 0;
}
