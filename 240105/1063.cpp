#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, 1, -1 ,-1};

map<string, int> dirMap = {
    {"R", 0},
    {"L", 1},
    {"B", 2},
    {"T", 3},
    {"RT", 4},
    {"LT", 5},
    {"RB", 6},
    {"LB", 7},
};

bool isInBoard(int x, int y, int a, int b) {
    if(x < a || x > b || y < a+1 || y > b+1)
        return false;
    else
        return true;
}

int main()
{
    int kingX, kingY, stoneX, stoneY, dir, num;
    string s;
    char king, stone;
    cin >> king >> kingY >> stone >> stoneY >> num;
    kingX = king - 'A';
    stoneX = stone - 'A';

    for (int i = 0; i < num; i++)
    {
        cin >> s;
        dir = dirMap.at(s);
        int x = kingX + dx[dir];
        int y = kingY + dy[dir];

        if(!isInBoard(x, y, 0, 7)) continue;
        // if(x < 0 || x > 7 || y <= 0 || y > 8)
        //     continue;
        
        if(x == stoneX && y == stoneY) {
            int sX = stoneX + dx[dir];
            int sY = stoneY + dy[dir];
            if(!isInBoard(sX, sY, 0, 7)) continue;
            stoneX = sX;
            stoneY = sY;
        }

        kingX = x;
        kingY = y;
    }
    king = (char)(kingX + 'A');
    stone = stoneX + 'A';
    cout << king << kingY << "\n";
    cout << stone << stoneY << "\n";

    return 0;
}