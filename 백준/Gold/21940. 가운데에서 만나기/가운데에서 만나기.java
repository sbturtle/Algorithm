import java.io.*;
import java.util.*;

public class Main {

	static int INF = Integer.MAX_VALUE;
	static int n, m, k;

	static int[][] road;
	static int[] friends;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());

		road = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			Arrays.fill(road[i], INF);
			road[i][i] = 0;
		}

		while (m-- != 0) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());
			int c = Integer.parseInt(stt.nextToken());

			road[a][b] = c;
		}

		k = Integer.parseInt(br.readLine());
		friends = new int[k];
		stt = new StringTokenizer(br.readLine());

		for (int i = 0; i < k; i++)
			friends[i] = Integer.parseInt(stt.nextToken());

		for (int r = 1; r <= n; r++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j)
						continue;
					if (road[i][r] == INF || road[r][j] == INF)
						continue;
					int nv = (road[i][r] + road[r][j]);
					road[i][j] = Math.min(road[i][j], nv);
				}
			}
		}

		List<Integer> rList = new ArrayList<>();
		int result = INF;

		for (int i = 1; i <= n; i++) {
		    int mx = 0; 
		    boolean ok = true;

		    for (int f : friends) {
		        if (road[f][i] == INF || road[i][f] == INF) {
		            ok = false;
		            break;
		        }
		        mx = Math.max(mx, road[f][i] + road[i][f]);
		    }

		    if (!ok) continue;

		    if (result == mx) rList.add(i);
		    else if (result > mx) {
		        rList.clear();
		        result = mx;
		        rList.add(i);
		    }
		}
		
		Collections.sort(rList);

		for (int r : rList) {
			sb.append(r).append(' ');
		}
		System.out.println(sb);
	}
}