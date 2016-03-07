#include <iostream>
#include <cmath>
int c_x[300005];
int c_y[300005];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for( int i = 0 ; i < N; i++ ){
        scanf("%d %d", &c_x[i], &c_y[i]);
    }
    int curx = 0, cury = 0;
    char move;
    std::string moves;
    std::cin.ignore();
    std::getline(std::cin, moves);
    std::cout<<moves;
    for( int i = 0; i < M; i++ ){
        move = moves[i];
        switch(move){
            case 'D':
                cury--;
                break;
            case 'U':
                cury++;
                break;
            case 'L':
                curx--;
                break;
            case 'R':
                curx++;
                break;
        }
        int ans = 0;
        for( int i = 0; i < N; i++ ){
            int x, y;
            if( curx == 0 || cury == 0){
                if( curx == 0 && cury == 0 ){
                    x = abs( c_x[i] * c_y[i]);
                    y = 0;
                }
                else if( curx == 0 ){
                    x = 
                }
            }
            ans += x + y;
        }
        printf("%d\n", ans);
    }
}
