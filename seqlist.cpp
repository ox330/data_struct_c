#include <stdlib.h>
#include <stdio.h>
#define InitSize 10
//线性表：顺序存储实现
typedef struct
{
    int *data;
    int length;
    int MaxSize;
}SeqList;

//初始化动态顺序表
void InitList(SeqList &L)
{
    //动态分配内存空间
    L.data=(int *)malloc(InitSize*sizeof(int));
    //长度置0
    L.length=0;
    //最大长度置为初始最大长度
    L.MaxSize=InitSize;
}

//增加动态表长度
void IncreaseSize(SeqList &L,int length)
{
    //将数据存到临时指针变量p

    int *p=L.data;
    //计算新长度，重新分配L内存空间
    L.data=(int *)malloc((L.MaxSize+length)*sizeof(int));
    //将数据写入L.data
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    //重新赋值最大长度
    L.MaxSize=L.MaxSize+length;
    //释放临时指针变量
    free(p);
}

//查找某元素的位序
int LocateElem(SeqList L,int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)
           return i+1;
    }
    return 0;

}

//查找固定位序的元素
int GetElem(SeqList L,int i){
    return L.data[i-1];

}


//在固定位序插入元素
bool InsertList(SeqList &L,int i,int e){
    if(i>=1&&(i<=(L.length+1))){
       for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
       L.data[i-1]=e;
       L.length++;
       return true;
    }
    return false; 
}

//删除动态顺序表指定元素
//删除第i个位置上的元素
bool DeleteList(SeqList &L,int i,int &e){
    if(i>=1&&(i<(L.length))){
    //把后面的数据依次往前挪
        e=L.data[i-1];
        for(int j=i;j<L.length;j++){
            L.data[j-1]=L.data[j];
        }
        L.length--;
        return true;
    }
    return false;
}


int main()
{
    //定义一个顺序表
    SeqList L;
    //初始化一个顺序表
    InitList(L);
    //向顺序表中插入数据
    for(int i=0;i<5;i++)
    {
        L.data[i]=i;
        L.length++;

    }
    //printf(L.data);

    printf("原顺序表数据: ");
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");

    //动态增加顺序表长度
    IncreaseSize(L,5);
    printf("顺序表长度增加为：%d\n",L.MaxSize);

    //查找位序为5的元素
    int elem=GetElem(L,5);
    printf("位序为5的元素值：%d\n",elem);

    //在位序为6的地方插入元素6
    if(InsertList(L,6,6))
       printf("插入成功\n");
    else
       printf("位序不合理，插入失败\n");

    //删除位序为1的元素
    int e=0;
    if(DeleteList(L,2,e))
        printf("删除成功,删除了元素%d\n",e);
    else
        printf("位序不合理，删除失败\n");

    printf("现在顺序表数据: ");
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
    return 0;
}