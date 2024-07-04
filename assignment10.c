//  TEAM PROJECT
//  COURSE: PROGRAMMING AND DATA STRUCTURES LABORATORY(CS112)
//  TITLE: METRO ROUTE FINDER

//  IMPLEMENTED USING: BASIC LOOPS, CONTROL STATEMENTS, , ARRAY, STRING, GRAPH, DIJKSTRA'S THEOREM, TERMINAL FORMATTING,

/* TEAM: DEVANSH SRIVASTAVA
         HARSHIT TOMAR
         HARSH DAHIYA
         MEGHA SAHU
         MOHIT KUMAR
         LAXMI
         GAURAV KUMAR
         HARSHITA
         */

// The program uses Dijkstra's algorithm to find the shortest path between two metro stations in a given graph.
// The program uses terminal formatting to display the output in an organized and visually appealing manner.
// The program defines some utility functions such as minDistance, printPath, and printShortestPath to assist in the implementation of Dijkstra's algorithm.

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 21
// defining the number of vertices in the graph.


// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree.
int minDistance(int dist[], bool sptSet[])
{   
    // initalize the minimum value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


// A utility function to print the constructed distance array representing the shartest path
void printPath(int parent[], int j, char loc[][50])
{
    // Base Case: If j is source
    if (parent[j] == -1)
    {
        printf("\e[38;2;255;105;105m%s\e[m ", loc[j]);
        return;
    }

    printPath(parent, parent[j], loc);

    printf("--> \e[38;2;255;105;105m%s\e[m ", loc[j]);
}


// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void printShortestPath(int parent[], int src, int dest, int dist[], char loc[][50])
{
    printf("Shortest Path from %d to %d: ", src, dest);
    printPath(parent, dest, loc);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("Travel Distance: \e[38;2;255;105;105m%d km\e[m\n", dist[dest]);
    int avg_speed = 42;
    float time = (float)dist[dest] / avg_speed;
    time *= 60;
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("Travel Time: \e[38;2;255;105;105m%1.1f mins\e[m\n", time);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
}

void dijkstra(int graph[V][V], int src, int dest, char loc[][50])
{
    int dist[V];
    // The output array.  dist[i] will hold the shortest distance from src to i

    bool sptSet[V];
    // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    int parent[V];
    // storing explored nodes
   
   // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    // Distance of source vertex from itself is always 0.
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)     
    {   
        /* Pick the minimum distance vertex from the set of
           vertices not yet processed. u is always equal to
           src in the first iteration. */
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)            
        {    
           /* Update dist[v] only if is not in sptSet,
             there is an edge from u to v, and total
             weight of path from src to  v through u is
             smaller than current value of dist[v] */

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }


    // prints the desired output on the screen
    printShortestPath(parent, src, dest, dist, loc);
}
#define yellow "\033[1;33m"
#define reset "\033[0m\n"
int main()
{

    printf(yellow"  __   __   ______  _______  _____    _____            _____    _____   _     _  _______  ______           ______  _______  _     _  _____   ______  _____  "reset);
    printf(yellow" (__)_(__) (______)(__ _ __)(_____)  (_____)          (_____)  (_____) (_)   (_)(__ _ __)(______)         (______)(_______)(_)   (_)(_____) (______)(_____) "reset);
    printf(yellow"(_) (_) (_)(_)__      (_)   (_)__(_)(_)   (_)         (_)__(_)(_)   (_)(_)   (_)   (_)   (_)__            (_)__      (_)   (__)_ (_)(_)  (_)(_)__   (_)__(_)"reset);
    printf(yellow"(_) (_) (_)(____)     (_)   (_____) (_)   (_)         (_____) (_)   (_)(_)   (_)   (_)   (____)           (____)     (_)   (_)(_)(_)(_)  (_)(____)  (_____) "reset);
    printf(yellow"(_)     (_)(_)____    (_)   ( ) ( ) (_)___(_)         ( ) ( ) (_)___(_)(_)___(_)   (_)   (_)____          (_)      __(_)__ (_)  (__)(_)__(_)(_)____ ( ) ( ) "reset);
    printf(yellow"(_)     (_)(______)   (_)   (_)  (_) (_____)          (_)  (_) (_____)  (_____)    (_)   (______)         (_)     (_______)(_)   (_)(_____) (______)(_)  (_)"reset);
    printf(yellow"                                                                                                                                                            "reset);



   /* The graph represents the connectivity between the metro stations, where each station is 
    represented by a vertex and the distances between stations are represented by the edges */

    int graph[V][V] = {{0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {6, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 14, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 7, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 9, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 6, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 23, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 4, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
    int src, dest;
label:
    printf("\t________________________________________________________________________________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n\t\t\t\e[1;4;38;2;255;255;0mWelcome to METRO ROUTE FINDER System !!!\e[m\n\n\n\tHere is the list of stations under Patna Metro, please take referrence\n from the list and enter the \e[38;2;255;105;105;3mIndex\e[0m corresponding to your source station and destination\n station to find the shortest route of travel and time taken for the journey.\n\n");

    char loc[21][50] = {{"Ara Jn."}, {"Jamira"}, {"Pali"}, {"Bihta"}, {"Patel Halt"}, {"Sadisopur"}, {"Goriya Dera"}, {"Danapur"}, {"Phulwari"}, {"Sachiwalay Halt"}, {"Patna Jn."}, {"Parsa Bazaar"}, {"Neema Halt"}, {"Jehanabad"}, {"Rajendra Nagar Tr."}, {"Patna Saheb"}, {"Dedarganj"}, {"Dak Bangla"}, {"Fraser Road"}, {"Bihar Mueseum"}, {"Patliputra Jn."}};
    printf("\n");
    printf("\n \n\e[38;2;0;255;0mStation Code\t\t\tStation\e[m\n");

    for (int i = 0; i < 21; i++) 
    {
        printf("\e[38;2;79;192;208m%d\e[m\t\t->\t\t\e[38;2;79;192;208m%s\e[m\n", i, loc[i]);
    }
    printf("\n \n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("Enter source: \n");
    scanf("%d", &src);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("Enter destination: \n");
    scanf("%d", &dest);
    printf("\n");
    printf("____________________________________________________________________________________________________");
    printf("\n\n");
    dijkstra(graph, src, dest, loc);
    printf("\n\n\n");
    printf("If you want to find route again please enter 1 or else enter 0: \n");
    int reuse = 0;
    scanf("%d", &reuse);
    if (reuse)
    {
        goto label;
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf(".............................THANK YOU FOR USING METRO ROUTE FINDER.................................");
    printf("\n");
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}
