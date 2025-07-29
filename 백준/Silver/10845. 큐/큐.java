import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        Deque<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            String input = br.readLine();

            if (input.startsWith("push")) {
                int x = Integer.parseInt(input.split(" ")[1]);
                queue.addLast(x);
            } else if (input.equals("pop")) {
                sb.append(queue.isEmpty() ? -1 : queue.pollFirst()).append("\n");
            } else if (input.equals("size")) {
                sb.append(queue.size()).append("\n");
            } else if (input.equals("empty")) {
                sb.append(queue.isEmpty() ? 1 : 0).append("\n");
            } else if (input.equals("front")) {
                sb.append(queue.isEmpty() ? -1 : queue.peekFirst()).append("\n");
            } else if (input.equals("back")) {
                sb.append(queue.isEmpty() ? -1 : queue.peekLast()).append("\n");
            }
        }

        System.out.print(sb);
    }
}
