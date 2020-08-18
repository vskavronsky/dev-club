public class Pen {
    private int inkAmount;
    private int inkCapacity;

    public Pen(int inkCapacity) {
        this.inkAmount = inkCapacity;
        this.inkCapacity = inkCapacity;
    }

    public Pen() {
        this(4096);
    }

    public final int getInkAmount() {
        return this.inkAmount;
    }
    public final int getInkCapacity() {
        return this.inkCapacity;
    }
    
    public void write(Paper paper, String message) throws OutOfInkException, OutOfSpaceException {
        if ( this.inkAmount == 0 ) {
            throw new OutOfInkException();
        }
        if ( message.length() > this.inkAmount ) {
            paper.addContent(message.substring(0, this.inkAmount));
            this.inkAmount = 0;
            return;
        }
        paper.addContent(message);
        this.inkAmount -= message.length();
    }
    
    public void refill() {
        if ( this.inkCapacity <= 0 ) {
            System.out.println("You entered incorect pen capacity");
            return;  
        }
        this.inkAmount = this.inkCapacity;
    }
}
