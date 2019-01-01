using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.View
{
    public class RunExample : Command
    {
        private InterpreterController ctrl;

        public RunExample(string key, string description, InterpreterController ctrl) : base(key, description)
        {
            this.ctrl = ctrl;
        }

        public override void execute()
        {
            try
            {
                Console.WriteLine(ctrl.getRepository().getProgramState().ToString());
                ctrl.executeAll();
                Console.WriteLine(ctrl.getRepository().getProgramState().ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}
