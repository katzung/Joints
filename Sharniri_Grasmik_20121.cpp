#include <iostream>
#include <stack>

enum vertexTypes
{
    original,
    opened,
    closed
};

using namespace std;

void DFS(int** adjacencyMatrix, int mSize, int start, int c, int* Dnum, int* Low)
{
    for (int i = 0; i < mSize; i++)
    {
        if (adjacencyMatrix[start][i] != 0 && Dnum[i] == 0)
        {
            c += 1;
            Dnum[i] = c;
            DFS(adjacencyMatrix, mSize, i, c, Dnum, Low);
        }
    }
    //ComputeLow
    int low = mSize + 1;
    for (int i = 0; i < mSize; i++)
    {
        if (adjacencyMatrix[start][i] != 0)
        {
            if (Dnum[i] > Dnum[start] && Low[i] < low)
            {
                low = Low[i];
            }
            else if(Dnum[i] < Dnum[start] && Dnum[i] < low)
            {
                low = Dnum[i];
            }
        }
    }
    Low[start] = low;
}

bool isJoint(int x, int** adjacencyMatrix, int mSize, int* Dnum, int* Low)
{
    for (int i = 0; i < mSize; i++)
    {
        if (adjacencyMatrix[x][i] != 0 && Dnum[i] > Dnum[x] && Low[i] == Dnum[x])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int** adjacencyMatrix;
    int mSize;

    cout << "Grasmik Roman 20121, Algorythm 7\n";
    cout << "Vertexes will be numerated from 1 to N, where N is number of vertexes.\n";
    cout << "Number of vertexes: ";
    cin >> mSize;
    cout << endl;

    adjacencyMatrix = new int* [mSize];
    for (int i = 0; i < mSize; ++i)
    {
        adjacencyMatrix[i] = new int[mSize];
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }
    cout << endl;

    int* Dnum = new int[mSize];
    for (int i = 0; i < mSize; i++)
    {
        Dnum[i] = 0;
    }
    Dnum[0] = 1;

    int* Low = new int[mSize];
    for (int i = 0; i < mSize; i++)
    {
        Low[i] = 0;
    }

    DFS(adjacencyMatrix, mSize, 0, 1, Dnum, Low);
    
    cout << "Joints: ";
    for (int i = 0; i < mSize; i++)
    {
        if (isJoint(i, adjacencyMatrix, mSize, Dnum, Low))
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}