#include <stdlib.h>
#include <stdio.h>

#define LH +1  // left high
#define EH 0   // equal high
#define RH -1  // right high

typedef struct BiTNode{
    int data;
    int bf;    //balance factor
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void right_rotate(BiTree *p){
    BiTree L;
    L = (*p)->lchild;
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    (*p) = L;
}

void left_rotate(BiTree *p){
    BiTree R;
    R = (*p)->rchild;
    (*p)->rchild = R->lchild;
    R->lchild = (*p);
    (*p) = R;
}

void left_balance(BiTree *T){   // bf of T is larger than 1
    BiTree L, Lr;
    L = (*T)->lchild;
    switch (L->bf){
	case LH:
	    (*T)->bf = L->bf = EH;
	    right_rotate(T);
	    break;
	case RH:
	    Lr = (*T)->lchild;
	    switch (Lr->bf){
	        case LH:
		    (*T)->bf = RH;
		    L->bf = EH;
		    break;
		case EH:
		    L->bf = (*T)->bf = EH;
		    break;
		case RH:
		    (*T)->bf = EH;
		    L->bf = LH;
		    break;
		}
	    Lr->bf = EH;
	    left_rotate(&(*T)->lchild);
	    right_rotate(T);
    }
}

void right_balance(BiTree *T){ // bf of T is less than -1
    BiTree R, Rl;
    R = (*T)->rchild;
    switch (R->bf){
	case RH:
	    (*T)->bf = R->bf = EH;
	    break;
	case LH:
	    Rl = R->lchild;
	    switch (Rl->bf){
		case LH:
		    (*T)->bf = EH;
		    R->bf = RH;
		    break;
		case EH:
		    R->bf = (*T)->bf = EH;
		    break;
		case RH:
		    (*T)->bf = LH;
		    R->bf = EH;
		    break;
	    }
	    Rl->bf = EH;
	    right_rotate(&(*T)->rchild);
	    left_rotate(T);
    }
}

int insert_avl(BiTree *T, int value, int *taller){
    if (!*T){
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = value;
	(*T)->lchild = (*T)->rchild = NULL;
	(*T)->bf = EH;
	*taller = 1;
    }
    else {
	if (value == (*T)->data){
	    *taller = 0;
	    return 0;
	}
	if (value < (*T)->data){
	    if (!insert_avl(&(*T)->lchild, value, taller))
		return 0;
	    if (*taller){
		switch ((*T)->bf){
		    case LH:
			left_balance(T);
			*taller = 0;
		    case EH:
			(*T)->bf = LH;
			*taller = 1;
			break;
		    case RH:
			(*T)->bf = EH;
			*taller = 0;
			break;
		}
	    }
	}
	if (value > (*T)->data){
	    if (!insert_avl(&(*T)->rchild, value, taller))
		return 0;
	    if (*taller){
		switch (*taller){
		    case LH:
			(*T)->bf = EH;
			*taller = 0;
			break;
		    case EH:
			(*T)->bf = RH;
			*taller = 1;
			break;
		    case RH:
			right_balance(T);
			*taller = 0;
			break;
		}
	    }
	}
    }
    return 1;
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

int main(){
    int i;
    int a[10] = {3,2,1,4,5,6,7,10,9,8};
    BiTree T = NULL;
    int taller;
    for (i = 0; i < 10; i++)
	insert_avl(&T, a[i], &taller);
    in_order_traverse(T);
    return 0;
}
