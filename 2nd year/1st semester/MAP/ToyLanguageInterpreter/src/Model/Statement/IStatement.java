package Model.Statement;

import Model.ProgramState;

public interface IStatement {
    ProgramState execute(ProgramState ps);

    @Override
    String toString();
}
