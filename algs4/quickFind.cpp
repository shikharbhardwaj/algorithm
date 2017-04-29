//An implementation of the quickFind algorithm
#include <vector>
#include <iostream>
class quickFind{
    private:
        std::vector<int> id;
    public:
        quickFind(){
            id.push_back(0);
        }
        quickFind(int n){
            for(int i = 0;i<n;i++){
                id.push_back(i);
            }
        }
        quickFind(const std::vector<int> &copy){
            id = copy;
        }
        quickFind(const quickFind &copy){
            id = copy.id;
        }
        void operator= (const quickFind &copy){
            id = copy.id;
        }
        void unite(unsigned int x,unsigned int y){	//Union x and y
            if(x >= id.size() || y >= id.size()){
                return;
            }
            int xid = id[x];
            int yid = id[y];
            for(auto &elem : id){
                if(elem == xid){
                    elem = yid;
                }
            }
        }
        bool connected(int x, int y){
            return id[x] == id[y];
        }
};
int main(){
    quickFind obj1(100);
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
//Complexity : Union -> O(n) Find -> O(1)
