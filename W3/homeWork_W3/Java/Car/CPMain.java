public class CPMain {
    public static void main(String[] args) {
        Point x = new Point(-10, -80);
        Point y = new Point(20, 100);
        Car car = new Car(5000, 20, x, "Toyota");
        
        car.refill(0);
        System.out.println(car);
        
        car.drive(y);
        System.out.println(car);       
    }
}
