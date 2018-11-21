package Model.Expression;

import Model.Utils.IDictionary;
import Model.Utils.MyDictionary;
import Model.Utils.MyHeap;

public interface IExpression {

    int evaluate(IDictionary<String, Integer> symTable, MyHeap<Integer> heap);

    @Override
    String toString();
}
