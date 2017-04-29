#include <cmath>
#include <cstdio>
#include <cstdlib>
const int startVal = 0; //The initial value at each node
struct segTreeNode{
    int min, max, sum; //The node manages [min, max]
    bool pendingUpdate; //For lazy propogation
    segTreeNode() : min(0), max(0), sum(0), pendingUpdate(false) {}
    segTreeNode(int min, int max, int sum, bool pendingUpdate){
        this->min = min;
        this->max = max;
        this->sum = sum;
        this->pendingUpdate = pendingUpdate;
    }
    void assignVal(int min, int max){
        this->min = min;
        this->max = max;
    }
    void merge(segTreeNode &left, segTreeNode &right){      //Merge the stats from the bottom levels
        sum = (left.hasPendingUpdate() ? (abs(left.max - left.min + 1 - left.sum)): left.sum);
        sum +=(right.hasPendingUpdate() ? (abs(right.max - right.min + 1 - right.sum)): right.sum);
    }
    int getVal(){           //Return the value for [min, max]
        return sum;         //Callers responsiblity to make sure the node has been merged!
    }
    bool hasPendingUpdate(){
        return pendingUpdate;
    }
    void applyPendingUpdate(){
        sum = abs(min - min + 1 - sum);
        pendingUpdate = false;
    }
    void addUpdate(){
        pendingUpdate = true;
    }
};
class segTree{
    private:
        segTreeNode *tree;
        int num;
        int getSegTreeSize(int n){
            int size = 1;
            for (; size < n; size <<= 1);
            return size << 1;

        }
        void buildTree(int index, int start, int end){
            tree[index].min = start;
            tree[index].max = end;
            if(start == end){
                tree[index].assignVal(startVal, startVal);
            }
            else{
                int mid = start+end; mid /= 2;
                int leftIndex = 2 * index;
                int rightIndex = leftIndex + 1;
                buildTree(leftIndex, start, mid);                     //Divide
                buildTree(rightIndex, mid+1, end);
                tree[index].merge(tree[leftIndex], tree[rightIndex]); //And conquer
            }
        }
        segTree() = default; //No instance having a default construction
        void switchInt(int index, int start, int end){
            if(index >= num){
                return;
            }
            if(tree[index].min == start && tree[index].max == end){
                //Yay!
                tree[index].addUpdate();
                return;
            }
            int mid = (start+end)/2;
            if(start > mid){
                switchInt(2*index + 1, start, end);
            }
            else if(mid <= end){
                switchInt(2*index, start, end);
            }
            switchInt(2*index, start, mid);
            switchInt(2*index +1, mid+1, end);
            tree[index].merge(tree[2*index], tree[2*index+1]);
        }
        segTreeNode query(int index, int start, int end){
            if(index >= num){
                return segTreeNode();
            }
            if(tree[index].min == start && tree[index].max == end){
                if(tree[index].hasPendingUpdate()){
                    tree[index].applyPendingUpdate();
                }
                return (tree[index]);
            }
            int mid = (start + end)/2;
            segTreeNode result;
            if(start > mid){        //The right child only
                result = query(2*index + 1, start, end);
            }
            else if(mid >= end){    //The left child only
                result = query(2*index, start, end);
            }
            else{
                segTreeNode leftRes = query(2*index, start, mid);
                segTreeNode rightRes = query(2*index + 1, mid+1, end);
                result.merge(leftRes, rightRes);
            }
            if(tree[index].hasPendingUpdate()){
                result.applyPendingUpdate();
            }
            return result;
        }
    public:
        segTree(int n){
            num = getSegTreeSize(n);
            tree = new segTreeNode[num];
            buildTree(1, 0, n-1);
        }
        ~segTree(){
            delete[] tree;
        }
        int queryInterval(int start, int end){
            segTreeNode result = query(1, start, end);
            return result.getVal();
        }
        void switchInterval(int start, int end){
            switchInt(1, start, end);
        }
};
int main(){
    int N, Q;
    int A, B, T;
    scanf("%d %d", &N, &Q);
    segTree solveThis(N);
    for(int i = 0; i < Q; i++){
        scanf("%d%d%d", &T, &A, &B);
        if( T == 0 ){
            solveThis.switchInterval(A, B);
        }
        else{
            printf("%d\n", solveThis.queryInterval(A, B));
        }
    }
}
