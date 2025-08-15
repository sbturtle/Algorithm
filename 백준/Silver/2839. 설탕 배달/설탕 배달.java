import java.io.*;
import java.util.*;

public class Main {
	static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		n = Integer.parseInt(br.readLine());

		int f = n / 5;
		int t = (n % 5) / 3;

		int result = -1;
		while (f >= 0) {
			int sum = (f * 5) + (t * 3);
			if (sum == n) {
				result = f + t;
				break;
			}
			f--;
			t = (n - (f * 5)) / 3;
		}

		System.out.println(result);

	}
}
