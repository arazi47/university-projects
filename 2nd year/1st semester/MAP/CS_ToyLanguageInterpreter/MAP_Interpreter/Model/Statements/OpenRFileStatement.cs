using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model.Statements
{
    class OpenRFileStatement : IStatement
    {
        private static int fd = 2;
        private string fileId, fileName;

        public OpenRFileStatement(string fileId, string fileName)
        {
            this.fileId = fileId;
            this.fileName = fileName;
        }

        public override ProgramState execute(ProgramState ps)
        {
            foreach(var e in ps.getFileTable().Values)
            {
                if (e.Item1 == this.fileName)
                {
                    throw new Exception("File already opened!");
                }
            }

            int newFileFd = ++OpenRFileStatement.fd;

            try
            {
                ps.getFileTable().Add(newFileFd, new Tuple<string, StreamReader>(this.fileName, new StreamReader(new FileStream("C:\\Users\\necso\\Desktop\\" + this.fileName, FileMode.Open, FileAccess.Read))));
                ps.getSymTable().Add(this.fileId, newFileFd);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            return null;
        }

        public override string ToString()
        {
            return "openRFile(" + this.fileId + ", " + this.fileName + ")";
        }
    }
}
