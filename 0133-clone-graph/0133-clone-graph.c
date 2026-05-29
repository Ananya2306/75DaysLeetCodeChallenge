/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#define MAX_NODES 101

struct Node* visited[MAX_NODES];

struct Node* dfs(struct Node* node) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(
        sizeof(struct Node*) * node->numNeighbors
    );

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL)
        return NULL;

    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = NULL;
    }

    return dfs(s);
}