public class Paper {
    private StringBuffer content;
    private int maxSymbols;
    private int symbols;
    
    public Paper(int maxSymbols) {
        this.content = new StringBuffer();
        this.maxSymbols = maxSymbols;
        this.symbols = 0;
    }

    public Paper() {
        this(4096);
    }

    public final int getMaxSymbols() {
        return this.maxSymbols;
    }
    
    public final int getSymbols() {
        return this.symbols;
    }
    
    public void addContent(String message) throws OutOfSpaceException {
        this.symbols = content.length() + message.length();
        
        if ( this.maxSymbols <= 0 ) {
            throw new OutOfSpaceException();
            }
        if ( content.length() == this.maxSymbols ) {
            throw new OutOfSpaceException();
        }
        if ( this.symbols > this.maxSymbols ) {
            content.append(message.substring(0, this.maxSymbols - content.length()));
            return;
        }
        content.append(message);
    }
    
    public void show() {
        System.out.println(content);
    }
}
