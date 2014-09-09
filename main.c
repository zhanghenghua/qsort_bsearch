#include <stdio.h>
#include <stdlib.h>

//һ�ο�������
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
//��������
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
//���ֲ���,num�����в���x�����鳤��Ϊn
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
    printf("������Ҫ��������Ĵ�С��\n");
    int n,i=0,x;
    scanf("%d",&n);
    int * num = (int*)malloc(n * sizeof(int));//�����ڴ�
    printf("������Ҫ��������Ԫ��:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    quick_Sort(0,n-1,num);//��������
    printf("���������������Ϊ:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",num[i]);
        printf("  ");
    }
    printf("\n������Ҫ��ѯ��Ԫ�أ�\n");
    scanf("%d",&x);
    int pos=bin_Search(x,num,n);
    if(pos==-1) printf("�����в����ڸ�Ԫ�أ�\n");
    else printf("������󣬸�Ԫ���������е�λ��Ϊ��%d\n",pos+1);

    free(num);//�ͷ��ڴ�
    return 0;
}
