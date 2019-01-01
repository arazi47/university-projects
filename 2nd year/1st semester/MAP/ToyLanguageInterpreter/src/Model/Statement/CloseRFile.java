package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.Tuple;

import java.io.BufferedReader;
import Exception.CustomException;

public class CloseRFile implements IStatement {
    private IExpression fileIdExp;

    public CloseRFile(IExpression fileIdExp) {
        this.fileIdExp = fileIdExp;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        int fd = this.fileIdExp.evaluate(ps.getSymTable(), ps.getHeap());
        Tuple<String, BufferedReader> br = ps.getFileTable().get(fd);

        if (br == null) {
            throw new CustomException("File not opened @TODO make a new exception class for this!");
        }

        try {
            // close the file
            br.getSecond().close();

            // Don't remove the file if we want to see it in the GUI for testing
            ps.getFileTable().remove(fd);

        } catch (java.io.IOException e) {
            System.out.println(e.toString());
        }

        return null;
    }

    @Override
    public String toString() {
        return "closeRFileStmt(" + this.fileIdExp.toString() + ")";
    }
}
