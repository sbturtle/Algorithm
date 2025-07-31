import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(st.nextToken());

		Deque<Integer> s = new ArrayDeque<>();
		while (t-- != 0) {
			s.clear();
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();

			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			String input = st.nextToken();
			String[] strArr = input.substring(1, input.length() - 1).split(",");

			if (strArr.length != 0)
				for (int i = 0; i < n; i++)
					s.add(Integer.parseInt(strArr[i]));

			boolean isQ = true;
			boolean isErr = false;
			
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == 'R')
					isQ = !isQ;
				else {
					if (s.isEmpty()) {
						sb.append("error\n");
						isErr = true;
						break;
					} else if (isQ) {
						s.pollFirst();
					} else {
						s.pollLast();
					}
				}
			}
			if(isErr)
				continue;
			
			sb.append("[");
			while (!s.isEmpty()) {
				sb.append(isQ ? s.pollFirst() : s.pollLast());
				if (!s.isEmpty())
					sb.append(",");
			}
			sb.append("]\n");
		}

		System.out.println(sb.toString());
	}

}
