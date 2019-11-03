from Model.SymbolTable import SymbolTable
from Scanner import *
from Model.ProgramInternalForm import *


def main():
    file = open('input.txt', 'r')
    st = SymbolTable()
    pif = ProgramInternalForm()

    line_index = 0
    for line in file:
        line_index += 1

        # Hacky way of inserting comments
        # TODO simple regexp for this and add '#' to reserved keywords
        if line[0] == '#':
            print("Line at index {} is a comment.".format(line_index))
            continue

        if line[-1] == '\n':
            line = line[0:-1]  # Skip \n

        for token in Scanner.get_tokens_from_line(line):
            if token in op_sep_res:
                pif.add(codification_table[token], -1)
            elif Scanner.is_identifier(token):
                # Add and return id or just return id
                pif.add(codification_table['identifier'], st.add(token))
            elif Scanner.is_constant(token):
                # Add and return id or just return id
                pif.add(codification_table['constant'], st.add(token))
            else:
                print("Unknown token '{}' at line {}!".format(token, line_index))

    print("Symbol table: {}".format(st))
    print("Program internal form: {}".format(pif))


if __name__ == '__main__':
    main()
