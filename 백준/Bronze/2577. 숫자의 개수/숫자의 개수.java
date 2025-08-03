import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int[] num = new int[10];

		long n1 = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long n2 = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long n3 = Long.parseLong(st.nextToken());

		long sum = n1 * n2 * n3;

		char[] str = Long.toString(sum).toCharArray();

		for (int i = 0; i < str.length; i++) {
			num[str[i] - '0']++;
		}

		for (int i = 0; i < num.length; i++) {
			sb.append(num[i]).append("\n");
		}

		System.out.println(sb.toString());
	}
}
