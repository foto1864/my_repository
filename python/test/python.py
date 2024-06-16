# Get ready bitches Im writing in python

import math

a = input("Give a number for a: ")
b = input("Give a number for b: ")
c = input("Give a number for c: ")

if a == 0:
    print("That ain't no quadradic fam we playin?")
    exit

print("Your quadradic is: "+a+"(x^2)+"+b+"x+"+c)

delta = int(b)*int(b) - 4*int(a)*int(c)

print(delta)

if delta > 0:
    x1 = (-int(b) + math.sqrt(delta)) / 2 * int(a)
    x2 = (-int(b) - math.sqrt(delta)) / 2 * int(a)
    print("Solutions are: "+str(x1)+" and "+str(x2))
elif delta == 0:
    x = (-int(b) + math.sqrt(delta)) / 2 * int(a)
    print("Solution is: "+str(x))
else :
    print("There are no solutions to your quadradic.")
