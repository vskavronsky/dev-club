import java.util.Random;

public class IntArrayListMain {
    public static void main(String[] args) {
        try {
            int element;
            int size = 10;
            Random dice = new Random();
            IntArrayList arr1 = new IntArrayList();
            IntArrayList arr2 = new IntArrayList();
            
            for ( int i = 0; i < size; i++ ) {
               arr1.add(element = dice.nextInt(10));
            }
            
            for ( int i = 0; i < size; i++ ) {
               arr2.add(element = dice.nextInt(10));
            }
            
            System.out.print("[ ");
            for ( int i = 0; i < arr1.size(); i++ ) {
                System.out.print(arr1.get(i) + " ");
            }
            System.out.println("]");
            
            System.out.print("[ ");
            for ( int i = 0; i < arr2.size(); i++ ) {
                System.out.print(arr2.get(i) + " ");
            }
            System.out.println("]");
            
            System.out.println(arr1.equals(arr2));
        }
        catch( IndexOutOfBoundsException ex ) {
            System.out.println("Incorrect index number!");
        }
        catch( IllegalStateException ex ) {
            System.out.println("Incorrect capacity or multiplier number!");
        }
        // catch(CloneNotSupportedException ex) {
        //     System.out.println("Can't clone the array");   
        // }
    }
}
