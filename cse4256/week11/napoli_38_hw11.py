# Complete the class below, which represents complex numbers, and upload your file to Carmen.
# This assignment is due on Friday, July 23.

import numpy as np

# You should do some research using Google if you have forgotten (or never knew) what some of the terms mean.
class Complex:
    def __init__(self, i, j):
        self.i = i
        self.j = j


    def __str__(self):
        return str(self.i) + " + " + str(self.j) + "i"


    def __repr__(self):
        return str(self.i) + " +  " + str(self.j) + "i"


    # The following method adds two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead.
    def __add__(self, other):
        return Complex(self.i + other.i, self.j + other.j)


    # The following method subtracts two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead.
    def __sub__(self, other):
        return Complex(self.i - other.i, self.j - other.j)


    # The following method multiplies two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead.
    def __mul__(self, other):
        return Complex(self.i * other.i - self.j * other.j, self.i * other.j + self.j * other.i)


    def conjugate(self):
        return Complex(self.i, -self.j)


    # The following method divides two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead.
    def __truediv__(self, other):
        num = self * other.conjugate()        # complex number
        den = other * other.conjugate()       # integer
        return Complex(num.i / den.i, num.j / den.i)


    def modulus(self):
        return np.sqrt(self.i**2 + self.j**2)


    def midpoint(self, other):
        return Complex((self.i + other.i) / 2, (self.j + other.j) / 2)


    def argument(self):
        return np.arctan(self.j / self.i)


c_num_1 = Complex(1, 3)
c_num_2 = Complex(2, 1)  # arbitrary values
print(c_num_1)
print(c_num_2)

# test case - addition
print(c_num_1 + c_num_2)

# test case - subtract
print(c_num_1 - c_num_2)

# test case - multiply
print(c_num_1 * c_num_2)

# test case - conjugate
print(c_num_1.conjugate())

# test case - division
print(c_num_1 / c_num_2)

# test case - modulus
print(c_num_1.modulus())

# test case - midpoint
print(c_num_1.midpoint(c_num_2))

# test case - argument
print(c_num_1.argument())
