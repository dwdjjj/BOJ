import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1238_권영재 {
    static int n, start, ans, depth;
    static ArrayList<Integer> adjList[];
    static int visited[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb;
        for (int test_case = 1; test_case <= 10; test_case++) {
            // 초기화
            adjList = new ArrayList[100 + 1];
            for (int i = 1; i <= 100; i++) {
                adjList[i] = new ArrayList<>();
            }
            visited = new int[100 + 1];
            StringTokenizer st = null;
            depth = 0;
            ans = 0;
            sb = new StringBuilder();

            // 첫줄 입력
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken()); // 입력 데이터 길이
            start = Integer.parseInt(st.nextToken()); // 시작점

            // 둘째줄 입력
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n / 2; i++) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                adjList[from].add(to); // 간선 입력 정보 넣기
            }

            // 시작점으로부터 bfs 탐색
            bfs(start);

            sb.append("#").append(test_case).append(" ").append(ans);
            System.out.println(sb.toString());
        }
    }

    static int bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = 1;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 0; i < adjList[cur].size(); i++) {
                int next = adjList[cur].get(i);
                if (visited[next] != 0)
                    continue;
                visited[next] = visited[cur] + 1;
                q.offer(next);
            }
            depth = visited[cur];
        }

        for (int i = 1; i <= 100; i++) {
            if (depth != visited[i])
                continue;
            ans = ans > i ? ans : i;
        }
        return ans;
    }
}
