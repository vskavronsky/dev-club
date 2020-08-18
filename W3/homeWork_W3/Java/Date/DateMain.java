public class DateMain {
    public static void main(String[] args) {
        try {
            Date date1 = new Date(23, 1, 2000);
            System.out.println("Leap 01 - " + date1);
            Date date2 = new Date(31, 01, 2003);
            System.out.println("noLeap 01 -" + date2);
            
            System.out.println("-----------------------");
            
            Date date3 = new Date(29, 02, 2000);
            System.out.println("Leap 02 - " + date3);
            Date date4 = new Date(28, 02, 2003);
            System.out.println("noLeap 02 -" + date4);
            
            System.out.println("-----------------------");
            
            Date date5 = new Date(31, 03, 2000);
            System.out.println("Leap 03 - " + date5);
            Date date6 = new Date(31, 03, 2003);
            System.out.println("noLeap 03 -" + date6);
            
            System.out.println("-----------------------");
            
            Date date7 = new Date(16, 04, 2000);
            System.out.println("Leap 04 - " + date7);
            Date date8 = new Date(30, 04, 2003);
            System.out.println("noLeap 04 -" + date8);
            
            System.out.println("-----------------------");
            
            Date date9 = new Date(31, 05, 2000);
            System.out.println("Leap 05 - " + date9);
            Date date10 = new Date(31, 05, 2003);
            System.out.println("noLeap 05 -" + date10);
            
            System.out.println("-----------------------");
            
            Date date11 = new Date(30, 06, 2000);
            System.out.println("Leap 06 - " + date11);
            Date date12 = new Date(30, 06, 2003);
            System.out.println("noLeap 06 -" + date12);
            
            System.out.println("-----------------------");
            
            Date date13 = new Date(31, 07, 2000);
            System.out.println("Leap 07 - " + date13);
            Date date14 = new Date(31, 07, 2003);
            System.out.println("noLeap 07 -" + date14);
            
            System.out.println("-----------------------");
            
            Date date15 = new Date(31, 8, 2000);
            System.out.println("Leap 08 - " + date15);
            Date date16 = new Date(31, 8, 2003);
            System.out.println("noLeap 08 -" + date16);
        
            System.out.println("-----------------------");
            
            Date date17 = new Date(30, 9, 2000);
            System.out.println("Leap 09 - " + date17);
            Date date18 = new Date(30, 9, 2003);
            System.out.println("noLeap 09 -" + date18);
        
            System.out.println("-----------------------");
            
            Date date19 = new Date(31, 10, 2000);
            System.out.println("Leap 10 - " + date19);
            Date date20 = new Date(31, 10, 2003);
            System.out.println("noLeap 10 -" + date20);
            
            System.out.println("-----------------------");
            
            Date date21 = new Date(30, 11, 2000);
            System.out.println("Leap 11 - " + date21);
            Date date22 = new Date(30, 11, 2003);
            System.out.println("noLeap 11 -" + date22);
        
            System.out.println("-----------------------");
            
            Date date23 = new Date(31, 12, 2000);
            System.out.println("Leap 12 - " + date23);
            Date date24 = new Date(31, 12, 2003);
            System.out.println("noLeap 12 -" + date24);
        }
        catch (InvalidDateException exception) {
            System.out.println(exception.getText());
        }        
    }
}
