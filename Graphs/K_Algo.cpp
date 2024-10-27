#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{

public:
    int ei, ej, wi;

    Edge(int a, int b, int c)
    { // Constructor
        ei = a;
        ej = b;
        wi = c;
    }
};

bool comp(Edge e1, Edge e2)
{
    return e1.wi < e2.wi;
}

int findParent(int v1, int *parent)
{
    if (parent[v1] == v1)
    {
        return v1;
    }
    else
    {
        return findParent(parent[v1], parent);
    }
}

int main()
{
    int v, e;
    // cout << "Enter v and e" << endl;
    cin >> v >> e;

    vector<Edge> input;
    vector<Edge> mst;
    int ei, ej, wi;

    for (int i = 0; i < e; i++)
    {
        // cout << "ei, ej and wi for object " << i + 1 << endl;
        cin >> ei >> ej >> wi;
        Edge e(ei, ej, wi);
        input.push_back(e);
    }

    // Sorting according to the weights
    sort(input.begin(), input.end(), &comp);

    // Printing the array
    /*
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i].wi << " ";
    }
    cout << endl;
    */

    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0; //to maintain count of number of edges in Mst
    int k = 0; //to traverse the input array
    while (count != v - 1)
    {
        // ei and ej are vertices
        int v1 = input[k].ei;
        int v2 = input[k].ej;

        int p1 = findParent(v1, parent);
        int p2 = findParent(v2, parent);

        if (p1 != p2)
        {
            mst.push_back(input[k]);
            count++;
            parent[p1] = p2;
        }
        k++;
    }

    for (int i = 0; i < v - 1; i++)
    {
        if (mst[i].ei < mst[i].ej)
        {
            cout << mst[i].ei << " " << mst[i].ej << " " << mst[i].wi << endl;
        }
        else
        {
            cout << mst[i].ej << " " << mst[i].ei << " " << mst[i].wi << endl;
        }
    }

    return 0;
}
