# File: napoli_38_hw11.py
# Created by: Michael Napoli
# Due date: 7/23/2021

# Comments and test cases removed by request.

import numpy as np

class Complex:
    def __init__(self, i, j):
        self.i = i
        self.j = j

    def __str__(self):
        return str(self.i) + " + " + str(self.j) + "i"

    def __repr__(self):
        return str(self.i) + " +  " + str(self.j) + "i"

    def __add__(self, other):
        return Complex(self.i + other.i, self.j + other.j)

    def __sub__(self, other):
        return Complex(self.i - other.i, self.j - other.j)

    def __mul__(self, other):
        return Complex(self.i * other.i - self.j * other.j, self.i * other.j + self.j * other.i)


    def conjugate(self):
        return Complex(self.i, -self.j)

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
