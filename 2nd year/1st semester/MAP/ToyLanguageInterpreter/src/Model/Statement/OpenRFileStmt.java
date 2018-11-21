package Model.Statement;

import Model.ProgramState;
import Model.Utils.Tuple;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import Exception.CustomException;

public class OpenRFileStmt implements IStatement {
    private static int fd = 2;
    private String fileId;
    private String fileName;

    public OpenRFileStmt(String fileId, String fileName) {
        this.fileId = fileId;
        this.fileName = fileName;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        for (Tuple<String, BufferedReader> file : ps.getFileTable().values()) {
            if (file.getFirst().equals(this.fileName)) {
                throw new CustomException("File already opened, cannot add it again @TODO make a new exception class out of this");
            }
        }

        File f = new File("C:\\Users\\necso\\Desktop\\926\\src\\" + this.fileName);
        if (!f.exists()) {
            throw new CustomException("File not found! @TODO make a new exception class out of this");
        }

        int newFileFd = ++OpenRFileStmt.fd;

        try {
            ps.getFileTable().put(newFileFd, new Tuple<String, BufferedReader>(this.fileName, new BufferedReader(new FileReader("C:\\Users\\necso\\Desktop\\926\\src\\" + this.fileName))));
            ps.getSymTable().put(this.fileId, newFileFd);
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
        }

        return null;
    }

    @Override
    public String toString() {
        return "openRFile(" + this.fileId + ", " + this.fileName + ")";
    }
}
