package by.bsu.hometask;

public class Product {
    String title;
    int size;

    public Product(String title, int size) {
        this.title = title;
        this.size = size;
    }

    public String toString() {
        return title + ":" + size;
    }
}
