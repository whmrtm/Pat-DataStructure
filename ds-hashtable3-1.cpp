#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int x;
    int y;
    node(int a, int b):x(a),y(b) {}
};

int main()
{
    int N;
    cin >> N;
    int *Hash = new int[N];
    int *Degree = new int[N];
    vector<vector<int> > G(N);
    vector<int> Ans;
    // input the hash table
    for(int i=0; i<N; i++)
    {
        cin >> Hash[i];
        if(Hash[i] >= 0)
            Degree[i] = 0; //if bigger than 0, the degree is 0
        else
            Degree[i] = -1;//if it is -1, the degree is -1
    }
    // calculate the degrees and build the graph
    for(int i=0; i<N; i++)
    {
        if(Hash[i] < 0) continue;
        int CurPos = i;                         
        int HashPos = Hash[i] % N;              
        Degree[i] = (CurPos - HashPos + N) % N; // degree
		for(int s  = 0; s < Degree[i]; s++)      //把Key%N 到 i - 1 的顶点指向 i
        {
            G[(HashPos + s + N) % N].push_back(i);
        }
    }

    typedef pair<int, int> PAIR;
    priority_queue< PAIR, vector< PAIR >, greater< PAIR > > Q;
    for(int i = 0; i < N; i++)
        if(Degree[i] == 0)                  // enqueue the elements whose degrees are zero
        {
            Q.push(PAIR(Hash[i],i));
        }
        
    // top sort    
    while(!Q.empty())
    {
        PAIR p = Q.top();                       
        int V = p.second;                       
        Ans.push_back(p.first);                 
        Q.pop();
        for(int i = 0; i < G[V].size(); i++)    
            if (--Degree[G[V][i]] == 0)
                Q.push(PAIR(Hash[G[V][i]], G[V][i]));
    }
    cout << Ans[0];
    for(int i = 1; i < Ans.size(); i++)
        cout << ' ' << Ans[i];
    return 0;
}
