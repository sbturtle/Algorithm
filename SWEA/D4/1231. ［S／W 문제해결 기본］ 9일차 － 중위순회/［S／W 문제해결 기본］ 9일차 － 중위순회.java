import java.io.*;
import java.util.StringTokenizer;

class Solution {

    static char[] values;
    static int[] left;
    static int[] right;

    public static void main(String args[]) throws IOException {
        int T = 10;


        String result = "";
        // System.setIn(new FileInputStream("input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        for (int test_case = 1; test_case <= T; test_case++) {
            values = new char[101];
            left = new int[101];
            right = new int[101];

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int idx = Integer.parseInt(st.nextToken());
                values[idx] = st.nextToken().charAt(0);

                left[idx] = (st.hasMoreTokens()) ? Integer.parseInt(st.nextToken()) : -1;
                right[idx] = (st.hasMoreTokens()) ? Integer.parseInt(st.nextToken()) : -1;

            }
            result = inorder(1);

            bw.write("#" + test_case + " " + result + "\n");
            bw.newLine();

            bw.flush();
        }
        bw.close();
    }

    public static String inorder(int idx) {
        if(idx == 0 || idx == -1) return "";
        String result = "";
        result += inorder(left[idx]);
        result += values[idx];
        result += inorder(right[idx]);

        return result;
    }
}