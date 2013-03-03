#include <stdio.h>
#include <stdlib.h>

typedef int key_t;
typedef int data_t;

typedef enum color_t
{
    RED = 0;
    BLACK = 1;
}color_t;

typedef struct rb_node_t
{
    struct rb_node_t *lchild, *rchild, *parent;
    key_t key;
    data_t data;
    color_t color;
}rb_node_t;

static rb_node_t *rb_new_node(key_t key, data_t data)
{
    rb_node_t *node = (rb_node_t*)malloc(sizeof(struct rb_node_t));
    if(!node)
    {
	printf("malloc error\n");
	exit(-1);
    }

    node->key = key;
    node->data = data;

    return node;
}

/*====================================================================
|       node                             right
|       /  \                             /   \
|      a  right       ==>              node   c
|         /   \                        /   \
|        b     c                      a     b 
=====================================================================*/
static rb_node_t *rb_rotate_left(rb_node_t *node, rb_node_t *root)
{
    rb_node_t *right = node->rchild;

//    node->rchild = right->lchild;
//    if (right->lchild)
      if ((node->rchild = right->lchild))
	  right->lchild->parent = node;

      if ((right->parent = node->parent))
      {
	  if (node == node->parent->rchild)
	      node->parent->rchild = right;
	  else
	      node->parent->lchild = right;
      }
      else
	  root = right;

      right->lchild = node;
      node->parent = right;

      return root;
}

/*====================================================================
|       node                             left
|       /  \                             /   \
|     left  a       ==>                 b    node
|    /   \                                  /   \
|   b     c                                c     a 
=====================================================================*/
static rb_node_t *rb_rotate_right(rb_node_t *node, rb_node_t *root)
{
    rb_node_t *left = node->lchild;

    if ((node->lchild = left->rchild))
	left->rchild->parent = node;

    if((left->parent = node->parent))
    {
	if (node == node->parent->rchild)
	    node->parent->rchild = left;
	else
	    node->parent->lchild = left;
    }
    else
	root = left;

    left->rchild = node;
    node->parent = left;

    return root;
}

static rb_node_t *rb_search_auxiliary(key_t key, rb_node_t *node, rb_node_t *root, rb_node_t **save)
{
    rb_node_t *node = root, *parent = NULL;

    while (node)
    {
	parent = node;

	if (node->key > key)
	    node = node->lchild;
	else if (node->key < key)
	    node = node->rchild;
	else 
	    return node;
    }

    if (save)
	*save = parent;

    return NULL;
}

rb_node_t *rb_search(key_t key, rb_node_t *root)
{
    return rb_search_auxilary(key, root, NULL);
}

static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root)
{
    rb_node_t *parent, *gparent, *uncle, *tmp;
    while ((parent = node->parent) && parent->color == RED)
    {
	gparent = parent->parent;
	if (parent == gparent->lchild)
	{
	    uncle = gparent->rchild;
	    if (uncle && uncle->color == RED)
	    {
		parent->color = BLACK;
		uncle->color = BLACK;
		gparent->color = RED;
		node = gparent;
	    }
	    else
	    {
		if (parent->rchild == node)
		{
		    root = rb_rotate_left(parent, root);
		    tmp = parent;
		    parent = node;
		    node = tmp;
		}

		parent->color = BLACK;
		gparent->color = RED;
		root = rb_rotate_right(gparent, root);
	    }
	}

	else
	{
	    uncle = gparent->lchild;
	    if (uncle && uncle->color == RED)
	    {
		parent->color = BLACK;
		uncle->color = BLACK;
		gparent->color = RED;
		node = gparent;
	    }
	    else
	    {
		if (parent->lchild == node)
		{
		    root = rb_rotate_right(parent, root);
		    tmp = parent;
		    parent = node;
		    node = tmp;
		}

		parent->color = BLACK;
		gparent->color = RED;
		root = rb_rotate_left(gparent, root);
	    }
	}
    }

    root->color = BLACK;
    return root;
}

rb_node_t *rb_insert(key_t key, data_t data, rb_node_t *root)
{
    rb_node_t *parent = NULL, *node;

    if ((node = rb_search_auxiliary(key, root, &parent)))
	return root;
    node = rb_new_node(key, data);
    node->parent = parent;
    node->lchild = node->rchild = NULL;
    node->color = RED;

    if (parent)
    {
	if (parent->key > key)
	    parent->lchild = node;
	else 
	    parent->rchild = node;
    }
    else 
	root = node;

    return rb_insert_rebalance(node, root);
}

rb_node_t *rb_delete(ket_t key, rb_node_t *root)
{
    rb_node_t *child, *parent, *old, *left, *node;
    color_t color;

    if (!(node = rb_search_auxiliary(key, root, NULL)))
    {
	printf("key %d is not exist! \n", key);
	return root;
    }

    old = node;

    if (node->lchild && node->rchild)
    {
	
    }
}
