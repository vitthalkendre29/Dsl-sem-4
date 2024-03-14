#include <iostream>
using namespace std;

const int Max = 15;

class Graph {
public:
    int numvertices;
    int adjmatrix[Max][Max];

    Graph(int numvertices) {
        this->numvertices = numvertices;
        for (int i = 1; i <= numvertices; i++) {
            for (int j = 1; j <= numvertices; j++) {
                adjmatrix[i][j] = 1000;
            }
        }
    }

    void insertedge(int row, int col, int weight) {
        adjmatrix[row][col] = weight;
        for(int i=1;i<=numvertices;i++) {
            adjmatrix[i][i] = 0;
        }
    }

    void printgraph() {
        for (int i = 1; i <= numvertices; i++) {
            cout << "vertex " << i << " is connected to :";
            for (int j = 1; j <= numvertices; j++) {
                if (adjmatrix[i][j] != 1000) {
                    cout << j << " its weight is " << adjmatrix[i][j] << "    ";
                }
            }
            cout << endl;
        }
    }

    void print() {
        for (int i = 1; i <= numvertices; i++) {
            for (int j = 1; j <= numvertices; j++) {
                cout << adjmatrix[i][j] << "   ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 4;
    Graph graph(numVertices);
    graph.insertedge(1, 2, 3);
    graph.insertedge(1, 4, 7);
    graph.insertedge(4, 1, 2);
    graph.insertedge(2, 1, 8);
    graph.insertedge(2, 3, 2);
    graph.insertedge(3, 1, 5);
    graph.insertedge(3, 4, 1);





    for(int k=1;k<=numVertices;k++)
        {
            for(int i=1;i<=numVertices;i++)
                {
                    for(int j=1;j<=numVertices;j++)
                        {
                            graph.adjmatrix[i][j]=min(graph.adjmatrix[i][j],graph.adjmatrix[i][k]+graph.adjmatrix[k][j]);
                            
                        }
                }
        }
    for(int i=1;i<=numVertices;i++){
        for(int j=1;j<=numVertices;j++)
        {
            cout<<graph.adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
