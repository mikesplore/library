import java.util.Scanner;

public class IntegerSorter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter the first integer: ");
        int num1 = scanner.nextInt();

        System.out.print("Please enter the second integer: ");
        int num2 = scanner.nextInt();

        System.out.print("Please enter the third integer: ");
        int num3 = scanner.nextInt();

        if (num1 > num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if (num2 > num3) {
            int temp = num2;
            num2 = num3;
            num3 = temp;
        }
        if (num1 > num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        
        System.out.println("Sorted numbers: " + num1 + " <= " + num2 + " <= " + num3);

        scanner.close();
    }
}
