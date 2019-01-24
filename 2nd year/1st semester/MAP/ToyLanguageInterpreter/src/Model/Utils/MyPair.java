package Model.Utils;

import Model.Statement.IStatement;

import java.util.ArrayList;

public class MyPair {

    private ArrayList<String> list = new ArrayList<>();
    private IStatement statement;

    public MyPair(ArrayList<String> list, IStatement statement) {
        this.list = list;
        this.statement = statement;
    }

    public void setList(ArrayList<String> list) {
        this.list = list;

    }

    public void setStatement(IStatement statement) {
        this.statement = statement;
    }

    public ArrayList<String> getList() {
        return list;
    }

    public IStatement getStatement() {
        return this.statement;
    }


}