import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_15683_권영재 {
    static int n, m, ans = Integer.MAX_VALUE;
    static int dr[] = { -1, 0, 1, 0 };
    static int dc[] = { 0, -1, 0, 1 };

    static class CCTV {
        int type;
        int r;
        int c;
        int dupCheck;

        public CCTV(int type, int r, int c, int dupCheck) {
            this.type = type;
            this.r = r;
            this.c = c;
            this.dupCheck = dupCheck;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];

        ArrayList<CCTV> cctvList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] != 0 && map[i][j] != 6) {
                    // CCTV마다 감시하는 영역을 표시하기 위한 dupCheck 고유값 생성
                    int dupCheck = Integer.parseInt(String.valueOf("7") + String.valueOf(i) + String.valueOf(j));
                    // 리스트에 CCTV 정보 저장
                    cctvList.add(new CCTV(map[i][j], i, j, dupCheck));
                }
            }
        }

        // CCTV감시 범위 체크를 재귀로 돌기
        f(cctvList, 0, map);

        System.out.println(ans);
    }

    static void f(ArrayList<CCTV> cctvList, int idx, int map[][]) {
        if (idx >= cctvList.size()) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) {
                        tmp++;
                    }
                }
            }
            // 모든 cctv를 돌려 감시하고 사각지대가 가장 적은 값으로 갱신
            ans = Math.min(tmp, ans);
            return;
        }

        // idx번째 cctv 불러오기
        CCTV cctv = cctvList.get(idx);

        for (int d = 0; d < 4; d++) {
            // cctv감시범위 체크
            checkRange(cctv.type, cctv.r, cctv.c, cctv.dupCheck, d, map);

            // 다음 cctv재귀
            f(cctvList, idx + 1, map);

            // 방문체크한거 해제해주기
            checkRange(cctv.type, cctv.r, cctv.c, cctv.dupCheck, d, map);
        }
    }

    static void checkRange(int type, int r, int c, int check, int d, int map[][]) {
        if (type == 1)
            watching(r, c, d, check, map);
        if (type == 2) {
            watching(r, c, d, check, map);
            watching(r, c, (d + 2) % 4, check, map);
        }
        if (type == 3) {
            watching(r, c, d, check, map);
            watching(r, c, (d + 1) % 4, check, map);
        }
        if (type == 4) {
            watching(r, c, d, check, map);
            watching(r, c, (d + 3) % 4, check, map);
            watching(r, c, (d + 1) % 4, check, map);
        }
        if (type == 5) {
            for (int i = 0; i < 4; i++) {
                watching(r, c, i, check, map);
            }
        }
    }

    static void watching(int r, int c, int d, int check, int map[][]) {
        // 벽볼때까지
        while (map[r][c] != 6) {
            r = r + dr[d];
            c = c + dc[d];

            if (!is_in_board(r, c))
                break;

            // 다음호출로 방문했던(저장한) check는 다시 빈칸으로 변경 (중복 체크)
            if (map[r][c] == 0)
                map[r][c] = check;
            else if (map[r][c] == check)
                map[r][c] = 0;
        }
    }

    static boolean is_in_board(int r, int c) { // 범위체크
        return r >= 0 && r < n && c >= 0 && c < m;
    }
}
