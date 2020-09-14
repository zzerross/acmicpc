import java.util.Random;

public class Sample {
    public static void main(String[] args) {
        Random r = new Random();

        int n = 1 + r.nextInt(100);

        System.out.println(n);

        int c = 1 + r.nextInt(n);

        System.out.println(c);

        for (int i = 0; i < c; i++) {
            int a = 1 + r.nextInt(n);
            int b = 1 + r.nextInt(n);

            System.out.println(a + " " + b);
        }
    }
}
