package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.ISymTable;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public class ConstExp implements IExpression {
    private int value;

    public ConstExp(int val){ this.value = val;}

    @Override
    public int evaluate(IDictionary<String, Integer> symTable, MyHeap<Integer> heap) {
        return this.value;
    }

    @Override
    public String toString() {
        return String.valueOf(this.value);
    }
}
