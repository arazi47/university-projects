package Model.Utils;

public interface ISymTable {
    void add(String name, int val);
    boolean find(String name);
    int getValue(String name);
    //void setValue(String name, int val);

}
