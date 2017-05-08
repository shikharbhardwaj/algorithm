def subset_sum_util(idx, cur_sum, x, target, select):
	if cur_sum == target:
		return True
	if idx >= len(x):
		return False

	for i in range(idx, len(x)):
		if x[i] + cur_sum <= target:
			select[i] = 1
			if subset_sum_util(i + 1, cur_sum + x[i], x, target, select):
				return True
			else:
				select[i] = 0
	return False

def subset_sum(x, t):
	x.sort()
	select = [0] * len(x)
	cur_sum = 0
	print(subset_sum_util(0, cur_sum, x, t, select))
	print(x)
	print(select)

subset_sum([15, 22, 14, 26, 32, 9, 16], 41)