#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum class Choice {
    ROCK,
    PAPER,
    SCISSOR,
};

enum class Outcome {
    LOSE,
    DRAW,
    WIN,
};

int main() {
    // There are 6 possible mappings.
    map<char, Choice> char_to_choice = {
        {'A', Choice::ROCK},
        {'B', Choice::PAPER},
        {'C', Choice::SCISSOR},
        {'X', Choice::ROCK},
        {'Y', Choice::PAPER},
        {'Z', Choice::SCISSOR},
    };

    map<char, Outcome> char_to_outcome = {
        {'X', Outcome::LOSE},
        {'Y', Outcome::DRAW},
        {'Z', Outcome::WIN},
    };

    map<pair<Choice, Choice>, int> choice_to_score = {
        {{Choice::ROCK, Choice::ROCK}, 3 + 1},
        {{Choice::ROCK, Choice::PAPER}, 1},
        {{Choice::ROCK, Choice::SCISSOR}, 6 + 1},
        {{Choice::PAPER, Choice::ROCK}, 6 + 2},
        {{Choice::PAPER, Choice::PAPER}, 3 + 2},
        {{Choice::PAPER, Choice::SCISSOR}, 2},
        {{Choice::SCISSOR, Choice::ROCK}, 3},
        {{Choice::SCISSOR, Choice::PAPER}, 6 + 3},
        {{Choice::SCISSOR, Choice::SCISSOR}, 3 + 3},
    };

    map<pair<Outcome, Choice>, Choice> outcome_to_choice = {
        {{Outcome::LOSE, Choice::ROCK}, Choice::SCISSOR},
        {{Outcome::LOSE, Choice::PAPER}, Choice::ROCK},
        {{Outcome::LOSE, Choice::SCISSOR}, Choice::PAPER},
        {{Outcome::DRAW, Choice::ROCK}, Choice::ROCK},
        {{Outcome::DRAW, Choice::PAPER}, Choice::PAPER},
        {{Outcome::DRAW, Choice::SCISSOR}, Choice::SCISSOR},
        {{Outcome::WIN, Choice::ROCK}, Choice::PAPER},
        {{Outcome::WIN, Choice::PAPER}, Choice::SCISSOR},
        {{Outcome::WIN, Choice::SCISSOR}, Choice::ROCK},
    };

    string line;
    int score = 0;

    while (getline(cin, line)) {
        auto opponent_choice = char_to_choice[line[0]];
        auto outcome =  char_to_outcome[line[2]];
        auto player_choice = outcome_to_choice[{outcome, opponent_choice}];

        score += choice_to_score[{player_choice, opponent_choice}];
    }

    cout << score << endl;
}