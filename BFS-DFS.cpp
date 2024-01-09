#include <iostream>
using namespace std;

class queue_structure
{
public:
    int size;
    int first;
    int rear;
    int *Q;
};

class queue
{
    queue_structure *q = new queue_structure;

public:
    void create();
    void enqueue(int x);
    int dequeue();
    int isEmpty();
};

void queue ::create()
{
    cout << "enter size of queue: ";
    cin >> q->size;
    q->first = q->rear = -1;
    q->Q = new int[q->size];
}

void queue ::enqueue(int x)
{
    if (q->rear != q->size - 1)
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int queue ::dequeue()
{
    int x = -1;
    if (q->first != q->rear)
    {
        q->first++;
        x = q->Q[q->first];
    }
    return x;
}

int queue ::isEmpty()
{
    if (q->rear == q->first)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BFS(int G[][7], int start, int n)
{
    int i = start;
    queue Q;
    Q.create();
    int visited[7] = {0};

    cout << i << endl;
    visited[i] = 1;
    Q.enqueue(i);

    while (!Q.isEmpty())
    {
        i = Q.dequeue();
        for (int j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << endl;
                visited[j] = 1;
                Q.enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    if (visited[start] == 0)
    {
        cout << start;
        visited[start] = 1;
        for (int j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    DFS(G, 4, 7);

    return 0;
}