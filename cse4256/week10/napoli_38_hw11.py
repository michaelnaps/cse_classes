#Complete the class below, which represents complex numbers, and upload your file to Carmen.
#This assignment is due on Friday, July 23.

#You should do some research using Google if you have forgotten (or never knew) what some of the terms mean.  

class Complex:
  def __init__(self, i, j):
    self.i = i
    self.j = j
    

  def __str__(self):
    return str(self.i) + " + " + str(self.j) + "i"

  def __repr__(self):
    return str(self.i) + " +  " + str(self.j) + "i"


#The following method adds two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead. 

  def __add__(self, other):
    pass




#The following method subtracts two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead. 
  
  def __sub__(self, other):
    pass




#The following method multiplies two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead. 
  
  def __mul__(self, other):
    pass


  def conjugate(self, other):
    pass

 

  #The following method divides two complex numbers. It should not change the complex numbers passed as arguments, but should return a new complex number instead. 
  def __truediv__(self, other):
    pass


  def modulus(self):
    pass


  def midpoint(self, other):
    pass


  def argument(self):
    pass


i = Complex(2, 3)
print(i)