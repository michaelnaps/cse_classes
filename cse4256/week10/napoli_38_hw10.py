# File: napoli_38_hw10.py
# Created by: Michael Napoli
# Due Date: 7/16/2021

import math as mt

# Problem 1
class Fraction:
    def __init__(self, num, den = None):
        if den != None:
            GCD = int(mt.gcd(num, den))

            if den > 0:
                self.num = int(num / GCD)
                self.den = int(den / GCD)
            else:
                self.num = int(-num / GCD)
                self.den = int(-den / GCD)

        else:
            num_str = ''
            den_str = ''

            frac_sign = True
            for i in range(0, len(num)):
                if num[i] == '/':
                    frac_sign = False

                if frac_sign:
                    num_str += num[i]
                elif not frac_sign and num[i] != '/':
                    den_str += num[i]

            self.num = int(num_str)
            self.den = int(den_str)


    def __repr__(self):
        return str(self.num) + '/' + str(self.den)

    def __mul__(self, other):
        return Fraction(self.num * other.num, self.den * other.den)


    #If f is a Fractions, then ~f returns a Fraction that is the
    #reciprocal of f
    def __invert__(self):
        return Fraction(self.den, self.num)

    #If f is a Fractions, then -f returns a Fraction that is the
    # negation of f.
    def __neg__(self):
        return Fraction(-self.num, self.den)

    #If f and g are Fractions, then f + g returns a Fraction that is the
    # sum of f and g
    def __add__(self, other):
        num_self = self.num * other.den
        den_self = self.den * other.den

        num_other = other.num * self.den
        den_other = other.den * self.den

        return Fraction(num_self + num_other, den_self)


    #If f and g are Fractions, then f - g returns a Fraction that is the
    # difference of f and g
    #You should implement this method without calling the constructor directly.
    def __sub__(self, other):
        num_self = self.num * other.den
        den_self = self.den * other.den

        num_other = other.num * self.den
        den_other = other.den * self.den

        return Fraction(num_self - num_other, den_self)

    #If f and g are Fractions, then f / g returns a Fraction that is the
    # quotient of f and g
    #You should implement this method without calling the constructor directly.
    def __truediv__(self, other):
        return self * ~other  # multiply by reciprocal

    #Returns true if self < other. False otherwise
    def __lt__(self, other):
        val = self / other
        dec = val.num / val.den
        return dec < 1

    #Returns the absolute value of self. If f is a Fraction, this is called as abs(f).
    def __abs__(self):
        if self.num > 0:
            return Fraction(self.num, self.den)
        else:
            return Fraction(-self.num, self.den)

    ##Returns a string representation of self as a mixed number. For example, 12/5 as a mixed number is "2 2/5".
    def mixed_number(self):
        n = 0
        while self.num >= (n + 1) * self.den:
            n += 1

        return str(n) + ' ' + str(Fraction(self.num - n * self.den, self.den))

# test case - initialization
print(Fraction(3, 4))     # 3/4
print(Fraction(-3, 4))    # -3/4
print(Fraction(3, -4))    # -3/4
print(Fraction(-3, -4))   # 3/4
print(Fraction(-6, -16))  # 1/2

# test case - multiply
print(Fraction(3, 4) * Fraction(10, 3))
print(Fraction(1, 2) * Fraction(3, 4))

# test case - addition
print(Fraction(3, 4) + Fraction(1, 2))

# test case - subtraction
print(Fraction(3, 4) - Fraction(1, 2))

# test case - division
print(Fraction(3, 4) / Fraction(1, 2))

# test case - less than
print(Fraction(3, 4) < Fraction(1, 2))
print(Fraction(1, 2) < Fraction(3, 4))

# test case - absolute value
print(abs(Fraction(3, 4)))
print(abs(Fraction(-3, 4)))
print(abs(Fraction(3, -4)))

# test case - mixed number
print(Fraction(12, 5).mixed_number())
print(Fraction(4, 2).mixed_number())

# test case - string representation
print(Fraction("12/14"))
