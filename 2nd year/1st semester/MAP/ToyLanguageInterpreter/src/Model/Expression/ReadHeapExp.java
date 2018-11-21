package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class ReadHeapExp implements IExpression {
    private String id;

    public ReadHeapExp(String id) {
        this.id = id;
    }

    @Override
    public int evaluate(IDictionary<String, Integer> symTable, MyHeap<Integer> heap) {
        Integer var_val = symTable.get(this.id);

        if (var_val == null) {
            //throw new Exception.CustomException("Unknown variable exception @TODO add a new one here");
        }

        Integer heap_val = heap.getAddr(var_val);
        if (heap_val == null) {
            //throw new Exception.CustomException("Heap error: no memory addres");
        }

        return heap_val;
    }

    @Override
    public String toString() {
        return "readHeapExp(" + id + ")";
    }
}
