//Flipcoins : Codechef, Medium
//
//Using lazy propogated segment tree
#include <cmath>
#include <cstdio>
#include <iostream>
const int startSum = 0;
int limit;
struct segTreeNode{
    int min, max, sum;
    bool update;
    segTreeNode() : min(-1), max(-1), sum(0), update(false) {}
    void setState(int min, int max, int sum){
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
    void aggregate(segTreeNode &left, segTreeNode &right){
        this->sum = left.sum + right.sum;
    }
};
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
segTreeNode* tree; 
void buildTree(int index, int left, int right){
    if(left == right){      //Yay! leaf node :/
        tree[index].setState(left, right, startSum);
        return;
    }
    int mid = (left + right)/2;     //Split the interval into half
    buildTree(2*index, left, mid);      //Recursively build
    buildTree(2*index+1, mid+1, right);
    tree[index].setState(tree[2*index].min, tree[2*index+1].max, startSum);
    tree[index].aggregate(tree[2*index], tree[2*index+1]);  //And combine
}
inline void propogateConditional(int index){
    if( 2*index + 1< limit ){
        tree[2*index].update = !tree[2*index].update;
        tree[2*index+1].update = !tree[2*index+1].update;
    }
    else if( 2*index < limit ){
        tree[2*index].update = !tree[2*index].update;
    }
}
inline void addConditional(int index){
    if( 2*index + 1 < limit ){
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        }
        if(tree[2*index+1].update){
            tree[index].sum += tree[2*index+1].max - tree[2*index+1].min + 1 - tree[2*index+1].sum;
        }
        else{
            tree[index].sum += tree[2*index+1].sum;
        }
    }
    else if( 2*index < limit ){
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        }
    }
}
void sum(int index, int min, int max, int &ret){
    if(max < min){
        return;
    }
    if(min == tree[index].min && max == tree[index].max){
        if(tree[index].update){
            //Update the node
            tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
            tree[index].update = false;
            propogateConditional(index);
        }
        else{
            //Conditional add
       }
        ret += tree[index].sum;
        return;
    }
    //First check and apply the update
    if(tree[index].update){
        tree[index].update = false;
        tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
        //std::cout<<"\nPropogating from "<<index;
        propogateConditional(index);
    }
    if( 2*index + 1 < limit ){
        if(min > tree[2*index].max){
            //Left node is useless
            sum(2*index+1, min, max, ret);
        }
        else if(max < tree[2*index+1].min){
            sum(2*index, min, max, ret);
        }
        else{
            if(max == tree[2*index+1].max){
                sum(2*index+1, tree[2*index+1].min, max, ret);
                sum(2*index, min, tree[2*index+1].min - 1, ret);
            }
            else if(min == tree[2*index].min){
                sum(2*index, min, tree[2*index].max, ret);
                sum(2*index+1, tree[2*index].max+1, max, ret);
            }
            else{
                sum(2*index, min, tree[2*index].max, ret);
                sum(2*index+1, tree[2*index+1].min, max, ret);
            }
        }
        //Get the sumd value from the child
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        }
        if(tree[2*index+1].update){
            tree[index].sum += tree[2*index+1].max - tree[2*index+1].min + 1 - tree[2*index+1].sum;
        }
        else{
            tree[index].sum += tree[2*index+1].sum;
        } 
    }
    else if(2 * index < limit){
        if(min >= tree[2*index].min && max <= tree[2*index].max){
            sum(2*index, min, max, ret);
        }
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        }
    }
    //std::cout<<"\nUpdated "<<tree[index].min<<", "<<tree[index].max<<" with "<<tree[index].sum;
}
void update(int index, int min, int max){
    if(max < min){
        return;
    }
    //std::cout<<"\nCalled with "<<index<<", "<<min<<", "<<max;
    if(min == tree[index].min && max == tree[index].max){
        //std::cout<<"\nPerfect match with "<<min<<", "<<max;
        if(tree[index].update){
            //std::cout<<"\nNull!";
            //Update was pending!
            //But again updating nullifies it
            //so just add and return
            tree[index].update = false;
            addConditional(index);
        }
        else{
            //std::cout<<"\nUpdate";
            //Update the node
            tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
            propogateConditional(index);
        }
        return;
    }
    //Both the children are available
    //First check and apply the update
    if(tree[index].update){
        tree[index].update = false;
        tree[index].sum = tree[index].max - tree[index].min + 1 - tree[index].sum;
        //std::cout<<"\nPropogating from "<<index;
        propogateConditional(index);
    }
    if( 2*index + 1 < limit ){
        if(min > tree[2*index].max){
            //Left node is useless
            update(2*index+1, min, max);
        }
        else if(max < tree[2*index+1].min){
            update(2*index, min, max);
        }
        else{
            if(max == tree[2*index+1].max){
                update(2*index+1, tree[2*index+1].min, max);
                update(2*index, min, tree[2*index+1].min - 1);
            }
            else if(min == tree[2*index].min){
                update(2*index, min, tree[2*index].max);
                update(2*index+1, tree[2*index].max+1, max);
            }
            else{
                update(2*index, min, tree[2*index].max);
                update(2*index+1, tree[2*index+1].min, max);
            }
        }
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        }
        if(tree[2*index+1].update){
            tree[index].sum += tree[2*index+1].max - tree[2*index+1].min + 1 - tree[2*index+1].sum;
        }
        else{
            tree[index].sum += tree[2*index+1].sum;
        }
    }
    else if(2*index < limit){
        if(min >= tree[2*index].min && max <= tree[2*index].max){
            update(2*index, min, max);
        }
        if(tree[2*index].update){
            tree[index].sum = tree[2*index].max - tree[2*index].min + 1 - tree[2*index].sum;
        }
        else{
            tree[index].sum = tree[2*index].sum;
        } 
    }
}
void printSpace(int n){
    for(int i = 0; i < n; i++){
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
    int T, A, B, N, Q, S;
    scanf("%d %d", &N, &Q);
    limit = getSegTreeSize(N);
    tree = new segTreeNode[limit+1];
    buildTree(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &T, &A, &B);
        if(T == 0){
            update(1, A, B);
        }
        else{
            S = 0;
            sum(1, A, B, S);
            printf("%d\n", S);
        }
        //showTree();
    }
    delete[] tree;
    return 0;
}
