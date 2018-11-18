package Model.Utils;

import java.util.Stack;
import Exception.StackException;

public class MyStack<T> implements IStack<T> {
    private Stack<T> stack;

    public MyStack(){
        stack = new Stack<T>();
    }

    @Override
    public void push(T elem) {
        stack.push(elem);
    }

    @Override
    public T pop() {
        if (this.stack.isEmpty()) {
            throw new StackException("[Stack error] Stack is empty!");
        }

        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    public String toString(){
        StringBuilder s = new StringBuilder();
        for(T elem : this.stack) {
            s.append(elem.toString()).append(" ");
        }

        return s.toString();
    }

    @Override
    public void clear() {
        this.stack.clear();
    }
}
