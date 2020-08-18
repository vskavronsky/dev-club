public class Gun {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;
    private final int BULLET = 1;
    private final int SHOOT = 1;
    
    public Gun(String model, int capacity) {
        this.amount = 0;
        this.capacity = capacity;
        this.isReady = false;
        this.model = model;
        this.totalShots = 0;
    }
        
    public Gun() {
        this("Beretta", 8);
    }
    
    public final int getAmount() {
        return this.amount;    
    }

    public final int getCapacity() {
        return this.capacity;
    }

    public final boolean ready() {
        return this.isReady;
    }

    public final String getModel() {
        return this.model;
    }

    public final int getTotalShots() {
        return this.totalShots;
    }

    public void prepare() {
        this.isReady = !this.isReady;
    }

    public void reload() {
        if ( this.capacity <= 0 ) {
            System.out.println("You entered incorrect magazine capacity!");
            return;
        }
        this.amount = this.capacity;
    }
    
    public void shoot() throws NotReadyException, OutOfRoundsException {
        if ( !this.ready() ) {
            throw new NotReadyException();
        }
        if ( this.amount == 0 ) {
            throw new OutOfRoundsException();
        }
        System.out.println("Bang!");
        this.amount -= BULLET;
        this.totalShots += SHOOT;
    }
    
    @Override
    public String toString() {
        return "Characteristics of the gun:\n" 
            + "The gun model - " + this.model + ".\n"
            + "Ready to shoot - " + this.isReady + ".\n"
            + "Bullets quantity - " + this.amount + ".\n"
            + "Magazine capacity - " + this.capacity + ".\n"
            + "Total shots - " + this.totalShots + ".";
    }
}
