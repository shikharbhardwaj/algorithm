#include <algorithm>
#include <iostream>
#include <vector>
typedef struct proposal {
    char name[81];
    float price;
    int compliance;
} proposal;
int main() {
    std::vector<std::string> winners;
    while (true) {
        int n, p;
        char temp[81];
        scanf("%d %d\n", &n, &p);
        std::vector<proposal> props(p);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            fgets(temp, 81, stdin);
            // Check if legit
            if (temp[0] == '\n')
                i--;
        }
        for (int i = 0; i < p; i++) {
            fgets(props[i].name, 81, stdin);
            // Check if legit
            if (props[i].name[0] == '\n') {
                i--;
                continue;
            }
            scanf("%f ", &props[i].price);
            scanf("%d ", &props[i].compliance);
            for (int j = 0; j < props[i].compliance; j++) {
                // Check if legit
                fgets(temp, 81, stdin);
                if (temp[0] == '\n')
                    j--;
            }
        }
        std::stable_sort(props.begin(), props.end(),
                         [](const proposal &first, const proposal &second) {
                             return first.compliance > second.compliance;
                         });
        int mark;
        int comp = props[0].compliance;
        for (mark = 1; mark < p; mark++) {
            if (props[mark].compliance != comp)
                break;
        }
        // Now find the best price
        std::stable_sort(props.begin(), props.begin() + mark,
                         [](const proposal &first, const proposal &second) {
                             return first.price < second.price;
                         });
        winners.push_back(props[0].name);
    }
    std::string last = winners[winners.size() - 1];
    for (size_t i = 0; i < winners.size() - 1; i++) {
        printf("RFP #%lu\n", i + 1);
        printf("%s\n", winners[i].c_str());
    }
    printf("RFP #%lu\n", winners.size());
    printf("%s", last.c_str());
}
