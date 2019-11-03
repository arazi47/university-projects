"""
    Language specifications file
"""

operators = ['+', '-', '*', '/', '=', '==', '<', '<=', '>', '>=']
separators = ['(', ')', '{', '}', ' ', ';', "\""]
reserved = ['bool', 'int', 'read', 'print', 'if', 'else', 'while']

op_sep_res = operators + separators + reserved

codification_table = {'constant': 0, 'identifier': 1}
for i in range(len(op_sep_res)):
    codification_table[op_sep_res[i]] = i + 2

