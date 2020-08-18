public class Date {
    private int day;
    private int month;
    private int year;
    private boolean isLeap = false;
    private final int STARTOFGREGCAL = 1582;
    private final int LEAPDIV = 4;
    private final int LEAPDIV2 = 400;
    
    private enum Month {
            JANUARY(1), FEBRUARY(2), MARCH(3), APRIL(4), MAY(5), JUNE(6),
            JULY(7), AUGUST(8), SEPTEMBER(9), OCTOBER(10), NOVEMBER(11), DECEMBER(12);
            
            private int month;
            
            Month(int month) {
                this.month = month;
            }
            
            public int getMonth() {
                return this.month;
            }
        }
    
    private void validate(int day, int month, int year) throws InvalidDateException {
        if ( year >= STARTOFGREGCAL ) {
            if ( year % LEAPDIV == 0 || year % LEAPDIV2 == 0 ) {
                isLeap = true;        
            }
            if ( month < 1 || month > 12 ) {
                throw new InvalidDateException("Please, enter correct date! The month should be from 1 till 12.");
            }
            if ( month == Month.FEBRUARY.getMonth() && !isLeap ) {
                if ( day < 1 || day > 28 ) {
                    throw new InvalidDateException("Please, enter correct date! The day should be from 1 till 28.");
                }
            } else if ( month == Month.FEBRUARY.getMonth() && isLeap ) {
                if ( day < 1 || day > 29 ) {
                    throw new InvalidDateException("Please, enter correct date! The day should be from 1 till 29.");
                }
            } else if ( month == Month.APRIL.getMonth() || month == Month.JUNE.getMonth() ||
                month == Month.SEPTEMBER.getMonth() || month == Month.NOVEMBER.getMonth() ) {
                if ( day < 1 || day > 30 ) {
                    throw new InvalidDateException("Please, enter correct date! The day should be from 1 till 30.");
                }
            } else {
                if ( day < 1 || day > 31 ) {
                    throw new InvalidDateException("Please, enter correct date! The day should be from 1 till 31.");
                }
            }
        } else {
            throw new InvalidDateException("Please, enter correct date! The year should be bigger or equal to 1582.");
        }
    }

    public Date(int day, int month, int year) throws InvalidDateException {
        this.validate(day, month, year);
    
        this.day = day;
        this.month = month;
        this.year = year;
    }
    
    public Date() throws InvalidDateException {
        this(1, 1, 1970);
    }
    
    public final int getDay() {
        return this.day;
    }

    public final int getMonth() {
        return this.month;
    }

    public final int getYear() {
        return this.year;
    }
    
    @Override
    public String toString() {
        return "Entered date (" + this.day + ", " + this.month + ", " + this.year + ") is correct.";
    }    
}
