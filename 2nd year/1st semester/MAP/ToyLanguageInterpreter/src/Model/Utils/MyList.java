package Model.Utils;

import java.util.ArrayList;

public class MyList<T> implements IList<T> {
    private ArrayList<T> list;

    public MyList(){
        this.list = new ArrayList<T>();
    }
    @Override
    public boolean add(T elem) {
        return this.list.add(elem);
    }

    @Override
    public boolean remove(T elem) {
        return this.list.remove(elem);
    }

    @Override
    public T get(int index) {
        return this.list.get(index);
    }

    public String toString(){
        StringBuilder res = new StringBuilder();
        for(T elem : this.list)
            res.append(elem.toString()).append(" ");

        res.append("\n");
        return res.toString();
    }
}