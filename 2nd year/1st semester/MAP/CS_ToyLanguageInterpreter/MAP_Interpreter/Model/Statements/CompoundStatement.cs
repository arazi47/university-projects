using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class CompoundStatement : IStatement
    {
        private IStatement st1, st2;

        public CompoundStatement(IStatement st1, IStatement st2)
        {
            this.st1 = st1;
            this.st2 = st2;
        }

        public override ProgramState execute(ProgramState ps)
        {
            Stack<IStatement> exeStack = ps.getExeStack();
            exeStack.Push(this.st2);
            exeStack.Push(this.st1);

            return null;
        }

        public override string ToString()
        {
            return "(" + this.st1.ToString() + "; " + this.st2.ToString() + ")";
        }
    }
}
