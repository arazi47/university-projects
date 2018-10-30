package View;

import Controller.InterpreterController;
import Model.Expression.ArithExp;
import Model.Expression.ConstExp;
import Model.Expression.IExpression;
import Model.Expression.VarExp;
import Model.ProgramState;
import Model.Statement.*;
import Model.Utils.MyDictionary;
import Model.Utils.MyList;
import Model.Utils.MyStack;
import Model.Utils.Tuple;
import Repository.IRepo;
import Repository.Repo;

import java.io.BufferedReader;
import java.util.Scanner;

public class View {
    public static void main(String[] args) {
        MyStack<IStatement> exeStack = new MyStack<>();
        MyDictionary<String, Integer> symTable = new MyDictionary<>();
        MyList<Integer> output = new MyList<>();
        MyDictionary<Integer, Tuple<String, BufferedReader>> fileTable = new MyDictionary<>();

        Scanner scanner = new Scanner(System.in);

        // v = 2; print(v)
        IStatement ex1 = new CompoundStm(new AssignmentStm("v",new ConstExp(2)), new PrintStm(new
                VarExp("v")));

        // a = 2 + 3 * 5; b = a + 1; print(b)
        //IStatement ex1 =  new CompoundStm(new AssignmentStm("a", new ArithExp(new ConstExp(2),'+',new
        //        ArithExp(new ConstExp(3),'*' ,new ConstExp(5)))),
        //        new CompoundStm(new AssignmentStm("b",new ArithExp(new VarExp("a"),'+', new
        //                ConstExp(1))), new PrintStm(new VarExp("b"))));

        // a = 2 - 2; (if a then v = 2 else v = 3); print(v)
        //IStatement ex1 = new CompoundStm(new AssignmentStm("a", new ArithExp( new ConstExp(2),'-', new
        //        ConstExp(1))), new CompoundStm(new IfStm(new VarExp("a"), new AssignmentStm("v", new ConstExp(2)), new
        //        AssignmentStm("v", new ConstExp(3))), new PrintStm(new VarExp("v"))));

        IRepo repo = new Repo();
        ProgramState mainPs = new ProgramState(exeStack, output, symTable, ex1, fileTable);
        repo.add(mainPs);
        InterpreterController ctrl = new InterpreterController(repo);

        System.out.println(repo.getCurrentPs());
        while (!mainPs.getExeStack().isEmpty()) {
            System.out.println("1. Execute one command\n2. Execute all commands");
            int option = Integer.valueOf(scanner.nextLine());
            if (option == 1) {
                ctrl.executeCmd(mainPs);
            } else if (option == 2) {
                ctrl.executeAll();
            } else {
                System.out.println("Unknown option entered!");
            }

            System.out.println(repo.getCurrentPs());
        }
    }
}

/*
    FileTable - un dictionar care dateaza niste intregi ca valori,
    o tabela noua in programstate care are o referinta spre mytable
    interfata + clasa

    buffer reader - string cu care citim urmatorul caracter
    daca am ajuns la finalul fisierului, returnam valoarea citita
 */