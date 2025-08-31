import java.io.*;
import java.util.*;

public class Main {
    static int[][] map;
    static boolean[] isvis;
    static int n, result = Integer.MAX_VALUE;

    static void func(int st, int idx, int cnt, int sum) {
        if(cnt == n && map[idx][st] != 0) {
            result = Math.min(result, sum + map[idx][st]);
            return;
        }

        for(int i=0; i<n; i++) {
            if(!isvis[i] && map[idx][i] != 0) {
                isvis[i] = true;
                func(st, i, cnt+1, sum + map[idx][i]);
                isvis[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        isvis = new boolean[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            isvis[i] = true;
            func(i, i, 1, 0);
            isvis[i] = false;
        }

        System.out.println(result);
    }
}
