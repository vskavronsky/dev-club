public class Point {
    private double x;
    private double y;
    
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Point() {
        this(0.0, 0.0);
    }
    
    public final double getX() {
        return this.x;
    }
    
    public final double getY() {
        return this.y;
    }
    
    public double distance(Point other) {
        return Math.hypot(other.x - this.x, other.y - this.y);
    }
    
    public boolean equals(Point other) {
        return this.x == other.x && this.y == other.y;
    }
    
    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
}
