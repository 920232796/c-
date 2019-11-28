print("hello")

import numpy as np 


if __name__ == "__main__":

    v1 = np.array([[-1, -2, -3], [4, 5, 6]])

    print((v1 > 0).astype(np.float))

    print((np.random.rand(2, 3) < 0.5) / 0.5)


    x_ = np.pad(v1, ((2, 2), (2, 2)), "constant")

    print("~~~~~~")
    
    print(x_)


    print("~~~~~~~~~~~")

    v2 = np.array([  [[1, 2, 3], [1, 2, 3]], [[1, 2, 3], [1, 2, 3]]    ])
    print(v2.shape)
    print(v2)
    print(np.sum(v2, axis=2))


    print("~~~~~~~~~~~~~~")

    list1 = [[1, 2, 3], [4, 5, 6]]

    list3 = []
    list3.append(list1)
    list3.append(list1)

    print(np.array(list3[::-1]))

    print("~~~~~~~~")

    i = 5
    if i == 5:
        next1 = 1
    print(next1)

