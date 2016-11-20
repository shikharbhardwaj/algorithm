#include <stdio.h>
#include <stdlib.h>

#define max_vertex 1024

const int NONE = -1, NOT_SET = -2;
int cur_time;
int parent[max_vertex];
int start_time[max_vertex];
int end_time[max_vertex];
int edges[max_vertex][max_vertex];
enum colors { WHITE, GREY, BLACK };
enum edge_type { TREE = 1, FWD = 2, BWD = 3, CROSS = 4 };
typedef struct AdjListNode {
    int id;
    struct AdjListNode *next;
} AdjListNode, node;

typedef struct AdjList {
    int v_id;
    int deg;
    struct AdjListNode *first;
} AdjList;

typedef struct graph {
    int V, E;
    struct AdjList *adj;
} graph;

void end_node(AdjListNode *cur) {
    if (cur == NULL)
        return;
    end_node(cur->next);
    free(cur);
}
void end_graph(graph *in) {
    for (int i = 0; i < in->V; i++) {
        end_node(in->adj[i].first);
    }
    free(in->adj);
}
graph *init_graph(int V) {
    graph *new_graph = (graph *)malloc(sizeof(graph));
    new_graph->V = V;
    new_graph->E = 0;
    new_graph->adj = (AdjList *)malloc(sizeof(AdjList) * V);
    for (int i = 0; i < V; i++) {
        new_graph->adj[i].first = NULL;
        new_graph->adj[i].v_id = i;
        new_graph->adj[i].deg = 0;
    }
    return new_graph;
}
AdjListNode *append(AdjListNode *cur, int id) {
    if (cur != NULL) {
        cur->next = append(cur->next, id);
    } else {
        cur = (AdjListNode *)malloc(sizeof(AdjListNode));
        cur->id = id;
        cur->next = NULL;
    }
    return cur;
}
AdjListNode *prepend(AdjListNode *first, int id) {
    AdjListNode *cur = (AdjListNode *)malloc(sizeof(AdjListNode));
    cur->id = id;
    cur->next = first;
    return cur;
}
void add_edge(graph *in, int id1, int id2) {
    in->adj[id1].first = prepend(in->adj[id1].first, id2);
    in->adj[id1].deg++;
    /*in->adj[id2].first = prepend(in->adj[id2].first, id1);*/
    /*in->adj[id2].deg++;*/
    in->E++;
}
void to_string(graph *in) {
    printf("Graph instance with V = %d, E = %d\n", in->E, in->V);
    AdjListNode *cur = NULL;
    for (int i = 0; i < in->V; i++) {
        printf("[%d] (%d, %d)", i, start_time[i], end_time[i]);
        cur = in->adj[i].first;
        while (cur != NULL) {
            printf("-> %d", cur->id);
            cur = cur->next;
        }
        printf("\n");
    }
}
void DFS_visit(int id, graph *in) {
    cur_time++;
    start_time[id] = cur_time;
    AdjListNode *cur_vertex = in->adj[id].first;
    while (cur_vertex != NULL) {
        if (parent[cur_vertex->id] == NOT_SET) {
            parent[cur_vertex->id] = id;
            edges[id][cur_vertex->id] = TREE;
            DFS_visit(cur_vertex->id, in);
        } else {
            if (end_time[cur_vertex->id] == NOT_SET) {
                edges[id][cur_vertex->id] = BWD;
            } else if (start_time[id] < start_time[cur_vertex->id]) {
                edges[id][cur_vertex->id] = FWD;
            } else {
                edges[id][cur_vertex->id] = CROSS;
            }
        }
        cur_vertex = cur_vertex->next;
    }
    cur_time++;
    end_time[id] = cur_time;
}
void DFS(graph *in) {
    /*Set up initial states*/
    cur_time = 0;
    for (int i = 0; i < in->V; i++) {
        start_time[i] = end_time[i] = parent[i] = NOT_SET;
        for (int j = 0; j < in->V; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < in->V; i++) {
        if (parent[i] == NOT_SET) {
            printf("Connected component with : %d", i);
            parent[i] = NONE;
            DFS_visit(i, in);
        }
    }
}
int has_cycle(graph *in) {
    DFS(in);
    for (int i = 0; i < in->V; i++) {
        for (int j = 0; j < in->V; j++) {
            if (edges[i][j] == BWD)
                return 1;
        }
    }
    return 0;
}
int partition_with(int *ar, int *sat, int l, int r) {
    int pivot = ar[l];
    int temp;
    int i = l, j = r;
    while (1) {
        do {
            i++;
        } while (i < r && ar[i] < pivot);
        do {
            j--;
        } while (ar[j] > pivot);
        if (i > j) {
            break;
        }
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
        temp = sat[i];
        sat[i] = sat[j];
        sat[j] = temp;
    }
    temp = ar[l];
    ar[l] = ar[j];
    ar[j] = temp;
    temp = sat[l];
    sat[l] = sat[j];
    sat[j] = temp;
    return j;
}
void quick_sort_with(int *ar, int *sat, int l, int r) {
    if (r <= l)
        return;
    int j = partition_with(ar, sat, l, r);
    quick_sort_with(ar, sat, l, j);
    quick_sort_with(ar, sat, j + 1, r);
}
void top_sort(graph *in) {
    DFS(in);
    int *indices = (int *)malloc(sizeof(int) * in->V);
    for (int i = 0; i < in->V; i++) {
        indices[i] = i;
    }
    quick_sort_with(end_time, indices, 0, in->V);
    for (int i = in->V - 1; i >= 0; i--) {
        printf("%d : ", indices[i]);
    }
    free(indices);
}
void bfs(int id, graph *in) {
    for (int i = 0; i < in->V; i++) {
        parent[i] = NOT_SET;
    }
    node *frontier = (node *)malloc(sizeof(node));
    frontier->id = id;
    frontier->next = NULL;
    parent[id] = NONE;
    while (frontier) {
        node *next = NULL, *temp;
        while (frontier) {
            node *cur = in->adj[frontier->id].first;
            while (cur) {
                if (parent[cur->id] == NOT_SET) {
                    printf("Visit %d\n", cur->id);
                    parent[cur->id] = frontier->id;
                    temp = (node *)malloc(sizeof(node));
                    temp->id = cur->id;
                    temp->next = next;
                    next = temp;
                }
                cur = cur->next;
            }
            temp = frontier->next;
            free(frontier);
            frontier = temp;
        }
        frontier = next;
    }
}
int main() {
    graph *G = init_graph(6);
    add_edge(G, 0, 1);
    add_edge(G, 0, 5);
    add_edge(G, 5, 1);
    add_edge(G, 4, 5);
    add_edge(G, 2, 4);
    add_edge(G, 2, 3);
    add_edge(G, 4, 1);
    DFS(G);
    end_graph(G);
    free(G);
}
