
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int wood[5];
    int tmp;
    for(int i=0; i<5; i++){
        cin >> wood[i];
    }
    bool flag = true;
    while(flag){
        for(int i=0; i<4; i++){
            if(wood[i+1]<wood[i])
            {
                flag = true;
                tmp = wood[i];
                wood[i] = wood[i+1];
                wood[i+1] = tmp;
                // swap(wood[i], wood[j]);
                for(int k=0; k<5; k++){
                    cout << wood[k] << " ";
                }
                cout << "\n";
                break;
            }
            else flag = false;
        }
    }
    return 0;
}
