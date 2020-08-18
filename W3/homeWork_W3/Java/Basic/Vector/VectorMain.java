public class VectorMain {
    public static void main(String[] args) {
        Vector a = new Vector();
        Vector b = new Vector(15, 20);
        
        a.setX(5.0);
        a.setY(10.0);
        
        System.out.println("a - " + a);
        System.out.println("a(x) - " + a.getX());
        System.out.println("a(y) - " + a.getY());
        System.out.println("b - " + b);
        System.out.println("b(x) - " + b.getX());
        System.out.println("b(y) - " + b.getY());
        
        System.out.println("Length of the b - " + b.len()); 
        
        a.increment(b);
        System.out.println("incremented a - " + a);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        a.decrement(b);
        System.out.println("Decremented a - " + a);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        Vector sum = a.add(b);
        System.out.println("Sum of a and b - " + sum);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        Vector diff = a.subtract(b);
        System.out.println("Diff of a and b - " + diff);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        if ( a.equals(b) ) {
            System.out.println("a is equal to b");    
        } else {
            System.out.println("a is not equal to b");
        }       
    }
}
