from ctypes import CDLL, Structure, c_int, c_ulonglong, c_uint

lib = CDLL('./libc_lib.so')

class DiophantineSolution(Structure):
	_fields_ = [("x", c_int), ("xk", c_int), ("y", c_int), ("yk", c_int)]

factorialL = lib.factorialL
factorialL.argtypes = [c_uint]
factorialL.restype = c_ulonglong

factorialR = lib.factorialR
factorialR.argtypes = [c_uint]
factorialR.restype = c_ulonglong

gcdL = lib.gcdL
gcdL.argtypes = [c_uint, c_uint]
gcdL.restype = c_uint

gcdR = lib.gcdR
gcdR.argtypes = [c_uint, c_uint]
gcdR.restype = c_uint

diophantineEqL = lib.diophantineEqL
diophantineEqL.argtypes = [c_int, c_int, c_int]
diophantineEqL.restype = DiophantineSolution

diophantineEqR = lib.diophantineEqR
diophantineEqR.argtypes = [c_int, c_int, c_int]
diophantineEqR.restype = DiophantineSolution