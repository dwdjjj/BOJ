//
//  main.cpp
//  BAEKJOON_3109_ bakery
//
//  Created by 권영재 on 2023/01/17.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c, ans = 0; // y : r까지 / x : c까지
bool flag;
vector<vector<char>> map;
vector<vector<bool>> visited;
int deltas[3][2] = {
    {-1, 1},
    {0, 1},
    {1, 1}
};

bool is_in_board(int y, int x) {
    if(y >= 0 && y < r && x >= 0 && x < c) return true;
    else return false;
}

// 0,0부터 우측으로, 끝까지 도달시 파이프 경로 설치. flag로 체크
void dfs(int y, int x) {
    visited[y][x] = true;
    if(x == c-1) {
        ans++;
        flag = true;
        return;
    }
    
    for(int i=0; i<3; i++) {
        int ny = y + deltas[i][0];
        int nx = x + deltas[i][1];
        if(is_in_board(ny, nx)) {
            if(map[ny][nx] == '.' && !visited[ny][nx]) {
                dfs(ny, nx);
                if(flag) return;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    
    map.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c));
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
//    for(int i=0; i<r; i++) {
//        string s;
//        cin >> s;
//        for(int j=0; j<c; j++) {
//            map[i][j] = s[j];
//        }
//    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
    
    for(int i=0; i<r; i++) {
        flag = false;
        dfs(i, 0);
    }
    
    cout << ans;
    
    return 0;
}
