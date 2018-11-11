package Model.Expression;

import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;
import Exception.CustomException;

public class BooleanExp implements IExpression {
    private IExpression exp1, exp2;
    private String type;

    public BooleanExp(IExpression exp1, IExpression exp2, String type) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.type = type;
    }

    @Override
    public int evaluate(MyDictionary<String, Integer> symTable, MyHeap<Integer> heap) {
        int res1 = this.exp1.evaluate(symTable, heap);
        int res2 = this.exp2.evaluate(symTable, heap);

        switch (this.type) {
            case "<":
                return res1 < res2 ? 1 : 0;

            case "<=":
                return res1 <= res2 ? 1 : 0;

            case ">":
                return res1 > res2 ? 1 : 0;

            case ">=":
                return res1 >= res2 ? 1 : 0;

            case "==":
                return res1 == res2 ? 1 : 0;

            case "!=":
                return res1 != res2 ? 1 : 0;

            default:
                throw new CustomException("BooleanExp.java evaluation error!");
        }
    }

    @Override
    public String toString() {
        return this.exp1 + " " + this.type + " " + this.exp2;
    }
}
