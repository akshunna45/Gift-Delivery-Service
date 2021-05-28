#include <stdio.h>
#include <limits.h>
#define V 9
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
void dijkstra(int graph[V][V], int src, int x)
{
     int dist[V];
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
     cout<<"Distance of Destination from Source "<<dist[x];
}
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   if (n == 0 || W == 0)
       return 0;
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
int main()
{
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int deliver;
    cout<<"Enter the delivery node ";
    cin>>deliver;
    dijkstra(graph, 0, deliver);
    cout<<"\nEnter number of items ";
    int n;
    cin>>n;
    int val[n];
    cout<<"\nEnter Value ";
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int wt[n];
    cout<<"\nEnter Weight";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int  W;
    cout<<"Enter the total capacity of delivery van ";
    cin>>W;
    int n1 = sizeof(val)/sizeof(val[0]);
    int bill= knapSack(W, wt, val, n1);
    cout<<"\nTotal Bill = "<<bill<<endl;
    int change[9]={1000,500,100,50,20,10,5,2,1};
    int x[9]={0,0,0,0,0,0,0,0,0};
    int c=0,i=0;
    int v1=bill;
    while(v1>0)
    {
        if(change[i]<=v1)
        {
            v1-=change[i];
            c++;
            x[i]++;
        }
        else
        {
            i++;
        }
    }
    cout<<"We need "<<c<<" no. of notes/coins\n";
    for(int j=0;j<9;j++)
    {
        if(x[j]!=0)
        {
            cout<<"We need "<<x[j]<<" notes/coins of "<<change[j]<<endl;
        }
    }
    return 0;
}
