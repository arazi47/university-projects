using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MAP_Interpreter.Model;

namespace MAP_Interpreter.Repositories
{
    class Repository : IRepository
    {
        ProgramState ps;

        // NYI
        // private string logPath = "logfile.txt";

        public Repository(ProgramState ps)
        {
            this.ps = ps;
        }

        public ProgramState getProgramState()
        {
            return this.ps;
        }

        public void logPrgStateExec()
        {
            return;

            // TODO
            throw new NotImplementedException();
        }
    }
}
