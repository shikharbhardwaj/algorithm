import os
from dataclasses import dataclass
from typing import List

import numpy as np

NUM_QUESTIONS = 10000
NUM_PLAYERS = 100


@dataclass
class PlayerStats:
    num_correct: int
    mean_correct_difficulty: float
    std_dev_correct_difficulties: float
    correct_difficulties: List[float]
    incorrect_difficulties: List[float]


def solve(answers: List[str]):
    answer_matrix = np.row_stack([[int(x) for x in answer[:NUM_QUESTIONS]] for answer in answers])

    difficulties = 1.0 - (np.array([np.mean(answer_matrix[:, i]) for i in range(NUM_QUESTIONS)]))

    def get_player_stats(player_idx: int, ):
        return PlayerStats(num_correct=len(difficulties[answer_matrix[player_idx] == 1]),
                        mean_correct_difficulty=np.mean(difficulties[answer_matrix[player_idx] == 1]),
                        std_dev_correct_difficulties=np.std(difficulties[answer_matrix[player_idx] == 1]),
                        correct_difficulties=difficulties[answer_matrix[player_idx] == 1],
                        incorrect_difficulties=difficulties[answer_matrix[player_idx] == 0])

    stats = [get_player_stats(i) for i in range(NUM_PLAYERS)]

    return stats.index(max(stats, key=lambda x: x.std_dev_correct_difficulties))


T = int(input())
P = int(input())


for i in range(1, T + 1):
    answers = [input() for _ in range(NUM_PLAYERS)]

    idx = solve(answers)

    print(f"Case #{i}: {idx + 1}")

