#define NONIUS_RUNNER
#include <nonius/nonius.h++>
#include "../implementations/graph.hpp"
graph<int, graph_types::list> grp;
NONIUS_BENCHMARK("boost::unordered_map", [](nonius::chronometer meter) {
    meter.measure([] {
        for(int i = 0; i < 10000; i++){
            grp.add_vertex(i);
        }
        for(int i = 0; i < 10000; i++){
            grp.add_edge(i, 9999-i);
        }
        return 0;
        });
});
