package Ssafy_practice.Ssafy_practice;

import java.util.Scanner;

public class Main_2567 {
    static int n, ans;
    static int arr[][];
    static int dx[] = { 0, 0, 1, -1 };
    static int dy[] = { -1, 1, 0, 0 };

    // 영역 체크
    static void check(int x, int y) {
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }

    static boolean is_in_board(int x, int y) {
        return x >= 0 && x <= 100 && y >= 0 && y <= 100;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[100 + 1][100 + 1];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            check(x, y);
        }

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                // 배열에 1로 체크된 곳에서 4방탐색. 0인 부분은 모서리이므로 둘레의 길이를 증가시킴
                if (arr[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int nextX = i + dx[d];
                        int nextY = j + dy[d];
                        if (arr[nextX][nextY] == 0 || !is_in_board(nextX, nextY))
                            ans++;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
