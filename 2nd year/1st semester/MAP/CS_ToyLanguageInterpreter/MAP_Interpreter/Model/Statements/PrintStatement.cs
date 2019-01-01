using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class PrintStatement : IStatement
    {
        IExpression exp;

        public PrintStatement(IExpression exp)
        {
            this.exp = exp;
        }

        public override ProgramState execute(ProgramState ps)
        {
            List<int> output = ps.getOutput();
            output.Add(this.exp.evaluate(ps.getSymTable()));

            return null;
        }

        public override string ToString()
        {
            return "print(" + this.exp.ToString() + ")";
        }
    }
}
