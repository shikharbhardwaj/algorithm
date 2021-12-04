#!/usr/bin/env python3
# encoding: utf-8
import sys

from typing import List

REDIRECT = True
old_stdin = sys.stdin

if REDIRECT:
    sys.stdin = open("in.txt", "r")


numbers_input = input()
numbers = [int(x) for x in numbers_input.split(',')]

best_seen = len(numbers)
score = 0

BOARD_SIZE = 5


class BingoBoard:
    def __init__(self, board: List[List[int]]):
        self._val_idx = {}
        self._row_counts = [0 for _ in range(BOARD_SIZE)]
        self._col_counts = [0 for _ in range(BOARD_SIZE)]

        assert(len(board) == BOARD_SIZE)

        for i in range(BOARD_SIZE):
            for j in range(BOARD_SIZE):
                val = board[i][j]
                idx = self._val_idx.get(val, [])
                idx.append((i, j))
                self._val_idx[val] = idx

    def get_sum(self) -> int:
        return sum([k * len(v) for k, v in self._val_idx.items()])

    def is_won(self):
        return BOARD_SIZE in self._row_counts or BOARD_SIZE in self._col_counts

    def mark_number(self, number: int):
        if number not in self._val_idx:
            return

        for i, j in self._val_idx[number]:
            self._row_counts[i] += 1
            self._col_counts[j] += 1

        del self._val_idx[number]


while True:
    # Read the 5 lines of the board.
    board = []

    for line in sys.stdin:
        line = line.strip()

        if not line:
            continue

        board.append([int(x) for x in line.split()])

        if len(board) == BOARD_SIZE:
            break

    if len(board) != BOARD_SIZE:
        break

    bingo = BingoBoard(board)
    seen = 0

    while seen < len(numbers) and not bingo.is_won():
        bingo.mark_number(numbers[seen])
        seen += 1
    
    if seen < best_seen:
        best_seen = seen
        last = numbers[seen - 1]
        bingo_sum = bingo.get_sum()
        score = bingo_sum * last

print(score)

if REDIRECT:
    sys.stdin.close()
    sys.stdin = old_stdin