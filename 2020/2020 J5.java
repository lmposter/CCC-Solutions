import java.util.*;

public class Main {
    static final int MAX = 1005;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        
        int[][] room = new int[MAX][MAX];
        boolean[][] visited = new boolean[MAX][MAX];
        
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                room[i][j] = scanner.nextInt();
            }
        }
        
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(1, 1));
        visited[1][1] = true;

        while (!queue.isEmpty()) {
            Pair cell = queue.poll();
            int x = cell.x;
            int y = cell.y;
            int value = room[x][y];

            for (int i = 1; i * i <= value; ++i) {
                if (value % i == 0) {
                    int a = i;
                    int b = value / i;

                    if (a <= M && b <= N && !visited[a][b]) {
                        queue.add(new Pair(a, b));
                        visited[a][b] = true;
                    }

                    if (a <= N && b <= M && !visited[b][a]) {
                        queue.add(new Pair(b, a));
                        visited[b][a] = true;
                    }
                }
            }
        }

        if (visited[M][N]) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}