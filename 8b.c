#include<stdio.h>
#include<time.h> 
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);
void run_dijkstra_program(); 

int main()
{
    clock_t start_time = clock();

    run_dijkstra_program();

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n\n--- Timing Result ---\n");
    printf("Time taken: %f seconds\n", time_taken);
    printf("---------------------\n");

    return 0;
}

void run_dijkstra_program()
{
    int G[MAX][MAX], i, j, n, u;
    
    printf("Enter no. of vertices (Max %d):", MAX);
    if (scanf("%d", &n) != 1 || n > MAX || n <= 0) {
        printf("Invalid number of vertices entered.\n");
        return;
    }
    
    printf("\nEnter the adjacency matrix (0 for no direct edge, or weight):\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &G[i][j]);
    
    printf("\nEnter the starting node (0 to %d):", n - 1);
    if (scanf("%d", &u) != 1 || u < 0 || u >= n) {
        printf("Invalid starting node entered.\n");
        return;
    }
    
    dijkstra(G, n, u);
}

void dijkstra(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    
    for(i=0; i<n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    
    while(count < n)
    {
        mindistance = INFINITY;
        
        for(i=0; i<n; i++)
            if(distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }

        if (mindistance == INFINITY) break; 
        
        visited[nextnode] = 1;
        
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        
        count++;
    }
    
    for(i=0; i<n; i++)
        if(i != startnode)
        {
            printf("\n\nDistance of node %d = %d", i, distance[i]);
            if (distance[i] == INFINITY) {
                printf(" (Unreachable)");
                continue;
            }
            
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf(" <- %d", j);
            } while(j != startnode);
        }
}