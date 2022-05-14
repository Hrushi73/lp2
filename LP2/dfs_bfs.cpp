#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>Graph[N];

vector<int>visited(N);
void reset()
{
    for(int i=0;i<N;i++)
    {
        visited[i]=0;
    }
}

void dfs(int source)
{
    visited[source]=1;
    cout<<source<<" ";
    for(auto child:Graph[source])
    {
        if(visited[child])
        {
            continue;
        }
        else
        {
            dfs(child);
        }
    }
}

void  bfs(int source)
{
    reset();
    queue<int>q;
    q.push(source);
    visited[source]=1;
    cout<<source<<" ";
    while (!q.empty())
    {
        int ver=q.front();
        q.pop();
        for(auto child : Graph[ver])
        {
            if(visited[child])
            {
                continue;
            }
            visited[child]=1;
            cout<<child<<" is visited\n";
            q.push(child);
        }

    }

}
void addGraph()
{
    // reseting all values;
    for(int i=0;i<N;i++)
    {
        visited[i]=0;;
        Graph[i].clear();

    }
    int n,m;
    cout<<"Enter Number of vertices : ";
    cin>>n;
    cout<<"Enter Number of Edges    : ";
    cin>>m;
    while(m--)
    {
        int x,y;

        cout<<"Enter Source and Destination Vertex : ";
        cin>>x>>y;

        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }


}

void Search(int ver)
{
    int flag=0;
    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
        {

            continue;
        }
        else{
            if(i==ver)
            {
                flag=1;
                break;
            }
        }

    }
    if(flag==0)
    {
        cout<<"No Such vertex Exist in Graph\n";
    }
    else if(flag==1)
    {
        cout<<"Vertex "<<ver<<" Exist in graph\n";
    }
}
int main()
{
    int choice;
    int source;
    do
    {
        cout<<"\n-------------------MENU--------------------\n";
        cout<<"1.Add Graph\n";
        cout<<"2.BFS\n";
        cout<<"3.DFS\n";
        cout<<"4.Serch Vertex\n";
        cout<<"5.Exit\n";
        cout<<"\n-------------------------------------------\n";
        cout<<"Enter a Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:addGraph();
            break;
         case 2:
                cout<<"Enter a Source vertex : ";
                cin>>source;
                bfs(source);
            break;
         case 3: reset();
                cout<<"Enter a Source vertex : ";
                cin>>source;
                dfs(source);
            break;
        case 4:cout<<"Enter Vertex/Node : ";
            cin>>source;
            Search(source);
            break;
        case 5:
                break;
        default:
            break;
        }
    } while (choice!=5);

}
