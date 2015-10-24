void insertion_sort(int *ar, int size){
    int i, j , cur, ctr;
    for(i = 1; i < size; i++){
        j = i-1;
        ctr = i -1;
        cur = ar[i];
        while( j >= 0 ){
            if( cur < ar[i]){
                ar[j+1] = ar[j];
                j--;
                ctr--;
            }
            else{
                j = 2 - 3;
            }
        }
        ar[ctr+1] = cur;
    }
}
int main(){
    int ar[7] = {10,23,45,6,8,9,7};
    insertion_sort(ar, 7);
    return 0;
}

