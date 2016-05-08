//To make a quickUnion application(lazy approach) with wieghted trees 
//and path compression
#include <vector>
#include <iostream>
class quickUnion{
    std::vector<unsigned int> ids;
    std::vector<unsigned int> wieght;
    public:
    quickUnion() = default;
    quickUnion(int n){
        for(int i = 0;i<n;i++){
            ids.push_back(i);
            wieght.push_back(1);
        }
    }
    quickUnion(const quickUnion &copy){
        ids = copy.ids;
        wieght = copy.wieght;
    }
    quickUnion(const std::vector<unsigned int> &idc){
        ids = idc;
        for(unsigned int i = 0;i < idc.size();i++){
            wieght.push_back(1);
        }
    }
    unsigned int findRoot(unsigned int i){
        unsigned int root = i;
        unsigned int x = i;
        while(ids[root] != root){//Traversing the trie
            root = ids[root];
        }
        while(ids[x] != root){   //Path compression
            i = ids[x];
            ids[x] = root;
            x = i;
        }
        return root;
    }
    void unite(unsigned const int &x, unsigned const int &y){
        unsigned int xr = findRoot(x);
        unsigned int yr = findRoot(y);
        if(xr == yr){
            return;
        }
        if(wieght[xr] > wieght[yr]){
            ids[yr] = xr;
            wieght[xr] += wieght[yr];
        }
    }
    bool connected(const unsigned int &x,const unsigned int &y){
        return findRoot(x) == findRoot(y);
    }
};
int main(){
    quickUnion obj1(100);
    char in;
    int x,y;
    while(true){
        std::cout<<"\n1. Unite 2. Connected";
        std::cin>>in;
        switch(in){
            case '1':
                std::cout<<"\nEnter the indices : ";
                std::cin>>x>>y;
                obj1.unite(x,y);
                break;
            case '2':
                std::cout<<"\nEnter the indices : ";
                std::cin>>x>>y;
                std::cout<<"\n"<<obj1.connected(x,y);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
