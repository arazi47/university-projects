using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class AssignmentStatement : IStatement
    {
        private string varName;
        private IExpression exp;

        public AssignmentStatement(string varName, IExpression exp)
        {
            this.varName = varName;
            this.exp = exp;
        }

        public override ProgramState execute(ProgramState ps)
        {
            Dictionary<string, int> symTable = ps.getSymTable();
            symTable.Add(this.varName, this.exp.evaluate(symTable));

            return null;
        }

        public override string ToString()
        {
            return this.varName + " = " + this.exp.ToString();
        }
    }
}
