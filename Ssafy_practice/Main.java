package Ssafy_practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static int[] visited;
    static int cnt = 1; // 방문 순서 저장 변수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        visited = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        // 오름차순정렬
        for (int i = 1; i < adj.size(); i++) {
            Collections.sort(adj.get(i), Collections.reverseOrder());
        }

        dfs(r);

        for (int i = 1; i < visited.length; i++) {
            sb.append(visited[i]).append("\n");
        }
        System.out.println(sb.toString());
    }

    // dfs
    static void dfs(int cur) {
        visited[cur] = cnt; // 현재 방문하고있는 정점에 순서 저장

        // 현재 위치한 정점이 갈 수 있는 정점 리스트를 순회
        for (int i = 0; i < adj.get(cur).size(); i++) {
            int next = adj.get(cur).get(i);

            // 다음 갈 정점을 방문했었는지 체크(0일 경우 방문 X)
            if (visited[next] == 0) {
                cnt++;
                dfs(next);
            }
        }
    }
}