public class PPMain {
    public static void main(String[] args) {
        try {
            Pen pen = new Pen(400);
            Paper paper = new Paper(300);
            String str1 = "Hello World! I love C++ so much."; // 32
            String str2 = "\nBut he loves Java."; // 19
            
            pen.refill();
            pen.write(paper, str1);
            paper.show();
            
            System.out.println("inkAmount - " + pen.getInkAmount());
            System.out.println("inkCapacity - " + pen.getInkCapacity());
            System.out.println("symbols - " + paper.getSymbols());
            System.out.println("maxSymbols - " + paper.getMaxSymbols());
            
            pen.write(paper, str2);
            paper.show();
            
            System.out.println("inkAmount - " + pen.getInkAmount());
            System.out.println("inkCapacity - " + pen.getInkCapacity());
            System.out.println("symbols - " + paper.getSymbols());
            System.out.println("maxSymbols - " + paper.getMaxSymbols());
            
            pen.write(paper, str1);
            paper.show();
            
            System.out.println("inkAmount - " + pen.getInkAmount());
            System.out.println("inkCapacity - " + pen.getInkCapacity());
            System.out.println("symbols - " + paper.getSymbols());
            System.out.println("maxSymbols - " + paper.getMaxSymbols());
            
            // pen.write(paper, str);
            // paper.show();
            
            // cout << "inkAmount - " << pen.getInkAmount() << endl;
            // cout << "inkCapacity - " << pen.getInkCapacity() << endl;
            // cout << "symbols - " << paper.getSymbols() << endl;
            // cout << "maxSymbols - " << paper.getMaxSymbols() << endl;
        }
        catch (OutOfInkException exception) {
            System.out.println("Please, refill your pen!");
        }
        catch (OutOfSpaceException exception) {
            System.out.println("Not enough space! You used all free space on the paper!");
        }
    }
}
