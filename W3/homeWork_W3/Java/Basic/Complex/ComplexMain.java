public class ComplexMain {
    public static void main(String[] args) {
        Complex a = new Complex(2, 7);
        Complex b = new Complex(3, -8);
        
        // a.setX(2.0);
        // a.setY(7.0);
        
        System.out.println("a - " + a);
        System.out.println("a(x) - " + a.getReal());
        System.out.println("a(y) - " + a.getImaginary());
        System.out.println("b - " + b);
        System.out.println("b(x) - " + b.getReal());
        System.out.println("b(y) - " + b.getImaginary());
        
        a.increment(b);
        System.out.println("incremented a - " + a);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        a.decrement(b);
        System.out.println("Decremented a - " + a);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        Complex sum = a.add(b);
        System.out.println("Sum of a and b - " + sum);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        Complex diff = a.subtract(b);
        System.out.println("Diff of a and b - " + diff);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        Complex product = a.multiply(b);
        System.out.println("Product of a and b - " + product);
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        if ( a.equals(b) ) {
            System.out.println("a is equal to b");    
        } else {
            System.out.println("a is not equal to b");
        }       
    }
}
