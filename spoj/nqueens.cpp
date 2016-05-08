#include <cstdio>
#include <string>
void rotate(){
    //Rotate the answerboard counterclockwise
    //and check if the answer is same
}
int main(){
    int n;
    char answerBoard[][15] = { 
        {'-','\t','Q','\t','-','\t','-','\t','-','\t','-','\t','-','\t','-'}, 
        {'-','\t','-','\t','-','\t','Q','\t', '-','\t','-','\t','-','\t','-'},
        {'Q','\t','-','\t','-','\t','-','\t', '-','\t','-','\t','-','\t','-'},
        {'-','\t','-','\t','Q','\t','-','\t', '-','\t','-','\t','-','\t','-'},
        {'-','\t','-','\t','-','\t','-','\t', 'Q','\t','-','\t','-','\t','-'},
        {'-','\t','-','\t','-','\t','-','\t', '-','\t','-','\t','-','\t','-'},
        {'-','\t','-','\t','-','\t','-','\t', '-','\t','Q','\t','-','\t','-'},
        {'-','\t','-','\t','-','\t','-','\t', '-','\t','-','\t','-','\t','Q'}
    };
    scanf("%d", &n);
    if(n == 1){
        printf("%c\n", answerBoard[0][2]);
    }
    else if( (n >= 2 && n <= 3) || n == 6){
        printf("Not Possible\n");
    }
    else{
        //Now print all 4 orientations of the board
        //avoiding any duplicates
    }
}
