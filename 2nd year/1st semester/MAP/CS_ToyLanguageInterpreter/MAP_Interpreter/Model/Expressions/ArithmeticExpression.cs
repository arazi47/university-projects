using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Expressions
{
    class ArithmeticExpression : IExpression
    {
        private IExpression e1, e2;
        private char op; // Operator

        public ArithmeticExpression(IExpression e1, char op, IExpression e2)
        {
            this.e1 = e1;
            this.op = op;
            this.e2 = e2;
        }
            
        public override int evaluate(Dictionary<string, int> symTable)
        {
            int firstRes = this.e1.evaluate(symTable);
            int secondRes = this.e2.evaluate(symTable);

            switch (this.op)
            {
                case '+':
                    return firstRes + secondRes;

                case '-':
                    return firstRes - secondRes;

                case '*':
                    return firstRes * secondRes;

                case '/':
                    if (secondRes == 0)
                    {
                        throw new Exception("Second operand cannot be 0!");
                    }

                    return firstRes / secondRes;

                default:
                    throw new Exception("Invalid operation entered!");
            }
        }

        public override string ToString()
        {
            return this.e1.ToString() + " " + this.op.ToString() + " " + this.e2.ToString();
        }
    }
}
