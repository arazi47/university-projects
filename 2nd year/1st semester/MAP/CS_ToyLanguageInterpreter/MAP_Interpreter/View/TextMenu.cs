using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MAP_Interpreter.View
{
    public class TextMenu
    {
        private Dictionary<string, Command> commands;

        public TextMenu()
        {
            this.commands = new Dictionary<string, Command>();
        }

        public void addCommand(Command cmd)
        {
            this.commands.Add(cmd.getKey(), cmd);
        }

        private void printMenu()
        {
            foreach (var cmd in this.commands.Values)
            {
                Console.WriteLine(cmd.getKey() + ": " + cmd.getDescription());
            }
        }

        public void show()
        {
            while (true)
            {
                this.printMenu();
                Console.WriteLine("Input the option: ");
                string userInput = Console.ReadLine();
                Command cmd = this.commands[userInput];

                if (cmd == null)
                {
                    Console.WriteLine("Invalid option entered!");
                    continue;
                }

                cmd.execute();
            }
        }
    }
}
