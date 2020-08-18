public class PointMain {
    public static void main(String[] args) {
        Point a = new Point();
        Point b = new Point(3, 8);
        
        System.out.println("a - " + a);
        System.out.println("b - " + b);
        
        a.setX(3.0);
        a.setY(8.0);
        
        if ( a.equals(b) ) {
            System.out.println("a is equal to b");    
        } else {
            System.out.println("a is not equal to b");
        }
        
        System.out.println("Distance from a to b - " + a.distance(b));
    }
}
