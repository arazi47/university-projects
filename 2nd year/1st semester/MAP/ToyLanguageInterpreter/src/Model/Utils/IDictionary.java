package Model.Utils;

public interface IDictionary<K, V> {
    void put(K key, V value);
    void remove(K key);
    boolean contains(K key);
    V get(K key);
    String toString();

}
