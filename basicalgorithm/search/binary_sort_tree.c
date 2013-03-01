#include<stdlib.h>
#include<stdio.h>
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int search_bst(BiTree T, int value, BiTree father, BiTree *p){
    if (!T){
	*p = father;
	return 0;
    }
    else if (value == T->data){
	*p = T;
	return 1;
    }
    else if (value < T->data)
	return search_bst(T->lchild, value, T, p);
    else 
	return search_bst(T->rchild, value, T, p);
}

int insert_bst(BiTree *T, int value){
    BiTree p,s;
    if (!search_bst(*T, value, NULL, &p)){
	s = (BiTree)malloc(sizeof(BiTNode));
	s->data = value;
	s->lchild = s->rchild = NULL;
	if (!p)
	    *T = s;
	else if (value < p->data)
	    p->lchild = s;
	else 
	    p->rchild = s;
	return 1;
    }
    else 
	return 0;
}

void pre_order_traverse(BiTree T){
    if (T == NULL)
	return;
    printf("%d ",T->data);
    pre_order_traverse(T->lchild);
    pre_order_traverse(T->rchild);
}

void in_order_traverse(BiTree T){
    if (T == NULL)
	return;
    in_order_traverse(T->lchild);
    printf("%d ",T->data);
    in_order_traverse(T->rchild);
}

void post_order_traverse(BiTree T){
    if (T == NULL)
	return;
    post_order_traverse(T->lchild);
    post_order_traverse(T->rchild);
    printf("%d ",T->data);
}

int delete(BiTree *p_delete){
    BiTree q, s;
    if ((*p_delete)->rchild == NULL){
	q = *p_delete;
	*p_delete = (*p_delete)->lchild;
	free(q);
    }
    else if ((*p_delete)->lchild == NULL){
	q = *p_delete;
	*p_delete = (*p_delete)->rchild;
	free(q);
    }
    else {
	q = *p_delete;
	s = (*p_delete)->rchild;
	while (s->lchild){
	    q = s;
	    s = s->lchild;
	}
	(*p_delete)->data = s->data;
	if ((*p_delete) != q)
	    q->lchild = s->rchild;
	else
	    q->rchild = s->rchild;
	free(s);
    }
    return 1;
}

int delete_bst(BiTree *T, int value){
    if (!(*T))
	return 0;
    else {
	if ((*T)->data == value)
	    return delete(T);
	else if ((*T)->data < value)
	    return delete_bst(&((*T)->lchild), value);
	else 
	    return delete_bst(&((*T)->rchild), value);
    }
}

int main(){
    int i;
    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    BiTree T = NULL;
    for (i = 0; i < 10; i++)
	insert_bst(&T, a[i]);
    in_order_traverse(T);
    putchar('\n');
    delete_bst(&T, 62);
    in_order_traverse(T);
    putchar('\n');
    return 0;
}
