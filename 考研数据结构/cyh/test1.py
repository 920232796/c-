

import numpy as np 


if __name__ == "__main__":
    v1 = np.array([[1, 2, 3], [-1, -2, 2]])
    v1[v1 > 0] = 1
    print(v1)


    print("~~~~~~~~~~")

    v1 = np.array([[1, 2, 3], [-1, -2, 2]])
    print(v1[:, :-1])