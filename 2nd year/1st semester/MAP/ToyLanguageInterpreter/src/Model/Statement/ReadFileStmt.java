package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.Tuple;

import java.io.BufferedReader;
import Exception.CustomException;

public class ReadFileStmt implements IStatement {
    private IExpression fileIdExp;
    private String varName;

    public ReadFileStmt(IExpression fileIdExp, String varName) {
        this.fileIdExp = fileIdExp;
        this.varName = varName;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        int fd = this.fileIdExp.evaluate(ps.getSymTable(), ps.getHeap());

        Tuple<String, BufferedReader> br = ps.getFileTable().get(fd);

        if (br == null) {
            throw new CustomException("File not opened! @TODO do a new exception class here");
        }

        String line = "";
        try {
            line = br.getSecond().readLine();
        } catch (java.io.IOException e) {
            System.out.println(e.toString());
        }

        int val = 0;
        if (line != null) {
            val = Integer.valueOf(line);
        }

        ps.getSymTable().put(this.varName, val);
        return ps;
    }

    @Override
    public String toString() {
        return "readFileStmt(" + this.fileIdExp.toString() + ", " + this.varName + ")";
    }
}
