package Model.Expression;

import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public interface IExpression {

    int evaluate(MyDictionary<String, Integer> symTable, MyHeap<Integer> heap);

    @Override
    String toString();
}
