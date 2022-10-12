//5번 삼분값
//
//삼분값
//  소마는 코딩테스트를 준비하기 위해 중앙값을 구하는 알고리즘 문제를 풀던 도중, 삼분값 아이디어가 떠올랐다!! 삼분값이란, 3N + 2 개의 수를 오름차순으로 정렬 시 13 지점의 수와 23 지점의 수를 말한다. 즉, 삼분값을 기준으로 나뉜 세 개의 수열의 길이는 모두 N이다. 예를 들어, 1, 2, 3, 4, 5의 수열에서 삼 분값은 2와 4 이고, 3, 1, 5, 8, 2, 7, 4, 6의 수열에서 삼분값은 3과 6이다.
//  수열에 속한 수 2개와 수열에 수가 3개씩 N번 추가될 때, 각각의 삼분값을 오름차순으로 출력하세요.
//
//입력
//첫 번째 줄에 수열에 속한 두 수가 주어진다.
//-10,000  a, b  10,000
//두 번째 줄에 N이 주어진다.
//1  N  100,000
//세 번째 줄 부터 N줄에 걸쳐 추가되는 수열의 세 수가 주어진다.
//-10,000  x, y, z  10,000
//출력
//N번에 걸쳐 수가 추가될 때마다 삼분값을 오름차순으로 출력하세요.
//
//입력 예시
//2 5
//2
//4 1 7
//3 8 6
//
//출력 예시
//2 5
//3 6

// 우선순위 큐로 풀면 시간복잡도 logN
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int a, b, n;
vector<int> v;
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int main() {
    cin >> a >> b;
    max_heap.push(a); min_heap.push(b);
    cin >> n;
    while (n--) {
        int x; cin >> x;
        
        if (max_heap.size() == min_heap.size()) max_heap.push(x);
        else min_heap.push(x);
        
        if (max_heap.top() > min_heap.top()) {
            int M = max_heap.top(), m = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            
            max_heap.push(m);
            min_heap.push(M);
        }
        cout << max_heap.top() << " " << min_heap.top() << "\n";
    }
    // 1 2 3 4 5
    // 12 3 45 6 78
    if(max_heap.size() > min_heap.size()) max_heap.pop();
    cout << max_heap.top() << " " << min_heap.top() << "\n";
    
//    for(int i=0; i<n; i++) {
//        int x, y, z;
//        cin >> x >> y >> z;
//        v.push_back(x); v.push_back(y); v.push_back(z);
//        sort(v.begin(), v.end());
//        int tmp = (v.size() - 2)/3;
//        cout << v[tmp] << " " << v[1 + tmp*2];
//        cout << "\n";
//    }
//
    // 5개면 3*1 + 2개 있을 때고, 두번째 네번째 출력 == 1, 3
    // 1 2 4 5 7
    // 8개면 3*2 + 2개 있을 때고, 3, 6번째 출력 == 2, 5
    // 1 2 3 4 5 6 7 8
    // 11개면? 3*3 + 2개 있을 때, 4, 8번째 출력 == 3, 7
    // 3*4 + 2 = 14 => 1234 5 6789 10 11121314
    return 0;
}
