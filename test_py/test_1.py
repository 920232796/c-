import numpy as np


w = np.array([[0.1, 0.5],[-0.3, 0.8]])
print(w)

x = np.array([[0.2], [0.4]])

print(x)

print("W * X: " + str(w.dot(x)))

q = w.dot(x)

dW = (2 * q.dot(x.T))

print("dW: " + str(dW))
