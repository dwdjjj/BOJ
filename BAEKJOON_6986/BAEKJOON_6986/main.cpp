#include <iostream>
using namespace std;
bool is_end(int a[]){
    for(int i=0; i<5; i++){
        if(a[i]!=i+1)   return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    
    int wood[5];
        
    for(int i=0; i<5; i++){
        cin >> wood[i];
    }
    bool flag = true;
    while(flag){
        for(int i=0; i<4; i++){
            if(wood[i+1]<wood[i])
            {
                swap(wood[i], wood[i+1]);
                for(int k=0; k<5; k++){
                    cout << wood[k] << " ";
                }
                cout << "\n";
            }
            if(is_end(wood)) {
                flag = false;
                break;
            }
        }
    }
    return 0;
}
