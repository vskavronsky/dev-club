public class Complex {
    private double real;
    private double imaginary;
    
    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }
    
    public Complex() {
        this(0.0, 0.0);
    }
    
    public final double getReal() {
        return this.real;
    }
    
    public final double getImaginary() {
        return this.imaginary;
    }
    
    public boolean equals(Complex other) {
        return this.real == other.real && this.imaginary == other.imaginary;
    }
    
    public void increment(Complex other) {
        this.real += other.real;
        this.imaginary += other.imaginary;
    }
    
    public void decrement(Complex other) {
        this.real -= other.real;
        this.imaginary -= other.imaginary;
    }
    
    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }
    
    public Complex subtract(Complex other) {
        return new Complex(this.real - other.real, this.imaginary - other.imaginary);
    }
    
    public Complex multiply(Complex other) {
        double tempReal = this.real;
        
        return new Complex(this.real * other.real - this.imaginary * other.imaginary, tempReal * other.imaginary +       this.imaginary * other.real);
    }
    
    @Override
    public String toString() {
        if ( this.imaginary < 0 ) {
            return this.real + "" + this.imaginary  + "i";
        } else {
            return this.real + "+" + this.imaginary + "i";
        }
    }
}
