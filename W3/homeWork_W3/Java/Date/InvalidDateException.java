public class InvalidDateException extends Exception {
    private String text;
    
    public InvalidDateException(String text) {
        this.text = text;
    }
    
    public final String getText() {
        return this.text;
    }
}
