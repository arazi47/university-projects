package Model.Statement;

import Model.ProgramState;

import java.io.FileNotFoundException;

public interface IStatement {
    ProgramState execute(ProgramState ps);

    @Override
    String toString();
}
