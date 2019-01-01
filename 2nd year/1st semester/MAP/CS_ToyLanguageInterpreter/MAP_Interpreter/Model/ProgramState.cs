using MAP_Interpreter.Model.Statements;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.Model
{
    public class ProgramState
    {
        private Stack<IStatement> exeStack;
        private Dictionary<string, int> symTable;
        private List<int> output;
        private IStatement program;
        Dictionary<int, Tuple<string, StreamReader>> fileTable;

        public ProgramState(IStatement program)
        {
            this.exeStack = new Stack<IStatement>();
            this.symTable = new Dictionary<string, int>();
            this.output = new List<int>();
            this.program = program;
            this.fileTable = new Dictionary<int, Tuple<string, StreamReader>>();

            this.exeStack.Push(program);
        }

        public ProgramState(
            Stack<IStatement> exeStack,
            Dictionary<string, int> symTable,
            List<int> output,
            Dictionary<int, Tuple<string, StreamReader>> fileTable,
            IStatement program
            )
        {
            this.exeStack = exeStack;
            this.symTable = symTable;
            this.output = output;
            this.fileTable = fileTable;
            this.program = program;

            this.exeStack.Push(program);
        }

        public Stack<IStatement> getExeStack() { return this.exeStack; }
        public void setExeStack(Stack<IStatement> exeStack) { this.exeStack = exeStack; }
        
        public Dictionary<string, int> getSymTable() { return this.symTable; }
        public void setSymTable(Dictionary<string, int> symTable) { this.symTable = symTable; }

        public List<int> getOutput() { return this.output; }
        public void setOutput(List<int> output) { this.output = output; }

        public IStatement getProgram() { return this.program; }
        public void setProgram(IStatement program) { this.program = program; }

        public Dictionary<int, Tuple<string, StreamReader>> getFileTable() { return this.fileTable; }
        public void setFileTable(Dictionary<int, Tuple<string, StreamReader>> fileTable) { this.fileTable = fileTable; }

        public override string ToString()
        {
            string s = "=========================\n";

            s += "exeStack:";
            foreach (var e in this.exeStack)
            {
                s += e.ToString();
            }

            s += "\nsymTable:\n";
            foreach (var e in this.symTable)
            {
                s += e.ToString();
            }

            s += "\nfileTable:\n";
            foreach (var e in this.fileTable)
            {
                s += e.ToString();
            }

            s += "\noutput:\n";
            foreach(var e in this.output)
            {
                s += e.ToString() + " ";
            }

            s += "\n=========================";

            return s;
        }
    }
}
