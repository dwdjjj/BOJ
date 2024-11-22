import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main_2493 {
    static int arr[];

    public static void main(String[] args) throws NumberFormatException, IOException {
        // 6 9 5 7 4
        // 4(5번째탑)부터 7과 비교
        // 7이 4보다 크니까 7(4번째 탑이) 4를 수신
        // 이후 7, 5는 9(2번째 탑)기 수신
        Stack<Integer> s = new Stack<>(); // Stack<int[]>
        Stack<Integer> res = new Stack<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[n];
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            if (s.size() > 0) {
                int top = s.peek();
                if (top > maxVal)
                    maxVal = top;
                if (x < maxVal) {
                    while (x > s.peek()) {
                        s.pop();
                        res.pop();
                    }
                    arr[i] = res.peek();
                }
            }
            s.push(x);
            res.push(i + 1);
        }
        for (int i = 0; i < n; i++) {
            bw.write(arr[i] + " ");
        }
        bw.close();

    }
}