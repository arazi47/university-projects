using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class CloseRFileStatement : IStatement
    {
        IExpression fileIdExp;

        public CloseRFileStatement(IExpression fileIdExp)
        {
            this.fileIdExp = fileIdExp;
        }

        public override ProgramState execute(ProgramState ps)
        {
            int fd = this.fileIdExp.evaluate(ps.getSymTable());
            Tuple<string, StreamReader> sr = ps.getFileTable()[fd];

            if (sr == null)
            {
                throw new Exception("File not opened!");
            }

            try
            {
                sr.Item2.Close();
                ps.getFileTable().Remove(fd);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            return null;
        }

        public override string ToString()
        {
            return "closeRFileStmt(" + this.fileIdExp.ToString() + ")";
        }
    }
}
