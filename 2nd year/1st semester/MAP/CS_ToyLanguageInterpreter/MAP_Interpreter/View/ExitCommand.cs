using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.View
{
    public class ExitCommand : Command
    {
        public ExitCommand(string key, string description) : base(key, description)
        {
            
        }

        public override void execute()
        {
            System.Environment.Exit(1);
        }
    }
}
