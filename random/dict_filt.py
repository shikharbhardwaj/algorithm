#!/usr/bin/env python3
def main():
	ans = []

	with open('./words.txt') as f:
		for line in f:
			line = line.strip().lower()
			if len(line) == 6 and line.isalpha():
				ans.append(line)

	print(len(ans))
	for word in ans:
		print(word)


main()