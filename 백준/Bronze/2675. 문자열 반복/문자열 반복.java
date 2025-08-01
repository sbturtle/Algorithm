import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(st.nextToken());

		while (t-- != 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			char[] str = st.nextToken().toCharArray();

			for (int i = 0; i < str.length; i++) {
				for (int j = 0; j < n; j++) {
					sb.append(str[i]);
				}
			}

			sb.append("\n");
		}

		System.out.println(sb.toString());
	}

}
