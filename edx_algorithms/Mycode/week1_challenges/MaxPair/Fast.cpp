//找到最大的两个元素相乘
#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> numbers){
    int n=numbers.size();
    int x1=0;
    for(int i=1;i<n;i++){
        if(numbers[i]>numbers[x1]){
            x1=i;
        }
    }

    int x2;
    if(x1=0)
        x2=1;
    else{
        x2=0;
    }
    for(int i=0;i<n;i++){
        if(numbers[i]>numbers[x2] && numbers[i]!=numbers[x1]){
            x2=i;
        }
    }
    return numbers[x1]*numbers[x2];
}

int main(){
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    cout<<getMax(numbers)<<'\n';
    return 0;
}