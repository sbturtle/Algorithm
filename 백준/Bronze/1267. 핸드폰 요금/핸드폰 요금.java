import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int y = 0;
		int m = 0;

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int c = Integer.parseInt(st.nextToken());
			y += 10 * (c / 30) + 10;
			m += 15 * (c / 60) + 15;
		}

		if (y > m)
			System.out.println("M " + m);
		else if (y == m)
			System.out.println("Y M " + m);
		else
			System.out.println("Y " + y);
	}
}
