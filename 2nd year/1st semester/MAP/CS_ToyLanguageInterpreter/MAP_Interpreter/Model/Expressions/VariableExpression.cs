using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Expressions
{
    class VariableExpression : IExpression
    {
        private string name;

        public VariableExpression(string name)
        {
            this.name = name;
        }

        public override int evaluate(Dictionary<string, int> symTable)
        {
            if (symTable.ContainsKey(this.name))
            {
                return symTable[this.name];
            }
            else
            {
                throw new Exception("Non existent variable!");
            }
        }

        public override string ToString()
        {
            return this.name;
        }
    }
}
