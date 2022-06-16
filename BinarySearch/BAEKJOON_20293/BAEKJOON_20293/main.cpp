//
//  main.cpp
//  BAEKJOON_20293
//  연료가 부족해
//  Created by 권영재 on 2022/06/15.
//

#include <iostream>
using namespace std;
int r, c, n;
bool is_possible(int mid) {
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> n;
    for (int i=0; i<n; i++) {
        int x, y, f;
        cin >> x >> y >> f;
    }
    int left, right, mid, ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (is_possible(mid)) {
            <#statements#>
        }
        else {
            
        }
    }
    return 0;
}
