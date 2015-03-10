#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "bsp.h"


//--------------------------------------------------------------
struct Node * make_node() {

  struct Node * n = (struct Node *)malloc(sizeof(struct Node));
  n->left = NULL;
  n->right = NULL;
  n->data = NULL;
}
//-------------------------------------------------------------
void free_node(struct Node * n) {

  free(n->data);
  free(n);
}
//-------------------------------------------------------------
struct BSP * create_tree() {

  struct BSP *tree = (struct BSP *)malloc(sizeof(struct BSP));
  tree->root = make_node();
  tree->size = 1;

  return tree;
}
//--------------------------------------------------------------
