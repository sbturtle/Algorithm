import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        long y = 0;
        long k = 0;
        while (t-- != 0) {
            for (int i = 0; i < 9; i++) {
                st = new StringTokenizer(br.readLine());
                y += Integer.parseInt(st.nextToken());
                k += Integer.parseInt(st.nextToken());
            }
            
            if (y < k) {
                System.out.println("Korea");
            } else if (y > k) {
                System.out.println("Yonsei");
            } else {
                System.out.println("Draw");
            }
        }
    }
}
