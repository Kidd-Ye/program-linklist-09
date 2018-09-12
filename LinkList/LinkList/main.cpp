//
//  main.cpp
//  LinkList
//
//  Created by kidd on 2018/9/12.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#define element char

typedef struct Node{
    element data;
    struct Node *next;
}SNode, *LinkList;

LinkList CreateList(LinkList &L, char *str, int length, LinkList &same){
    Node *s;
    L = (LinkList)malloc(sizeof(Node)); //创建头结点
    L->next = NULL;
    for (int i = length-1; i >= 0; i--) {
        s = (Node*)malloc(sizeof(Node));
        s->data = str[i];
        s->next = L->next;
        L->next = s;
    }
    
    return L;
}

void Print(LinkList L){
    Node *s = L->next;
    while (s != NULL) {
        printf("%c ",s->data);
        s = s->next;
    }
    printf("\n");
}

SNode *find_addr(LinkList list1, int length1, LinkList list2, int length2){
    SNode *p, *q;
    for (p=list1; length1 > length2; length1--) {
        p=p->next;
    }
    for (q=list2; length2 > length1; length2--) {
        q=q->next;
    }
    while (p->next!=NULL&&p->next!=q->next) {
        p=p->next;
        q=q->next;
    }
    return p->next;
}

int main(int argc, const char * argv[]) {
    
    LinkList str1, str2;
    char strc1[] = "ilovefight";
    char strc2[] = "swimm";
    int len1 = sizeof(strc1)/sizeof(char);
    int len2 = sizeof(strc2)/sizeof(char);
//    CreateList(str1, strc1, len1);
//    CreateList(str2, strc2, len2);
    Print(str1);
    Print(str2);
 
    printf("%c\n", find_addr(str1,len1,str2,len2)->data);
    
    
    return 0;
}
