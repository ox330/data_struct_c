// 双链表的初始化，插入，删除，遍历
#include <stdio.h>
#include <stdlib.h>

// 1.定义双链表
typedef struct DNode{
    int data;
    sturct DNode *prior,*next;
}DNode,*DLinkList;

// 2.初始化
bool InitDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));
    if(L!=NULL){
        L->prior=NULL;
        L->next=NULL;
        return true;
    }
    return false;
}

// 3.判空
bool Empty(DLinkList &L){
    if(L->next==NULL)
      return true;
    else
      return false;
}

// 4.插入
// 后插，在p后面插入s
bool InsertDLinkList(DNode *p,DNode *s){
    if(p==NULL || s==null)
      return false;
    // s->next=p->next;
    // if(p->next!=NULL)
    //   p->next->prior=s;
    // s->prior=p;
    // p->next=s;
    // return true;
    if(p->next==NULL){
      s->prior=p;
      p->next=s;
      s->next=NULL;
      return true；
    }
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}

// 若在最后一个元素后插入s，单独处理
// bool InsertLastDLinkList(DNode &L){
// }

// 5.双链表的删除
bool DeleteNextDNode(DNode *p){
  if(p==NULL || P->next==NULL)
    return false;
  DNode *q=p->next;
  p->next=q->next;
  if(q->next==NULL)
    return false;
  q->next->prior=p;
  free(q);
  return true;
}

// 6.销毁双链表
void DestroyDLinkList(DLinkList &L){
  DNode *p=L;
  while(L->next!=NULL)
    DeleteNextDNode(p);
  free(L);
  L=NULL;
}

// 7.遍历



// 测试
int main(){

  return 0;
}