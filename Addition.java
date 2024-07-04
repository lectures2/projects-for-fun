import javax.swing.JOptionPane;  
public class Addition {
   public static void main( String args[]){
     String first,second;  
     int number1,number2,sum;              
	     final double PI = 3.14;
     
     first=JOptionPane.showInputDialog("Enter 1st int" );
     second=JOptionPane.showInputDialog("Enter 2nd int");

     number1 = Integer.parseInt(first);
     number2 = Integer.parseInt(second);
      
     sum = number1 + number2;
      
     JOptionPane.showMessageDialog(null,"The sum is" + sum, "Results", JOptionPane.PLAIN_MESSAGE );
     System.exit(0);   
   }  
}  
