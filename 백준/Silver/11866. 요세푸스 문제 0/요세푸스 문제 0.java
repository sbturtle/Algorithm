import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		sb.append("<");
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		Deque<Integer> q = new ArrayDeque<>();
		
		for (int i = 1; i <= n; i++) {
			q.add(i);
		}

		int idx = 1;
		while(!q.isEmpty()) {
			int cur = q.poll();
			
			if(q.size() == 0) {
				sb.append(cur).append(">");
				break;
			}
			
			if(idx++ % k == 0) {
				sb.append(cur).append(", ");
				continue;
			}
			q.add(cur);
		}
		
		System.out.println(sb.toString());
	}

}
