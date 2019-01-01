using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    public abstract class IStatement
    {
        public abstract ProgramState execute(ProgramState ps);

        public abstract override string ToString();
    }
}
