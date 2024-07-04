import java.util.Scanner;
public class Add {
 public static void main(String args[]) {
  Scanner input = new Scanner(System.in);
  double number1, number2, total;

  System.out.print("Type number 1:");
  number1 = input.nextDouble();
  System.out.print("Type number 2:");
  number2 = input.nextDouble();
  total = number1 + number2;
  System.out.printf("The total of the two numbers is %3.2f\n", total);
 }
}
