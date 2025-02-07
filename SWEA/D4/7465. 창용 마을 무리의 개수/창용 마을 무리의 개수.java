import java.io.*;
import java.util.StringTokenizer;

class Solution {
    static int[] relationship;

    public static void main(String args[]) throws IOException {
        //System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T;
        T = Integer.parseInt(st.nextToken());
        for (int test_case = 1; test_case <= T; test_case++) {
            int result = 0;
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            relationship = new int[n + 1];
            for (int i = 0; i < n; i++)
                relationship[i] = -1;

            for (int i = 1; i <= m; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                uni(a, b);
            }

            for (int i = 0; i < n; i++) {
                if (relationship[i] < 0) result++;
            }

            bw.write("#" + test_case + ' ' + result + '\n');
            bw.flush();
        }
        bw.close();
    }

    public static int find(int x) {
        if (relationship[x] < 0) return x;
        return relationship[x] = find(relationship[x]);
    }

    public static void uni(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (u > v)
            v = swap(u, u = v);

        relationship[u]--;
        relationship[v] = u;
    }

    public static int swap(int a, int b) {
        return a;
    }
}