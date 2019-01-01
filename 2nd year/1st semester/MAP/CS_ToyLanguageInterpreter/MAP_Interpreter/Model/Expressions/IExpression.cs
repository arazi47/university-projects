using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Expressions
{
    public abstract class IExpression
    {
        public abstract int evaluate(Dictionary<string, int> symTable);

        public abstract override string ToString();
    }
}
