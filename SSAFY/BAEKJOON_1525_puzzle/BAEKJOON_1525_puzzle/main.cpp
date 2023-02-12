//
//  main.cpp
//  BAEKJOON_1525_puzzle
//
//  Created by 권영재 on 2023/01/20.
//

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[3][3];
string s;
bool is_in_board(int y, int x) {
    if(y>=0 && y <= 2 && x>=0 && x<= 2) return true;
    else return false;
}

int bfs(string s) {
    queue<string> q;
    q.push(s);
    
    while(!q.empty()) {
        string s = q.front();
        q.pop();
        if(s == "123456780") return m[s]; // 3x3배열안쓰고 1차원으로 맞추기
        
        auto x = s.find('0'); // 문자열 s에서 0이 있는 index반환 -> 0위치의 상하좌우만 서로 교환 가능
        for(int i=0; i<4; i++) {
            int ny = x / 3 + dy[i]; // 3x3에서의 0 행번호
            int nx = x % 3 + dx[i]; // 0의 열번호
            if(!is_in_board(ny, nx)) continue;
            string tmp = s;
            swap(tmp[x], tmp[(3 * ny) + nx]);
            if(!m[tmp]) {
                m[tmp] = m[s] + 1;
                q.push(tmp);
            }
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
            s += arr[i][j] + '0';
        }
    }
    
    cout << bfs(s);
    return 0;
}
