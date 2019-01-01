using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.View
{
    public abstract class Command
    {
        private string key, description;

        public Command(string key, string description)
        {
            this.key = key;
            this.description = description;
        }

        public abstract void execute();

        public string getKey() { return this.key; }
        public string getDescription() { return this.description; }
    }
}
