class Operand:
    def __init__(self, t):
        self.label = t[0]
        if type(t[0]) == type("s"):
            if t[0] == "True" or t[0] == "False":
                self.value = eval(t[0])
            else:
                if t[0] not in variables_dict:
                    raise BaseException("Unknown variable {}".format(t[0]))
                self.value = variables_dict[t[0]]
        else:
            self.value = t[0]


    def calc(self):
        return self.value

    def __str__(self):
        return str(self.label)

    __repr__ = __str__


class BoolBinOp:
    def __init__(self, t):
        self.args = t[0][0::2]

    def __str__(self):
        sep = " %s " % self.reprsymbol
        return "(" + sep.join(map(str, self.args)) + ")"

    def calc(self):
        return self.evalop(a.calc() for a in self.args)

    __nonzero__ = calc

class BoolAnd(BoolBinOp):
    reprsymbol = "&"
    evalop = all

class BoolOr(BoolBinOp):
    reprsymbol = "|"
    evalop = any
    
class BoolXOR(BoolBinOp):
    def calc(self):
        res, *tail = self.args
        res = res.calc()
        while tail:
            h, *tail = tail
            res = res ^ h.calc()
        return res

    __nonzero__ = calc  
    reprsymbol = "^"
    
class BoolNot:
    def __init__(self, t):
        self.arg = t[0][1]

    def calc(self):
        v = self.arg.calc()
        return not v

    def __str__(self):
        return "!" + str(self.arg)

    __repr__ = __str__

class IntBinOp:
    def __init__(self, t):
        self.args = t[0][0::2]
    
    def __str__(self):
        sep = " %s " % self.reprsymbol
        return "(" + sep.join(map(str, self.args)) + ")"
    
class IntPlus(IntBinOp):
    def calc(self):
        res, *tail = self.args
        res = res.calc()
        while tail:
            h, *tail = tail
            res = res + h.calc()
        return res

    __nonzero__ = calc  
    reprsymbol = "+"
    
class IntMinus(IntBinOp):
    def calc(self):
        res, *tail = self.args
        res = res.calc()
        while tail:
            h, *tail = tail
            res = res - h.calc()
        return res

    __nonzero__ = calc  
    reprsymbol = "-"

class IntMult(IntBinOp):
    def calc(self):
        res, *tail = self.args
        res = res.calc()
        while tail:
            h, *tail = tail
            res = res * h.calc()
        return res

    __nonzero__ = calc
    reprsymbol = "*"

class IntDiv(IntBinOp):
    def calc(self):
        res, *tail = self.args
        res = res.calc()
        while tail:
            h, *tail = tail
            if h.calc() == 0:
                raise ZeroDivisionError("Division by zero because {} is equal to zero".format(h))
            res = res / h.calc()
        return res

    __nonzero__ = calc  
    reprsymbol = "/"