import java.util.*;
import java.io.*;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            st = new StringTokenizer(br.readLine());

            long n= Long.parseLong(st.nextToken());
            long  result = 0;
            long  l = 0, r = 10000000000L;
            while (true) {
                long  md = (l + r) / 2;
                long  g = ((md * md) + md) / 2;
                if (g == n) {
                    result = md;
                    break;
                }
                if (l >= r) {
                    result = -1;
                    break;
                }
                else if (n > g)
                    l = md + 1;
                else if (n < g)
                    r = md - 1;
            }
            bw.write( "#" + test_case + " " + result + "\n");
            bw.flush();
        }
        bw.close();
    }
}