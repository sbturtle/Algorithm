import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		long n1 = Long.parseLong(st.nextToken());
		long n2 = Long.parseLong(st.nextToken());

		long mx = Math.max(n1, n2);
		long mn = Math.min(n1, n2);

		sb.append(mx - (mn + 1)).append("\n");
		for (long i = mn + 1; i < mx; i++)
			sb.append(i).append(" ");

		if (mx == mn)
			System.out.println(0);
		else
			System.out.println(sb.toString());
	}
}
