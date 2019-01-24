package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.IDictionary;
import Model.Utils.MyDictionary;

import java.util.ArrayList;

public class CallStmt implements IStatement {

    String fname; // function name
    ArrayList<IExpression> expList = new ArrayList<>();

    public CallStmt(String fname, ArrayList<IExpression> expList) {
        this.fname = fname;
        this.expList = expList;
    }


    @Override
    public ProgramState execute(ProgramState ps) {


        //if(!ps.getProcTable().contains(fname))
        //    throw new RuntimeException("procedure " + this.fname + " does not exist!"");

        ArrayList<Integer> evaluateExp = new ArrayList<>();
        for(IExpression exp : this.expList)
            evaluateExp.add(exp.evaluate(ps.getTopSymTable(), ps.getHeap()));


        IDictionary<String, Integer> symTab = new MyDictionary<>();

        for(int i = 0; i < ps.getProcTable().get(fname).getList().size(); i++)
            symTab.put(ps.getProcTable().get(fname).getList().get(i), evaluateExp.get(i));

        ps.getStackSymTable().push(symTab);
        ps.getExeStack().push(new ReturnStmt());
        ps.getExeStack().push(ps.getProcTable().get(fname).getStatement());


        return null;
    }



    @Override
    public String toString(){
        String x = new String();
        x+="call("+fname +"(";
        for(IExpression e : expList)
            x += e + ", ";
        x += "))";

        return x;
    }


}