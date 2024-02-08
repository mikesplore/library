import java.util.Scanner;

public class DigitSumCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter any integer between 0 and 1000: ");
        int number = scanner.nextInt();

        int sum = 0;

        while (number != 0) {
            sum += number % 10; 
            number /= 10; 
        }

        System.out.println("The sum of all digits in the integer is: " + sum);

        scanner.close();
    }
}
