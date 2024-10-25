package Sum;
import java.util.Scanner;

class Sum {
    public static void main(String[] args){
        try (Scanner s = new Scanner(System.in)) {
            int a=s.nextInt();
            int b=s.nextInt();
            System.out.println(a+b);
        }
    }
}
