#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjList[], int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void bfs(struct Node* adjList[], int vertices,
         int startNode, int visited[])
{

 int queue[MAX_VERTICES];
    int front = 0, rear = 0;

visited[startNode] = 1;
    queue[rear++] = startNode;

while (front != rear) {

 int currentNode = queue[front++];
        printf("%d ", currentNode);

struct Node* temp = adjList[currentNode];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main()
{
clock_t start, end;
int vertices = 5;
start=clock();
struct Node* adjList[vertices];
    for (int i = 0; i < vertices; ++i)
        adjList[i] = NULL;

  addEdge(adjList, 200, 100);
    addEdge(adjList, 200, 300);
    addEdge(adjList, 100, 400);
    addEdge(adjList, 100, 500);
    addEdge(adjList, 300, 500);

int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

 printf(
        "Breadth First Traversal starting from vertex 0: ");
    bfs(adjList, vertices, 0, visited);
end=clock();
printf("time taken to perform bfs : %f",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}