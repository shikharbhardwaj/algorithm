def num_filter_combinations(filters, image):
    # Construct matrix from filters + image (simple transpose).
    M = [list(tup) for tup in zip(*(filters + [image]))]

    # Gaussian elimination over GF(2).
    last_pivot = -1
    n, m = len(M), len(M[0])
    for i in range(n):
        for j in range(m-1):
            if M[i][j]:
                last_pivot = j
                for k in range(n):
                    if k == i: continue
                    if M[k][j]:
                        for t in range(m):
                            M[k][t] ^= M[i][t]
                break

    # Check for inconsistent matrix.
    for row in M:
        if not any(row[:-1]) and row[-1]:
            return 0

    # Number of filter combations is 2 to the power of the number of free variables.
    return 2 ** (len(filters) - (last_pivot + 1))


filters = [
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0],
    [0,  0,  0,  0, 0, 0, 0, 0, 0], 
    [1,  0,  0,  0, 0, 0, 0, 0, 0]
]

image = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

print(num_filter_combinations(filters, image))
