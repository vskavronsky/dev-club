public class Car {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point location;
    private String model;
    
    public Car(double capacity, double consumption, Point location, String model) {
        this.fuelAmount = 0.0;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
    }
    
    public Car() {
        this(60.0, 0.6, new Point(0.0, 0.0), "Mercedes");
    }
    
    public final double getFuelAmount() {
        return this.fuelAmount;
    }
    
    public final double getFuelCapacity() {
        return this.fuelCapacity;
    }
    
    public final double getFuelConsumption() {
        return this.fuelConsumption;
    }
    
    public final Point getLocation() {
        return this.location;
    }
    
    public final String getModel() {
        return this.model;
    }
    
    public void drive(Point destination) {
        double neededFuel;
    
        if ( this.fuelConsumption <= 0 ) {
            System.out.println("You entered incorrect fuel consumption!");
            return;
        }
        neededFuel = this.location.distance(destination) * this.fuelConsumption;
    
        try {
            if ( this.fuelAmount == 0 ) {
                throw new OutOfFuelException();
            }
            if ( this.fuelAmount < neededFuel ) {
                System.out.println("Can't move! Needed fuel for travel is " + neededFuel + " liters.");
                return;
            }
        
            this.fuelAmount -= neededFuel;
            this.fuelCapacity -= this.fuelAmount;
            this.location = destination;
        }
        catch (OutOfFuelException exception) {
            System.out.println("Your fuel tank is empty! Needed fuel for travel is " + neededFuel + " liters.");
        }
    }

    public void drive(double x, double y) {
        this.drive(new Point(x, y));
    }

    public void refill(double fuel) {
        try {
            if ( this.fuelCapacity <= 0 ) {
                System.out.println("You entered incorrect tank capacity!");
                return;
            }
            if ( this.fuelAmount + fuel > this.fuelCapacity ) {
                this.fuelAmount = this.fuelCapacity;
                throw new ToMuchFuelException();
            } else if ( fuel < 0 ) {
                this.fuelAmount = 0;
                return;
            }   
            this.fuelAmount += fuel;
        }
        catch (ToMuchFuelException exception) {
            System.out.println("To much fuel! Your fuel tank is full.");
        }
    }
    
    @Override
    public String toString() {
        return "Characteristics of the car:\n"
            + "The model of car - " + this.model + ".\n"
            + "The car location - " + this.location + ".\n"
            + "Fuel amount - " + this.fuelAmount + " liters.\n"
            + "Tank capacity - " + this.fuelCapacity + " liters.\n"
            + "Fuel consumption - " + this.fuelConsumption + " liters.";
    }
}
