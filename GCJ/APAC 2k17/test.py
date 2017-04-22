#!/usr/bin/env python3

def num_possibilities(score_a, score_b, N, M, cur):
	print((score_a, score_b, N, M, cur), end="")
	if score_b >= score_a:
		print("x")
		return 0

	if N == 0 or M == 0:
		return cur

	return num_possibilities(score_a + 1, score_b, N - 1, M, cur * N) + \
			num_possibilities(score_a, score_b + 1, N, M - 1, cur * M)

if __name__ == '__main__':
	print(num_possibilities(1, 0, 2, 1, 3))