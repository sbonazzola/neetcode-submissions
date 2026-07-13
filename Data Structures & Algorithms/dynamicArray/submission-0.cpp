class DynamicArray {

private:

int* arr;
int capacity;
int size;

public:

    DynamicArray(int capacity) {

        this -> capacity = capacity;
        this -> size = 0;
        this -> arr = new int [capacity];

    }

     ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        return arr[i];

    }

    void set(int i, int n) {
        arr[i] =n;

    }

    void pushback(int n) {
        if (size == capacity){
            resize();
        }

        arr[size] = n;

        size++;

    }

    int popback() {

        int val = arr[size-1];
        size--;
        return val;

    }

    void resize() {
    int newCapacity = capacity * 2;
    int* newArr = new int[newCapacity];

    for (int i = 0; i <size; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;

    arr = newArr;
    capacity = newCapacity;

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;

    }
};
