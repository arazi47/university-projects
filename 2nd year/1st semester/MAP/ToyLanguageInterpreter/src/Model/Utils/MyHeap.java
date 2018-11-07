package Model.Utils;

import java.util.HashMap;
import java.util.Map;

public class MyHeap<T> implements IHeap<T> {
    private int memory;
    private Map<Integer, T> vals;

    public MyHeap(Map<Integer, T> vals) {
        this.vals = vals;
    }

    @Override
    public int allocate(T val) {
        ++this.memory;
        this.vals.put(this.memory, val);

        return memory;
    }

    @Override
    public T getAddr(int addr) {
        return this.vals.get(addr);
    }

    @Override
    public void putAddr(int addr, T val) {
        this.vals.put(addr, val);
    }

    @Override
    public T deallocate(int addr) {
        return this.vals.remove(addr);
    }

    @Override
    public String toString() {
        String s = "";
        boolean firstTime = true;

        for (HashMap.Entry<Integer, T> entry : this.vals.entrySet()) {
            if (!firstTime) {
                s += "\n";
            }

            s += entry.getKey().toString() + " -> " + entry.getValue().toString();
            firstTime = false;
        }

        return s;
    }

    @Override
    public void setMap(Map<Integer, T> map) {
        this.vals = map;
    }

    @Override
    public Map<Integer, T> getMap() {
        return this.vals;
    }
}
