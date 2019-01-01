using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class ReadRFileStatement : IStatement
    {
        private IExpression fileIdExp;
        private string varName;

        public ReadRFileStatement(IExpression fileIdExp, string varName)
        {
            this.fileIdExp = fileIdExp;
            this.varName = varName;
        }

        public override ProgramState execute(ProgramState ps)
        {
            int fd = this.fileIdExp.evaluate(ps.getSymTable());
            Tuple<String, StreamReader> sr = ps.getFileTable()[fd];
            
            if (sr == null)
            {
                throw new Exception("File not found!");
            }

            string line = "";
            try
            {
                line = sr.Item2.ReadLine();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            ps.getSymTable()[this.varName] = Convert.ToInt32(line);

            return null;
        }

        public override string ToString()
        {
            return "readFileStmt(" + this.fileIdExp.ToString() + ", " + this.varName + ")";
        }
    }
}
