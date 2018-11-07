package Model.Utils;

import java.util.Map;

public interface IHeap<T> {
    int allocate(T val);
    T getAddr(int addr);
    void putAddr(int addr, T val);
    T deallocate(int addr);

    void setMap(Map<Integer, T> map);
    Map<Integer, T> getMap();
}
