#include <cstdio>
#include <cmath>
#include <limits>
#define gc getchar_unlocked

void scanint(int &x){
    int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int size, M;
struct segTreeNode{
    long long sum, min, max, update;
    bool noUpdate;
    segTreeNode() : sum(0), min(-1), max(-1), update(false), noUpdate(false) {}
    void setState(long long  min, long long max, long long sum, long long update){
        this->min = min;
        this->max = max;
        this->sum = sum;
        this->update = update;
        noUpdate = false;
    }
};
int getSegTreeSize(int n){
    float logVal = log2(n);
    if(logVal == (int)logVal){
        return 2 * n;
    }
    return  pow(2, (int)logVal + 2);
}
long long ar[100005];
segTreeNode tree[262145];
int id = 0;
void buildTree(int index, int min, int max){
    tree[index].setState(min, max, 0, false);
    if(min == max && min != -1){
        tree[index].sum = ar[id++];
        return;
    }
    buildTree(2*index, min, (min+max)/2);
    buildTree(2*index+1, (min+max)/2+1, max);
    tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
}
void sumSqrt(int index, int min, int max, int times){
    if(tree[index].sum == 1){
        return;
    }
    if(min == max){
        for(int i = 0; i < times && tree[index].sum != 1; i++){
            tree[index].sum = sqrt(tree[index].sum);
        }
        return;
    }
    sumSqrt(2*index, min, (min+max)/2, times);
    sumSqrt(2*index+1, (min+max)/2 + 1, max, times);
    tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
}
void update(int index, int min, int max){
    if(tree[index].noUpdate){
        return;         //The update is pretty useless now!
    }
    if(tree[index].update){
        tree[index].update++;
        sumSqrt(index, tree[index].min, tree[index].max, tree[index].update);
        if(tree[index].sum == tree[index].max - tree[index].min + 1){
            tree[index].noUpdate = true;
        }
        tree[index].update = 0;
    }
    if( tree[index].max < min || tree[index].min > max ){
        return;
    }
    else if( min <= tree[index].min && max >= tree[index].max ){
        tree[index].update++;
        sumSqrt(index, tree[index].min, tree[index].max, tree[index].update);
        if(tree[index].sum == tree[index].max - tree[index].min + 1){
            tree[index].noUpdate = true;
        }
        tree[index].update = 0;
        return;
    }
    update(2*index, min, max);
    update(2*index+1, min, max);
    tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
}
void query(int index, int min, int max, long long &ret){
    if(tree[index].update && tree[index].noUpdate == false){
        sumSqrt(index, tree[index].min, tree[index].max, tree[index].update);
        if(tree[index].sum == tree[index].max - tree[index].min + 1){
            tree[index].noUpdate = true;
        }
        tree[index].update = 0;
    }
    if( tree[index].max < min || tree[index].min > max ){
        return;
    }
    else if( min <= tree[index].min && max >= tree[index].max ){
        ret += tree[index].sum;
        return;
    }
    query(2*index, min, max, ret);
    query(2*index+1, min, max, ret);
}
int main(){
    int i, x, y;
    long long S;
    while(scanf("%d", &size)){
        id = 0;
        for(int i = 0; i < size; i++){ 
            scanf("%lld", &ar[i]);
        }
        buildTree(1, 1, size);
        scanf("%d", &M);
        while(M--){
            scanint(i);
            scanint(x);
            scanint(y);
            if(i == 0){
                update(1, x, y);
            }
            else{
                S = 0;
                query(1, x, y, S);
                printf("%lld\n", S);
            }
        }
    }
}
