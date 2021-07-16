# File: napoli_38_hw10.py
# Created by: Michael Napoli
# Due Date: 7/16/2021

# Comments and test cases removed by request.

import math as mt

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


    def __invert__(self):
        return Fraction(self.den, self.num)


    def __neg__(self):
        return Fraction(-self.num, self.den)


    def __add__(self, other):
        num_self = self.num * other.den
        den_self = self.den * other.den

        num_other = other.num * self.den
        den_other = other.den * self.den

        return Fraction(num_self + num_other, den_self)


    def __sub__(self, other):
        num_self = self.num * other.den
        den_self = self.den * other.den

        num_other = other.num * self.den
        den_other = other.den * self.den

        return Fraction(num_self - num_other, den_self)


    def __truediv__(self, other):
        return self * ~other


    def __lt__(self, other):
        val = self / other
        dec = val.num / val.den
        return dec < 1


    def __abs__(self):
        if self.num > 0:
            return Fraction(self.num, self.den)
        else:
            return Fraction(-self.num, self.den)


    def mixed_number(self):
        n = 0
        while self.num >= (n + 1) * self.den:
            n += 1

        return str(n) + ' ' + str(Fraction(self.num - n * self.den, self.den))
