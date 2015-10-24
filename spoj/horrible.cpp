#include <cstdio>
#include <iostream>
#include <cmath>
const int startSum = 0;
int getSegTreeSize(int n){
    float logVal = log2(n);
    if(logVal == (int)logVal){
        return 2*n;
    }
    else{
        return pow(2, (int)logVal + 2);
    }
}
struct segTreeNode{
    long long sum, min, max, updateVal;
    bool update;
    segTreeNode() : sum(0), min(-1), max(-1), updateVal(0), update(false) {}
    void setState(long long  min, long long max, long long sum, long long update){
        this->min = min;
        this->max = max;
        this->sum = sum;
        this->update = update;
    }
    void setUpdate(long long val, bool update){
        this->updateVal = val;
        this->update = update;
    }
};
class segTree{
    private:
        segTreeNode *tree;
        segTree();
        void buildTree(int index, int min, int max){
            tree[index].setState(min, max, startSum, false);
            if(min == max){
                return;
            }
            buildTree(2*index, min, (min+max)/2);
            buildTree(2*index+1, (min+max)/2 + 1, max);
            tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
        }
        void queryInterval(int index, int min, int max, long long &ret){
            if(tree[index].update){
                tree[index].sum += tree[index].updateVal*(tree[index].max - tree[index].min + 1);
                if(tree[index].min != tree[index].max){
                    tree[2*index].updateVal += tree[index].updateVal;
                    tree[2*index].update = true;
                    tree[2*index+1].updateVal += tree[index].updateVal;
                    tree[2*index+1].update = true;
                }
                tree[index].update = false;
                tree[index].updateVal = 0;
            }
            if(min > tree[index].max || max < tree[index].min){
                return;
            }
            if(tree[index].min >= min && tree[index].max <= max){
                ret += tree[index].sum;
                return;
            }
            queryInterval(2*index, min, max, ret);
            queryInterval(2*index+1, min, max, ret);
        }
        void updateInterval(int index, int min, int max, int val){
            if(tree[index].update){
                tree[index].sum += tree[index].updateVal*(tree[index].max - tree[index].min + 1);
                if(tree[index].min != tree[index].max){
                    tree[2*index].updateVal += tree[index].updateVal;
                    tree[2*index].update = true;
                    tree[2*index+1].updateVal += tree[index].updateVal;
                    tree[2*index+1].update = true;
                }
                tree[index].update = false;
                tree[index].updateVal = 0;
            }
            if(min > tree[index].max || max < tree[index].min){
                return;
            }
            if(tree[index].min >= min && tree[index].max <= max){
                tree[index].sum += val*(tree[index].max - tree[index].min + 1);
                if(tree[index].max != tree[index].min){
                    tree[2*index].update = true;
                    tree[2*index].updateVal += val;
                    tree[2*index+1].update = true;
                    tree[2*index+1].updateVal += val;
                }
                return;
            }
            updateInterval(2*index, min, max, val);
            updateInterval(2*index+1, min, max, val);
            tree[index].sum = tree[2*index].sum + tree[2*index+1].sum;
        }
    public:
        segTree(int n){
            int sz = getSegTreeSize(n);
            tree = new segTreeNode[sz];
            buildTree(1, 1, n);         //This is for 1 indiced rep
        }
        ~segTree(){
            delete[] tree;
        }
        void update(int val, int min, int max){
            updateInterval(1, min, max, val);
        }
        long long query(int min, int max){
            long long S = 0;
            queryInterval(1, min, max, S);
            return S;
        }
        void showTree(){
            for(int i = 0; i <16; i++){
                printf("[%lld,%lld]:%lld,%d, %lld\n", tree[i].min, tree[i].max, tree[i].sum, tree[i].update, tree[i].updateVal);
            }
        }
};
int main(){
    int T;
    int P, A, B, v;
    int N, C;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &C);
        segTree instance(N);
        while(C--){
            scanf("%d", &P);
            if(P==0){
                scanf("%d%d%d", &A, &B, &v);
                instance.update(v, A, B);
            }
            else{
                scanf("%d%d", &A, &B);
                printf("%lld\n", instance.query(A, B));
            }
            //instance.showTree();
        }
    }
}
