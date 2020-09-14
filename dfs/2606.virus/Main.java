import java.util.Scanner;

public class Main {
    static int R = 0;
    static int N;
    static int M;
    static boolean A[][];
    static boolean V[];

    static void solve(int i) {
        V[i] = true;

        for (int j = 2; j <= N; j++)
            if (!V[j] && A[i][j])
                solve(j);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        N = scanner.nextInt();
        M = scanner.nextInt();
        A = new boolean[N+1][N+1];
        V = new boolean[N+1];

        for (int i = 0; i < N; i++) {
            V[i]  = false;

            for (int j = 0; j < N; j++)
                A[i][j] = false;
        }

        for (int m = 0; m < M; m++) {
            int i = scanner.nextInt();
            int j = scanner.nextInt();

            A[i][j] = A[j][i] = true;
        }

        solve(1);

        for (int i = 2; i <= N; i++)
            if (V[i])
                R++;

        System.out.println(R);
    }
}
