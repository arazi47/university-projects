using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class IfStatement : IStatement
    {
        private IStatement st1, st2;
        private IExpression exp;

        public IfStatement(IExpression exp, IStatement st1, IStatement st2)
        {
            this.exp = exp;
            this.st1 = st1;
            this.st2 = st2;
        }

        public override ProgramState execute(ProgramState ps)
        {
            int result = this.exp.evaluate(ps.getSymTable());
            if (result != 0)
            {
                this.st1.execute(ps);
            }
            else
            {
                this.st2.execute(ps);
            }

            return null;
        }

        public override string ToString()
        {
            return "if " + this.exp.ToString() + " then " + this.st1.ToString() + " else " + this.st2.ToString();
        }
    }
}