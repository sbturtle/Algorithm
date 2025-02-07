import java.util.PriorityQueue;
import java.io.*;
import java.util.StringTokenizer;


/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int T;
        T = Integer.parseInt(st.nextToken());

        for (int test_case = 1; test_case <= T; test_case++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            StringBuilder result = new StringBuilder();
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int op = Integer.parseInt(st.nextToken());

                if (op == 1) {
                    int num = Integer.parseInt(st.nextToken()) * -1;
                    pq.offer(num);
                } else {
                    if (pq.isEmpty())
                        result.append(-1);
                    else {
                        Integer num = pq.poll() * -1;
                        result.append(num);
                    }
                    result.append(" ");
                }
            }

            bw.write("#" + test_case + " " + result + "\n");
            bw.flush();
        }
        bw.close();
    }
}