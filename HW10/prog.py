from pyparsing import infixNotation, opAssoc, Keyword, Word, alphas, ParserElement, oneOf, pyparsing_common
from classes import *
import sys

EPS = 1e-5

ParserElement.enablePackrat()

TRUE = Keyword("True")
FALSE = Keyword("False")
integer = pyparsing_common.integer
variable = Word(alphas, exact=1)

operand = TRUE | FALSE | integer | variable
operand.setParseAction(Operand)

operators = [
    ("!", 1, opAssoc.RIGHT, BoolNot),
    ("&", 2, opAssoc.LEFT, BoolAnd),
    ("^", 2, opAssoc.LEFT, BoolXOR),
    ("|", 2, opAssoc.LEFT, BoolOr),
    ("/", 2, opAssoc.LEFT, IntDiv),
    ("*", 2, opAssoc.LEFT, IntMult),
    ("-", 2, opAssoc.LEFT, IntMinus),        
    ("+", 2, opAssoc.LEFT, IntPlus),
]

expr = variable + '=' + infixNotation(operand, operators)

variables_dict = {}

tests = []
print(sys.argv)
with open(sys.argv[-1])  as f:
    lines = f.readlines()
    for line in lines:
        sp_l = line.split(',')
        tests.append((sp_l[0], eval(sp_l[1])))

cnt_fail = 0
cnt_err = 0
cnt_correct = 0
for t, expected in tests:
    try:
        var, _, res = expr.parseString(t, parseAll=True)
        success = "PASS" if expected - EPS< res.calc() < expected + EPS else "FAIL"
        variables_dict[var] = res.calc()
        if success == "FAIL":
            cnt_fail += 1
            print(success, "\ntest:", t, "\nparsed: ", res, "=", res.calc(), "\ncorrect =", expected)
        else:
            cnt_correct += 1
    except BaseException as e:
        cnt_err += 1
        print("ERROR", e)
        print("test:", t)
        print("_" * 50)
        
print('Всего тестов: {}, из них: \n\tправильных: {}, \
\n\tс ошибкой при вычислении: {}, \n\tс ошибкой при парсинге: {}' \
      .format(len(tests), cnt_correct, cnt_fail, cnt_err))