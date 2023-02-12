import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

// 백준 - 1062. 가르침
// 조합 + 방문체크 or 조합 + 비트마스킹
// 방문체크 비트마스크로 대체가능!
public class Main_1062 {
    static int n, k;
    static String word[];
    static int ans = Integer.MIN_VALUE; // int형의 가장 최솟값 약 -21억
    static boolean selectAlpha[];
    static ArrayList<Character> list;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken()) - 5;

        selectAlpha = new boolean[26];
        // anta ~ tica 고정 -> a, c, i, n, t 최소 5개 배워야 읽을 수 있음.
        // 5개는 뽑았다 치고
        for (char c : new char[] { 'a', 'c', 'i', 'n', 't' }) {
            selectAlpha[c - 'a'] = true;
        }

        word = new String[n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            word[i] = s.substring(4, s.length() - 4);
            // 앞 네글자 anta와 뒤 네개 tica 자르기
        }

        // 가르치는 알파벳수가 5개미만이면(acint제외시에 0보다 작다면)
        if (k < 0) {
            System.out.println(0);
            return;
        }

        // 이후 남은 가운데 문자들을 중복없는 리스트로 만들어주고
        list = getList();

        // r개를 골라 체크 <-- 조합으로
        if (list.size() <= k) // 배워야할 단어가 배울 수 있는 단어보다 적다면 모든 단어 읽을 수 있음.
            ans = n;
        else
            comb(0, 0);

        System.out.println(ans);
    }

    private static ArrayList<Character> getList() {
        HashSet<Character> set = new HashSet<>(); // 중복없이 알파벳 저장 목적
        ArrayList<Character> res = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < word[i].length(); j++) {
                char c = word[i].charAt(j);
                if (!selectAlpha[c - 'a']) // acint이외의 알파벳 중 방문하지 않은애 저장
                    set.add(c);
            }
        }
        res.addAll(set);
        return res;
    }

    private static void calcMin() {
        int cnt = 0;
        boolean flag;
        for (int i = 0; i < n; i++) {
            flag = true;
            for (int j = 0; j < word[i].length(); j++) {
                char c = word[i].charAt(j);
                if (!selectAlpha[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
        ans = cnt > ans ? cnt : ans;
    }

    private static void comb(int start, int depth) throws IOException {
        if (depth == k) {
            calcMin();
            return;
        }

        for (int i = start; i < list.size(); i++) {
            char c = list.get(i);
            selectAlpha[c - 'a'] = true;
            comb(i + 1, depth + 1);
            selectAlpha[c - 'a'] = false;
        }
    }
}