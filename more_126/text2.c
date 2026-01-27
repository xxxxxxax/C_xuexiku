#include <stdio.h>
void selection_sort(int* arr,int sz)
{
    int i=0;
    for(i=0;i<sz-1;i++)
    {
        int min_idx=i;//假设当前轮次的第一个元素是最小值，记录其下标
        int j=0;
        for(j=i+1;j<sz;j++)//从i+1开始，找到剩余未排序部分的最小值下标
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx!=i)//如果最小值下标不是当前轮次的起始下标，交换两个元素
        {
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}//每轮找到未排序部分的最小值，与未排序部分的第一个元素交换，共需n-1轮排序；
int main() {
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    int sz=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,sz);
    int n=0;
    for(n=0;n<sz;n++)
    {
        printf("%d ",arr[n]);
    }
    return 0;
}