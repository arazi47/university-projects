using MAP_Interpreter.Model.Statements;
using MAP_Interpreter.Model.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MAP_Interpreter.Repositories;
using MAP_Interpreter.Model;
using System.IO;
using MAP_Interpreter.View;

namespace MAP_Interpreter
{
    class Program
    {
        static void Main(string[] args)
        {
            // v = 2; print(v)
            IStatement ex1 = new CompoundStatement(new AssignmentStatement("v", new ConstantExpression(2)), new PrintStatement(new VariableExpression("v")));

            // open csharptestlogfile.txt, write the numbers on the first 2 lines and -1
            IStatement ex2 = new CompoundStatement(new OpenRFileStatement("var_f", "csharptestlogfile.txt"),
        new CompoundStatement(new ReadRFileStatement(new VariableExpression("var_f"), "var_c"),
                new CompoundStatement(new PrintStatement(new VariableExpression("var_c")),
                        new CompoundStatement(new IfStatement(new VariableExpression("var_c"),
                                new CompoundStatement(new ReadRFileStatement(new VariableExpression("var_f"), "var_c"), new PrintStatement(new VariableExpression("var_c"))),
                                new PrintStatement(new ConstantExpression(0))), new PrintStatement(new ConstantExpression(-1))))));

            ProgramState ps1 = new ProgramState(ex1);
            IRepository repo1 = new Repository(ps1);
            InterpreterController ctrl1 = new InterpreterController(repo1);

            ProgramState ps2 = new ProgramState(ex2);
            IRepository repo2 = new Repository(ps2);
            InterpreterController ctrl2 = new InterpreterController(repo2);

            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "Exit"));
            menu.addCommand(new RunExample("1", ex1.ToString(), ctrl1));
            menu.addCommand(new RunExample("2", ex2.ToString(), ctrl2));

            menu.show();
        }
    }
}
