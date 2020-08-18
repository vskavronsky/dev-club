public class Vector {
    private double x;
    private double y;
    
    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Vector() {
        this(0.0, 0.0);
    }
    
    public final double getX() {
        return this.x;
    }
    
    public final double getY() {
        return this.y;
    }
    
    public void setX(double value) {
        this.x = value;
    }
    
    public void setY(double value) {
        this.y = value;
    }
    
    public double len() {
        return Math.hypot(this.x, this.y);    
    }
    
    public boolean equals(Vector other) {
        return this.x == other.x && this.y == other.y;
    }
    
    public void increment(Vector other) {
        this.x += other.x;
        this.y += other.y;
    }
    
    public void decrement(Vector other) {
        this.x -= other.x;
        this.y -= other.y;
    }
    
    public Vector add(Vector other) {
        return new Vector(this.x + other.x, this.y + other.y);
    }
    
    public Vector subtract(Vector other) {
        return new Vector(this.x - other.x, this.y - other.y);
    }
    
    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")"; 
    }
}
