package zhuhonglin.website.A1001;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        String rst = "";
        boolean flag = true;
        int num = a + b;
        if (num == 0) {
            System.out.println("0");
            return;
        }
        if (num < 0) {
            flag = false;
            num = -num;
        }
        int cnt = 0;
        int x;
        while (num != 0) {
            x = num % 10;
            num /= 10;
            rst = rst + String.valueOf(x);
            cnt++;
            if (cnt == 3) {
                cnt = 0;
                rst += ",";
            }
        }

        if (!flag) {
            System.out.printf("-");
        }
        int len = rst.length();
        for (int i = len - 1; i >= 0; i--) {
            if (i == len - 1 && rst.charAt(i) == ',') {
                continue;
            }
            System.out.printf("%c", rst.charAt(i));
        }
        System.out.println("");
    }
}
