import java.util.Scanner;

public class FeetToMetersConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Plese enter the length in feet: ");
        float feet = scanner.nextFloat();

        float meters = convertFeetToMeters(feet);

        System.out.println(feet + " feet is equal to " + meters + " meters.");

        scanner.close();
    }

    public static float convertFeetToMeters(float feet) {
        return feet * 0.305f;
    }
}
