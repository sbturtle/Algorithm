import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// 관리인은 오른쪽만 본다.
		// 높거나 같으면 못봄
		int n = Integer.parseInt(st.nextToken());

		int[] b = new int[n];
		int[] size = new int[n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			b[i] = Integer.parseInt(st.nextToken());
		}

		Deque<Integer> s = new ArrayDeque<>();

		long sum = 0;

		s.push(n - 1);

		for (int i = n - 2; i >= 0; i--) {
			int old = s.peek();

			while (b[old] < b[i]) { // 이전 빌딩이 현재 빌딩보다 작은 경우
				size[i] += size[old];
				s.pop();
				size[i]++;
				if (s.isEmpty()) {
					break;
				}
				old = s.peek();
			}
			sum += size[i];
			s.push(i);
		}

		System.out.println(sum);
	}
}
