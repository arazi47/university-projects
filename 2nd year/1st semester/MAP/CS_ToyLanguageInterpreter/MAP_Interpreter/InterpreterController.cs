using MAP_Interpreter.Model;
using MAP_Interpreter.Model.Statements;
using MAP_Interpreter.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter
{
    public class InterpreterController
    {
        private IRepository repo;

        public InterpreterController(IRepository repo)
        {
            this.repo = repo;
        }

        public ProgramState executeCmd(ProgramState ps)
        {
            Stack<IStatement> exeStack = ps.getExeStack();
            if (exeStack.Count == 0)
            {
                throw new Exception("Execution stack is empty!");
            }

            IStatement currentStatement = exeStack.Pop();
            return currentStatement.execute(ps);
        }

        public void executeAll()
        {
            ProgramState ps = this.repo.getProgramState();

            try
            {
                while (!(ps.getExeStack().Count == 0))
                {
                    this.executeCmd(ps);
                    this.repo.logPrgStateExec();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        public IRepository getRepository() { return this.repo; }
    }
}
