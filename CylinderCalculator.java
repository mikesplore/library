import java.util.Scanner;

public class CylinderCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter the radius of the cylinder: ");
        float radius = scanner.nextFloat();

        System.out.print("Please enter the length of the cylinder: ");
        float length = scanner.nextFloat();

        float area = (float) (Math.PI * radius * radius);
        float volume = area*length;

        System.out.println("The area of the cylinder is: " + area);
        System.out.println("The volume of the cylinder is: " + volume);
        
        scanner.close();
    }

    
}
