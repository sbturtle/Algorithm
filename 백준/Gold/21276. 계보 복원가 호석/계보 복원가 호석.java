import java.util.*;
import java.io.*;

public class Main {

	static int n, m;

	static Map<String, Integer> nameToIdx;

	static String[] names;
	static int[] indegree;

	static List<Integer>[] list, child;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt;
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(br.readLine());

		nameToIdx = new HashMap<>();
		list = new List[n];
		child = new List[n];
		for (int i = 0; i < n; i++) {
			list[i] = new ArrayList<>();
			child[i] = new ArrayList<>();
		}

		// 이름 입력
		names = new String[n];
		stt = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			names[i] = stt.nextToken();

		Arrays.sort(names); // 사전순으로 정렬
		for (int i = 0; i < n; i++)
			nameToIdx.put(names[i], i);

		m = Integer.parseInt(br.readLine());
		indegree = new int[n];
		while (m-- != 0) {
			stt = new StringTokenizer(br.readLine());
			int a = nameToIdx.get(stt.nextToken());
			int b = nameToIdx.get(stt.nextToken());

			list[b].add(a);
			indegree[a]++;
		}

		List<String> roots = new ArrayList<>();
		Queue<Integer> q = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				roots.add(names[i]);
				q.offer(i);
			}
		}

		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt : list[cur]) {
				indegree[nxt]--;
				if (indegree[nxt] == 0) {
					child[cur].add(nxt);
					q.offer(nxt);
				}
			}
		}

		// 시조 출력
		sb.append(roots.size()).append('\n');
		for (String r : roots)
			sb.append(r).append(' ');
		sb.append('\n');

		// 전체 출력
		for (int i = 0; i < n; i++) {
			sb.append(names[i]).append(' ').append(child[i].size()).append(' ');
			Collections.sort(child[i]);
			for (int c : child[i]) {
				sb.append(names[c]).append(' ');
			}
			sb.append('\n');
		}

		System.out.println(sb);
	}
}
