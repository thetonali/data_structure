#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* 1.自定义比较函数
* 2.使用贪心策略直接构造结果
    逐步构造结果——每次从剩余的数字中选出能使当前结果变大的数字
    使用类似的拼接比较策略，比较每个数字与当前结果组合后的大小，
    选择可以最大化结果的那个数字
    - *初始化一个空的结果字符串
    - *从输入的数字中，每次选出能让结果变大的数字，拼接到结果后面
    - *重复步骤2直到所有的数字都被选中
* 3.动态规划（不太实用，但可行）
* 4.回溯法（复杂度较高）
* 5.模拟人工排列的规则
    每次都找到剩下数字中“最高位最大”的那个数放在前面。
    这种方法的核心和自定义排序法类似，只不过模拟的是我们手工排列时的决策过程。
*/

/* qsort 函数
* 在qsort函数中，比较函数的参数是两个const void* 类型（表示指向任意类型的常量对象的指针）的指针，即a和b。
  这意味着a和b指向的是排序数组中的某个元素的地址。
  实际传递给qsort的数组是一个字符串数组（char*类型的数组),
  所以每个元素实际上是指向字符串的指针(char*)，而a和b是指向这些指针的地址
* ！！a是一个指向char*的指针的指针，类型为const char**
* 为了访问a指向的内容，需要将a从const void*类型转换为合适的类型。
  由于直到a实际上是一个指向字符串指针的指针，所以将它强制转换为const char**类型
  - const char**的意思是：a是指向一个const char*（指向常量字符串的指针）的指针
* *(const char**)a——在解引用这个指针，获取a指向的内容。
  因为a是一个指向char*的指针，所以*(const char**)a的结果是一个const char*，
  即指向实际字符串的指针。
* 总结——
  const void *a 是一个指针，指向一个元素的地址，元素本身是 char * 类型的指针。
  (const char **)a 将 a 转换为指向 const char * 的指针。
  *(const char **)a 对这个指针进行解引用，得到 const char *，也就是实际的字符串指针。
*/


//自定义比较函数
int compare(const void*a,const void*b){
    //将两个字符串连接，比较哪个组合更大
    char ab[2000],ba[2000];
    strcpy(ab,*(const char**)a);
    strcat(ab,*(const char**)b);

    strcpy(ba,*(const char**)b);
    strcat(ba,*(const char**)a);
    return strcmp(ba,ab);//返回较大的组合顺序
    // 注意：返回 ba - ab，因为我们希望较大的字符串排列在前面
}

int main(){
    int n;
    scanf("%d",&n);//输入整数个数

    char*num[n];
    for(int i=0;i<n;i++){
        num[i]=(char*)malloc(1001*sizeof(char));//为每个数字分配存储空间
        scanf("%s",num[i]);//输入每个整数作为字符串
    }
    //使用自定义比较函数排序
    qsort(num,n,sizeof(char*),compare);
    //在 qsort 中，如果返回负数，a 会被排在 b 之前；如果返回正数，b 会被排在 a 之前

    //如果最大数是0，直接输出0
    if(strcmp(num[0],"0")==0){
        printf("0\n");
    }else{
        //输出排序后的结果，组合成最大的数
        for(int i=0;i<n;i++){
            printf("%s",num[i]);
        }
        printf("\n");
    }
    //释放分配的内存
    for(int i=0;i<n;i++){
        free(num[i]);
    }
    return 0;
}