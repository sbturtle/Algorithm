import java.io.*;
import java.util.*;

public class Main {

	static int T, n;
	static TreeMap<Integer, Integer> map = new TreeMap<>();

	private static void removeKey(int key) {
		if (map.get(key) == 1)
			map.remove(key);
		else
			map.put(key, map.get(key) - 1);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt;
		StringBuilder sb = new StringBuilder();

		T = Integer.parseInt(br.readLine());
		while (T-- != 0) {
			map.clear();
			n = Integer.parseInt(br.readLine());
			while (n-- != 0) {
				stt = new StringTokenizer(br.readLine());
				if (stt.nextToken().equals("I")) {
					int x = Integer.parseInt(stt.nextToken());
					map.put(x, map.getOrDefault(x, 0) + 1);
				} else {
					if (stt.nextToken().equals("1")) {
						if (!map.isEmpty())
							removeKey(map.lastKey());
					} else {
						if (!map.isEmpty())
							removeKey(map.firstKey());
					}
				}
			}
			if (map.size() == 0)
				sb.append("EMPTY");
			else
				sb.append(map.lastKey()).append(' ').append(map.firstKey());
			sb.append('\n');
		}

		System.out.println(sb);
	}
}