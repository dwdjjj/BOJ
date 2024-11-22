package Ssafy_practice;

import java.util.Scanner;

public class Solution2105 {
    static int[] dr = { 1, 1, -1, -1 };
    static int[] dc = { 1, -1, -1, 1 };
    static int T, n, ans;
    static int[][] arr;
    static boolean[] eat;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            n = sc.nextInt();
            arr = new int[n][n];
            eat = new boolean[100 + 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            ans = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    go(i, j, i, j, 0, 1); // i,j부터 하나 먹어보고 이동
                }
            }

            System.out.println("#" + tc + " " + ans);

        }
        sc.close();

    }

    static void go(int startR, int startC, int nowR, int nowC, int dir, int cnt) {
        eat[arr[nowR][nowC]] = true; // 현재 번호 방문체크

        for (int d = dir; d < 4; d++) {
            int nextR = nowR + dr[d];
            int nextC = nowC + dc[d];

            if (!isInBoard(nextR, nextC)) // 벗어나면
                continue;

            if (eat[arr[nextR][nextC]]) {
                if (startR == nextR && startC == nextC && cnt >= 4) {
                    ans = Math.max(ans, cnt);

                }
            } else
                go(startR, startC, nextR, nextC, d, cnt + 1);

        }

        eat[arr[nowR][nowC]] = false;

    }

    static boolean isInBoard(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

}
