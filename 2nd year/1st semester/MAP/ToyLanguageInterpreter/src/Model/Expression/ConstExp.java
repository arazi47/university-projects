package Model.Expression;

import Model.Utils.ISymTable;
import Model.Utils.MyDictionary;

public class ConstExp implements IExpression {
    private int value;

    public ConstExp(int val){ this.value = val;}

    @Override
    public int evaluate(MyDictionary<String, Integer> symTable) {
        return this.value;
    }

    @Override
    public String toString() {
        return String.valueOf(this.value);
    }
}
