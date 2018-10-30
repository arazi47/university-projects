package Model.Expression;

import Model.Utils.MyDictionary;

public interface IExpression {

    int evaluate(MyDictionary<String, Integer> symTable);

    @Override
    String toString();
}
