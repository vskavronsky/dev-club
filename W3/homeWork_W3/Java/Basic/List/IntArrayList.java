public class IntArrayList implements Cloneable {
    private int[] array;
    private int size;
    private int capacity;
    private int multiplier;
    
    private int isIndexExist(int index) throws IndexOutOfBoundsException {
        if ( index >= this.size || index < 0 ) {
            throw new IndexOutOfBoundsException();
        }
        return index;
    }
    
    private int[] increaseCapacity() {
        int newCapacity = this.capacity * this.multiplier;
        int[] temp = new int[newCapacity];
        System.arraycopy(this.array, 0, temp, 0, this.capacity);
        this.capacity = newCapacity;
        
        return temp;
    }
    
    public IntArrayList(int capacity, int multiplier) throws IllegalStateException {
        if ( this.capacity >= 0 && multiplier >= 0 ) {
            this.array = new int[capacity];
            this.size = 0;
            this.capacity = capacity;
            this.multiplier = multiplier;
        } else {
            throw new IllegalStateException();
        }
    }
    
    public IntArrayList() throws IllegalStateException {
        this(10, 2);
    }
    
    public final int size() {
        return this.size;
    }
    
    public final int max_size() {
        return this.capacity;
    }
    
    public int get(int index) throws IndexOutOfBoundsException {
        return this.array[isIndexExist(index)];
    }
    
    public void add(int index, int value) throws IndexOutOfBoundsException {
        isIndexExist(index);
        if ( this.size == this.capacity ) {
            this.array = increaseCapacity();
        }
        System.arraycopy(this.array, index, this.array, index + 1, this.size - index);
        this.array[index] = value;
        this.size += 1;
    }
    
    public boolean add(int value) {
        if ( this.size == this.capacity ) {
            this.array = increaseCapacity();
        }
        this.array[this.size] = value;
        this.size += 1;
        
        return true;
    }
    
    public int set(int index, int value) throws IndexOutOfBoundsException {
        int temp = this.array[isIndexExist(index)];
        this.array[index] = value;
        
        return temp;
    }
    
    public int remove(int index) throws IndexOutOfBoundsException {
        int temp = this.array[isIndexExist(index)];
        System.arraycopy(this.array, index + 1, this.array, index, this.size - 1 - index);
        this.size -= 1;
        
        return temp;
    }
    
    public boolean contains(int value) {
        for ( int i = 0; i < this.size; i++ ) {
            if ( array[i] == value ) {
                return true;
            }
        }
        return false;
    }
    
    public void clear() {
        for ( int i = 0; i < this.size; i++ ) {
            array[i] = 0;
        }
    }
    
    public int indexOf(int value) {
        for ( int i = 0; i < this.size; i++ ) {
            if ( array[i] == value ) {
                return i;
            }
        }
        return -1;
    }
    
    public void sort() {
        for ( int i = 0; i < this.size; i++ ) {
            int min = i;
        
            for ( int j = i + 1; j < this.size; j++ ) {
                if ( this.array[min] > this.array[j] ) {
                    min = j;
                }
            }
            if ( min != i ) {
                int temp = this.array[min];
            
                this.array[min] = this.array[i];
                this.array[i] = temp;
            }
        }
    }
    
    public boolean equals(IntArrayList other) {
        if ( this.size == other.size ) {
            for ( int i = 0, j = this.size - 1; this.array[i] == other.array[i]; i++, j-- ) {
                if ( j == 0 ) {
                    return true;
                }
            }
        }
        return false;
    }
    
    public IntArrayList clone() throws CloneNotSupportedException {
        return (IntArrayList) super.clone();
    }  
}
