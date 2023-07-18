#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;

}LNode,*LinkList;

bool InsertNextNode(LNode *p,int e);

// 单链表的初始化
// 1.带头结点的初始化
bool InitLinkList(LinkList &L){
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
       return false;
    L->next=NULL;
    return true;
}

// 2.不带头结点的初始化
bool InitNHeadLinkList(LinkList &L){
    L=NULL;
    return true;
}

// 单链表：查找
// 1.按位查找
LNode * GetElem(LinkList L,int i){
    if(i<1)
      return NULL;
    LNode *p;
    p=L;
    int j=0;
    while(p!=NULL && j<i){
        p=p->next; 
        j++;
    }
    return p;
}

// 2.按值查找
LNode * LocateElem(LinkList &L,int e){
  // 依次循环，对比值
  LNode *p=L->next;
  while(p!=NULL && p->data!=e)
    p=p->next;
  return p;
}

// 单链表长度
int Length(LinkList L){
  LNode *p=L;
  int count=0;
  while(p->next!=NULL){
    p=p->next;
    count++;
  }
  return count;
}

// 单链表的插入
// 1.按位序插入
// 1.1带头结点插入
bool ListInsert(LinkList &L,int i,int e){
    if(i<1)
       return false;
    LNode *p=GetElem(L,i-1);
    return InsertNextNode(p,e);
}

// 不带头结点插入
bool NHeadListInsert(LinkList &L,int i,int e){
    if(i<1)
      return false;
    if(i==1){
        LNode *s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=L->next;
        L=s;
        return true;
    }
    LNode *p=GetElem(L,i-1);//当前结点位置
    return InsertNextNode(p,e);
}
// 2.指定结点的后插操作
bool InsertNextNode(LNode *p,int e){
    if(p==NULL)
       return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if(s==NULL)
      return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

// 3.指定结点的前插操作
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL)
      return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if(s==NULL)
      return false;
    s->data=p->data;
    s->next=p->next;
    p->next=s;
    p->data=e;
    return true;
}
// 单链表的删除
// 1.按位序删除
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1)
      return false;
    LNode *p=GetElem(L,i-1);;
    if(p==NULL)  //i不合法
      return false;
    if(p->next==NULL) //若i的前驱结点的后继为空，i-1以后已无结点
      return false;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

// 2.删除指定结点（注意删除最后一个结点需从头到尾找到其前驱）
bool DeleteNode(LNode *p){
    if(p==NULL)
      return false;
    if(p->next!=NULL){
        LNode *q=p->next;
        p->data=p->next->data;
        p->next=q->next;
        free(q);
        return true;
    }
    else
      return false;
    // 未处理删除最后一个结点，删除最后一个结点需要L，循环L找到删除结点p的前驱结点，将它的后继指针置为空
}

// 单链表的建立
// 1.尾插法建立
LinkList List_TailInsert(LinkList &L){
  // typedef struct user{
  //   char name;
  //   int age;
  // }user;
  // user u;
  // scanf("%s %d",u.name,&u.age);
  int x;
  InitLinkList(L);
  LNode *s,*r=L;
  scanf("%d",&x);
  while(x!=9999){
    InsertNextNode(r,x);
    r=s;
    scanf("%d",&x);
  }
  r->next=NULL;
  return L;
}


int main(){
    LNode *L;
    InitLinkList(L);
    for(int i=1;i<5;i++)
      ListInsert(L,i,i);
    LNode *s=GetElem(L,4);
    int e=0;
    LNode *p=L;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    printf("获取第4位元素值：%d\n",s->data);
    printf("在位序为4的结点后插入5，插入结果：%d\n",InsertNextNode(s,5));
    LNode *k=L;
    while(k!=NULL){
        printf("%d ",k->data);
        k=k->next;
    }
    printf("\n");
    printf("在位序为4的结点前插入5，插入结果：%d\n",InsertPriorNode(s,5));
    LNode *w=L;
    while(w!=NULL){
        printf("%d ",w->data);
        w=w->next;
    }
    printf("\n");
    int x=0;
    printf("删除位序为5的结点，删除结果：%d，",ListDelete(L,5,x));
    printf("刪除的值：%d\n",x);
    LNode *r=L;
    while(r!=NULL){
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");

    printf("删除指定结点，删除结果：%d，\n",DeleteNode(s));
    LNode *u=L;
    while(u!=NULL){
        printf("%d ",u->data);
        u=u->next;
    }
    
    return 0;
}