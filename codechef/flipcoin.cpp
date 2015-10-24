#include <cstdio>
#include <iostream>
#include <cmath>
int limit;
const int startSum = 0;
struct segTreeNode{
    int min, max, sum;
    bool update;
    segTreeNode() : min(-1), max(-1), sum(0), update(false) {}
    void setState(int min, int max, int sum){
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};
segTreeNode *tree;
int getSegTreeSize(int n){
    float logVal = log2(n);     //The hieght of the tree
    if(logVal == (int)logVal){
        return 2*n;
    }
    else{
        return pow(2, (int)logVal + 2);
    }
    //We waste the constant 
    //amount of memory here, but anyways
}
void buildTree(int index, int left, int right){
    if(left == right){      //Yay! leaf node :/
        tree[index].setState(left, right, startSum);
        return;
    }
    int mid = (left + right)/2;     //Split the interval into half
    buildTree(2*index, left, mid);      //Recursively build
    buildTree(2*index+1, mid+1, right);
    tree[index].setState(tree[2*index].min, tree[2*index+1].max, startSum);
    tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
}
void update(int index, int min, int max){
    if(tree[index].update){
        tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
        if(tree[index].max != tree[index].min){
            //This is not a leaf node
            tree[2*index].update = !tree[2*index].update;
            tree[2*index+1].update = !tree[2*index+1].update;
        }
        tree[index].update = false;
    }
    if(min > tree[index].max || max < tree[index].min){
        //This interval is useless!
        return;
    }
    if(min <= tree[index].min && max >= tree[index].max){
        //This is inside the wanted domain, so flip
        tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
        if(tree[index].max != tree[index].min){
            tree[2*index].update = !tree[2*index].update;
            tree[2*index+1].update = !tree[2*index+1].update;
        }
        return;
    }
    update(2*index, min, max);
    update(2*index + 1, min, max);
    tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
}
void sum(int index, int min, int max, long long &ret){
    if(min > tree[index].max || max < tree[index].min){
        return;      //This is not the node which we want
    }
    if(tree[index].update){
        tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
        if(tree[index].max != tree[index].min){
            tree[2*index].update = !tree[2*index].update;
            tree[2*index+1].update = !tree[2*index+1].update;
        }
        tree[index].update = false;
    }
    if(min <= tree[index].min && max >= tree[index].max){
        ret += tree[index].sum;
        return;
    }
    sum(2*index, min, max, ret);
    sum(2*index+1, min, max, ret);
}
void printSpace(int n){
    while(n--){
        std::cout<<" ";
    }
}
void showTree(){
    std::cout<<std::endl;
    int lastPower = 1;
    int index = 1;
    for(int i = 0; i < log2(limit); i++){
        printSpace(12*(log2(limit)-i-1));
        for(int j = 0; j < lastPower && index < limit; j++){
            printSpace(8*(log2(limit)-i));
            std::cout<<"["<<tree[index].min<<", "<<tree[index].max<<"]:"<<tree[index].sum<<"|"<<tree[index].update;
            index++;
        }
        lastPower = lastPower<<1;
        std::cout<<std::endl;
    }
}
int main(){
    int N, Q, T, A, B;
    long long S;
    scanf("%d %d", &N, &Q);
    limit = getSegTreeSize(N);
    tree = new segTreeNode[limit];
    buildTree(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &T, &A, &B);
        if(T == 0){
            update(1, A, B);
        }
        else{
            S = 0;
            sum(1, A, B, S);
            printf("%lld\n",S);
        }
        //showTree();
    }
    delete[] tree;
}
