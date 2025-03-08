#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int key;
  struct Node *left, *right;
} Node;

Node *getNewNode(int val) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->key = val;
  n->left = n->right = nullptr;
  return n;
}

Node *insert(Node *root, int key) {
  if (root == NULL)
    return getNewNode(key);
  if (rand() % 2)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
  return root;
}

void clear(Node *root) {
  if (root == NULL)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
  return;
}

#define MAX_NODE 10
Node *queue[MAX_NODE + 5];
int head, tail;
void bfs(Node *root) {
  head = tail = 0;
  queue[tail++] = root;
  while (head < tail) {
    Node *node = queue[head];
    printf("\n node : %d \n", node->key);
    if (node->left) {
      queue[tail++] = node->left;
      printf("\t%d->%d(left)\n", node->key, node->left->key);
    }
    if (node->right) {
      queue[tail++] = node->right;
      printf("\t%d->%d(right)\n", node->key, node->right->key);
    }
    head++;
  }
}

int tot = 0;
void dfs(Node *root) {
  if (root == NULL)
    return;
  int start, end;
  tot += 1;
  start = tot;
  if (root->left)
    dfs(root->left);
  if (root->right)
    dfs(root->right);
  tot += 1;
  end = tot;
  printf("%d : [%d, %d]\n", root->key, start, end);
  return;
}

int main() {
  srand(time(0));
  Node *root = NULL;
  for (int i = 0; i < MAX_NODE; ++i) {
    root = insert(root, rand() % 100);
  }
  bfs(root);
  dfs(root);
  clear(root);
  return 0;
}
