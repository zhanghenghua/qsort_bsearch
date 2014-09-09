#include <stdio.h>
#include <stdlib.h>

//一次快速排序
int partition(int low,int high,int *num)
{
    int pivot=num[low];
    while(low<high)
    {
        while(low<high&&num[high]>=pivot)  --high;
        num[low]=num[high];
        while(low<high&&num[low]<pivot) ++low;
        num[high]=num[low];
    }
    num[low]=pivot;
    return low;
}
//快速排序
void quick_Sort(int low,int high,int *num)
{
    int pivot=0;
    if(low < high)
    {
        pivot = partition(low, high,num);
        quick_Sort(low, pivot-1,num);
        quick_Sort(pivot+1, high,num);
    }
}
//二分查找,num数组中查找x，数组长度为n
int bin_Search(int x, int num[], int n)
{
    int low, high, mid;
    low = 0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x>num[mid])  low=mid+1;
        else if(x<num[mid])  high=mid-1;
        else return mid;
    }
    return -1;
}

int main(void)
{
    printf("请输入要排序数组的大小：\n");
    int n,i=0,x;
    scanf("%d",&n);
    int * num = (int*)malloc(n * sizeof(int));//申请内存
    printf("请输入要排序数组元素:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    quick_Sort(0,n-1,num);//快速排序
    printf("经快速排序后，数组为:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",num[i]);
        printf("  ");
    }
    printf("\n请输入要查询的元素：\n");
    scanf("%d",&x);
    int pos=bin_Search(x,num,n);
    if(pos==-1) printf("数组中不存在该元素！\n");
    else printf("经排序后，该元素在数组中的位置为：%d\n",pos+1);

    free(num);//释放内存
    return 0;
}
