# include <stdio.h>
#define N 15
int n,x;
int arr[N];
int left,right,mid;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>=arr[j]){
                printf("Invalid Value");
                return 0;
            }
        }
    }

    left=0,right=n-1;
    mid=(left+right)/2;
    while(left<=right){
        printf("[%d,%d][%d]\n",left,right,mid);
        if(x>arr[mid]){
            left=mid+1;
            mid=(left+right)/2;
        }
        else if(x<arr[mid]){
            right=mid-1;
            mid=(left+right)/2;
        }
        else{
            printf("%d\n",mid);
            return 0;
        }
    }
    
    printf("Not Found");
    return 0;
}