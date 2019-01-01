using MAP_Interpreter.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Repositories
{
    public interface IRepository
    {
        ProgramState getProgramState();
        void logPrgStateExec();
    }
}
