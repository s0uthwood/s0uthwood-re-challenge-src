import java.util.Scanner;

public class Chall {
    public static void main(String[] args) {
        System.out.println("Input your flag:");
        Scanner scan = new Scanner(System.in);
        String flag = scan.nextLine();
        byte f[] = flag.getBytes();
        int res = 0;
        byte cipher[] = {0x66, 0x6d, 0x63, 0x64, 0x7f, 0x4f, 0x67, 0x71, 0x69, 0x56, 0x66, 0x6a, 0x62, 0x6a, 0x7b, 0x6e, 0x77, 0x74, 0x6f};
        scan.close();
        if (f.length != cipher.length) {
            System.out.println("Wrong");
            return;
        }
        for (int i = 0; i < f.length; i++) {
            f[i] ^= i;
            res |= f[i] ^ cipher[i];
        }
        if (res != 0) {
            System.out.println("Wrong");
        } else {
            System.out.println("Good");
        }
    }
}
