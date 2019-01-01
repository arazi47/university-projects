using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Expressions
{
    class ConstantExpression : IExpression
    {
        private int value;

        public ConstantExpression(int value)
        {
            this.value = value;
        }

        public override int evaluate(Dictionary<string, int> symTable)
        {
            return this.value;
        }

        public override string ToString()
        {
            return this.value.ToString();
        }
    }
}
