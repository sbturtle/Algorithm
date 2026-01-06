import java.io.*;
import java.util.*;

public class Main {

    static int n, m, l;
    static int[] rest;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stt = new StringTokenizer(br.readLine());

        n = Integer.parseInt(stt.nextToken());
        m = Integer.parseInt(stt.nextToken());
        l = Integer.parseInt(stt.nextToken());

        rest = new int[n + 2];
        rest[0] = 0;
        rest[n + 1] = l;

        if (n > 0) {
            stt = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                rest[i] = Integer.parseInt(stt.nextToken());
            }
        }

        Arrays.sort(rest);

        int st = 1;
        int ed = l;
        int result = l;

        while (st <= ed) {
            int md = (st + ed) / 2;

            int cnt = 0;
            for (int i = 1; i < rest.length; i++) {
                int dist = rest[i] - rest[i - 1];
                cnt += (dist - 1) / md;
            }

            if (cnt > m) {
                st = md + 1;
            } else {
            	result = md;
                ed = md - 1;
            }
        }

        System.out.println(result);
    }
}
