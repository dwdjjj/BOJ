
package Ssafy_practice;

import java.util.Scanner;

/**
 * SWEA5650
 */
public class SWEA5650 {
    static int T, n, ans;
    static int[][] board;
    static int[] dr = { -1, 0, 1, 0 }; // 위 왼 아 오
    static int[] dc = { 0, -1, 0, 1 };
    static int[][] blocks = {
            {},
            { 3, -1, -1, 0 },
            { -1, -1, 3, 2 },
            { -1, 2, 1, -1 },
            { 1, 0, -1, -1 },
            { -1, -1, -1, -1 }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            n = sc.nextInt();
            board = new int[n + 2][n + 2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    board[i][j] = sc.nextInt();
                }
            }

            ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = -1; // 도착점(블랙홀)로 취급
                        for (int d = 0; d < 4; d++) {
                            ans = Math.max(f(i, j, d), ans);
                        }
                        board[i][j] = 0; // 출발지로 택한 곳 원래대로 돌리기
                    }
                }
            }
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }

    static int f(int startR, int startC, int dir) {
        int cnt = 0;
        while (true) {
            boolean moved = false;
            int r = startR, c = startC;
            while (true) { // 해당 방향으로 쭉가보고
                int nextR = r + dr[dir];
                int nextC = c + dc[dir];
                if ((!isInBoard(r, c) || board[r][c] != 0) && moved) // 벗어나거나 빈칸이 아니면
                    break;
                r = nextR; // 지금 칸의 번호에 맞는 동작 위해 현 위치 저장
                c = nextC;
                moved = true;
            }

            // // 기저 : (시작)블랙홀이면 종료
            // if (board[r][c] == -1)
            // return cnt;
            // 벽이면?
            if (!isInBoard(r, c)) {
                dir = (dir + 2) % 4;
                cnt++;
                startR = r;
                startC = c;
            }
            // 블록이면
            else if (board[r][c] >= 1 && board[r][c] <= 5) {
                cnt++;
                startR = r;
                startC = c;
                int blockType = board[r][c];
                // 평평한벽
                if (blocks[blockType][(dir + 2) % 4] == -1)
                    dir = (dir + 2) % 4;
                else // 경사에 반사된 방향 유지
                    dir = blocks[blockType][(dir + 2) % 4];

            }
            // 웜홀이면 같은 번호 다른 웜홀로 이동
            else if (board[r][c] >= 6 && board[r][c] <= 10) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        // 맵에서 값이 같고 좌표가 다른 웜홀
                        if (board[r][c] == board[i][j] && !(r == i && c == j)) {
                            startR = i;
                            startC = j;
                        }
                    }

                }
            } else
                break;
        }
        return cnt;

    }

    static boolean isInBoard(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
}
