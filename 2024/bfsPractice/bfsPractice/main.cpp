//
//  main.cpp
//  bfsPractice
//
//  Created by 권영재 on 2024/03/05.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int>> d;
// bool isInBoard(int y, int x) {
    
// }

void bfs(vector<vector<int>> maps) {
    queue<pair<int, int>> q;
    q.push({0,0});
    pair<int ,int> cur;
    d.resize(maps.size(), vector<int>(maps[0].size(), 0));
    int ny, nx;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            ny = cur.first + dy[i]; nx = cur.second + dx[i];
            if(ny>= 0 && nx >= 0 && ny < maps.size() && nx < maps[0].size()) {
                if(maps[ny][nx] == 1 && d[ny][nx] == 0) {
                    q.push({ny, nx});
                    d[ny][nx] = d[cur.first][cur.second] + 1;
                    cout << d[ny][nx] << "\n";
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> maps;
    maps.resize(5, vector<int>(5, 0));
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> maps[i][j];
        }
    }
    
    int answer = 0;
    bfs(maps);
    answer = d[maps.size()-1][maps[0].size()-1];
    cout << answer;
    
    return 0;
}
