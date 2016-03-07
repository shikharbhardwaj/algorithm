#include <iostream>
#include <cctype>
int main(){
    int T;
    scanf("%d", &T);
    std::string str, sts;
    while( T-- ){
        std::cin>>str;
        for( auto &ch : str ){
            ch = toupper(ch);
        }
        std::cin>>sts;
        for( auto &ch : sts ){
            ch = toupper(ch);
        }
        if( sts == str ){
            printf("equal");
        }
        else if( sts > str ){
            printf("first");
        }
        else{
            printf("second");
        }
        printf("\n");
    }
}
