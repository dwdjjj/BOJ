#include <iostream>
using namespace std;
int arr[] = {1, 3, 5, 7};
int n = 4;
//int used[10];
char path[10];

void print(char path[]) {
    for(int i =0; i<4; i++) {
        if(path[i] == 'o') cout << arr[i];
    }
    cout << "\n";
}

void run(int lev) {
    if(lev == n) {
        print(path);
//        cout << path << "\n";
        return;
    }
    // o아니면 x, used 안씀
    path[lev] = 'o';
    run(lev + 1);
    path[lev] = 'x';
    run(lev + 1);
}

//void run(int lev) {
//    if(lev == n) {
//        cout << path << "\n";
//        return;
//    }
//
//    for(int i=0; i<4; i++) {
//        if(used[i] == 1) continue;
//        used[i] = 1;
//        path[lev] = arr[i] + '0';
//        run(lev + 1);
//        used[i] = 0;
//    }
//}
int main(int argc, const char * argv[]) {
    n = 4;
    run(0);
    return 0;
}
