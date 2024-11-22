package Ssafy_practice;

import java.util.Scanner;

public class Solution_핀볼게임 {
	// int[][] map; 혹시 원본 훼손하면서 시뮬레이션 하느라 deepcopy 필요없나?
	// int N; 지도 크기
	// int[] di, dj = {상, 좌, 하 ,우};
	// int ans; // 가능한 최대점수
	// int[][] blocks = 1~5까지.
	static int N;
	static int[][] map;
	static int[] di = { -1, 0, 1, 0 }; // 상:0,좌:1,하:2,우:3
	static int[] dj = { 0, -1, 0, 1 };
	static int ans;
	static int[][] blocks = { // 블럭번호 1~5
			{},
			{ 3, -1, -1, 0 },
			{ -1, -1, 3, 2 },
			{ -1, 2, 1, -1 },
			{ 1, 0, -1, -1 },
			{ -1, -1, -1, -1 } };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int TC = sc.nextInt();
		for (int tc = 1; tc <= TC; tc++) {
			N = sc.nextInt();

			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			} // end input

			// start
			ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == 0) { // i,j에서 4방향으로 출발시켜 보자.
						map[i][j] = -1; // 출발점이나 블랙홀이나 게임오버는 같으니 같은상태 만들기
						for (int dir = 0; dir < 4; dir++) { // 상:0,좌:1,하:2,우:3
							// 출발
							ans = Math.max(start(i, j, dir), ans);
						} // end while
						map[i][j] = 0; // 새로운 출발을 위해 출발점 돌려놓기
					}
				}
			}
			System.out.println("#" + tc + " " + ans);
		} // end TC
	} // end main

	//////////////////////////////////////////////////////////////////////
	private static int start(int si, int sj, int dir) {
		int score = 0;
		while (true) {
			boolean move = false; // 처음에는 빈칸 출발인데 나중에는 블럭에서도 출발함;; 그때는 멈춤조건 안걸려야됨.
			int nowi = si, nowj = sj; // 자 여기서 출발이다.

			while (true) {// 일단 직진할수 있는 만큼 직진
				int nexti = nowi + di[dir]; // 아직 옆칸 안가고 일단 계산만
				int nextj = nowj + dj[dir];
				if ((nowi < 0 || nowi >= N || nowj < 0 || nowj >= N || map[nowi][nowj] != 0) && move) // 멈춰!!!
					break;
				nowi = nexti; // 나 이상한칸 아닌 곳에 있어. 그 칸으로 이동
				nowj = nextj;
				move = true;
			}

			// 나 어딘가에 멈췄다는 거네? 현재 서있는 곳은 빈칸은 아니다. 즉 nowi, nowj가 이상한 칸이라는 거임.
			// 1. 벽에 부딪힌 경우(배열 벗어난거 먼저 검사하는게 좋음!)
			if (nowi < 0 || nowi >= N || nowj < 0 || nowj >= N) { // 벽 - 거기서 반대 방향으로 출발(점수)
				score++;
				dir = (dir + 2) % 4; // 벽은 반대방향이고
				si = nowi; // 지금 내 위치에서 다시 반대방향으로 출발하면 됨.
				sj = nowj;
			} else if (map[nowi][nowj] >= 1 && map[nowi][nowj] <= 5) { // 2. 블럭에 부딪힌 경우
				score++;
				int block = map[nowi][nowj];
				si = nowi;
				sj = nowj;
				if (blocks[block][(dir + 2) % 4] == -1) { // 수직벽
					dir = (dir + 2) % 4;
				} else { // 경사면(블럭위치 유지)
					dir = blocks[block][(dir + 2) % 4];
				}
			} else if (map[nowi][nowj] >= 6 && map[nowi][nowj] <= 10) { // 웜홀 - 자기랑 다른 칸 같은번호 찾아서 출발
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (map[nowi][nowj] == map[i][j] && !(nowi == i && nowj == j)) {
							si = i;
							sj = j;
						}
					}
				}
			} else { // 4. 게임오버(배열바깥이 아닌데 블럭1~5도 아니고 웜홀 6~10도 아니면 ? -1밖에 없지 뭐)
				break;
			}
		}
		return score;
	}
}
