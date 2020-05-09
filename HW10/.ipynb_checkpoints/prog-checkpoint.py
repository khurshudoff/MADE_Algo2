import sys
from pyparsing import pyparsing_common, ParserElement, Word, alphas, Literal, oneOf, infixNotation, opAssoc

def make_oper(v1, op, v2):
    if op == '+':
        return v1 + v2
    if op == '-':
        return v1 - v2
    if op == '*':
        return v1 * v2
    if op == '/':
        if v2 == 0:
            raise ZeroDivisionError("Division by zero, {} / {}".format(v1, v2))
        return v1 / v2

def calculate(arr):
    if type(arr) == type(2):
        return arr
    if type(arr) == type('s'):
        if arr not in variables:
            raise BaseException("Variable {} is not defined".format(arr))
        return variables[arr]
        
    res = calculate(arr[0])
    i = 1
    while i < len(arr):
        op = arr[i]
        i += 1
        val = calculate(arr[i])
        i += 1
        res = make_oper(res, op, val)
    return res

ParserElement.enablePackrat()
sys.setrecursionlimit(3000)

integer = pyparsing_common.integer # helps to parse unsigned int
variable = Word(alphas, exact=1) # helps to parse variable (should consist)
operand = integer | variable # define operand as integer | variable

multop = oneOf("* /") # define alternative operators
plusop = oneOf("+ -") # define alternative operators

# define expression which consists of operands and operators
# infixNotation = notations we use every day
expr = infixNotation(
    operand,
    [
        (multop, 2, opAssoc.LEFT), # define operator sign, ammount of operands, assoc
        (plusop, 2, opAssoc.LEFT),
    ]
)

# define expression for parsing start of string 'A = '
start_expr = infixNotation(variable,[('=', 1, opAssoc.LEFT)]) 


test = [
    "A = 9 - 2",
    "B = 1 + A - 4 * 3",
    "D = 33",
    "C = 8 / 4 / 2",
    "A = A * (5 + 5)",
    "2 = 2",
    "Q = E * E",
]

variables = {}
        
for t in test:
    try:
        start = t[:t.find('=') + 1]
        var, eq = start_expr.parseString(start, parseAll=True)[0]

        t = t[t.find('=') + 1:]
        variables[var] = calculate(expr.parseString(t, parseAll=True)[0])
        print(var, '=', variables[var])
        
    except BaseException as e:
        print(e)