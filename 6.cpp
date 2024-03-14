#include<iostream>
using namespace std;

const int Max = 15;

class Graph {
    int numvertices;
    int adjmatrix[Max][Max];

public:
    Graph(int numvertices) {
        this->numvertices = numvertices;
        for (int i = 1; i <= numvertices; i++) {
            for (int j = 1; j <= numvertices; j++) {
                adjmatrix[i][j] = 0;
            }
        }
    }

    void insertedge(int row, int col, int weight) {
        adjmatrix[row][col] = weight;
        adjmatrix[col][row] = weight;
    }

    void printgraph() {
        for (int i = 1; i <= numvertices; i++) {
            cout << "vertex " << i << " is connected to :";
            for (int j = 1; j <= numvertices; j++) {
                if (adjmatrix[i][j] != 0) {
                    cout << j << " its weight is " << adjmatrix[i][j] << "    ";
                }
            }
            cout << endl;
        }
    }

    int getWeight(int i, int j) {
        return adjmatrix[i][j];
    }
     void print(){
        for (int i=1;i<=numvertices;i++){
            for (int j=1;j<=numvertices;j++){
               cout<< adjmatrix[i][j]<<"   ";
			}
            cout<<endl;
        }
    }

};

int main() {
    // int numVertices = 5;
    // Graph graph(numVertices);
    // graph.insertedge(2, 3, 2);
    // graph.insertedge(1, 3, 4);
    // graph.insertedge(1, 2, 4);
    // graph.insertedge(4, 3, 3);
    // graph.insertedge(5, 4, 3);
    // graph.insertedge(3, 6, 2);
    // graph.insertedge(6, 5, 3);
    
    

    // graph.printgraph();
    // cout<<endl;
    // graph.print();

    cout<<"assign all the node to 1,2,3,... format and submit connecting edges and weight of corresponding edge:"<<endl;
    int sk,kk,vk,mk,dk;
    cout<<"\nenter number of vertices:";
    cin>>mk;
    cout<<endl;
    int numVertices = mk;
    Graph graph(numVertices);
    cout<<"\nenter number of Edges:";
    cin>>dk;
    cout<<endl;
    cout<<"\nenter edges with weights"<<endl;
    for (int i=0;i<dk;i++){
        cout<<"\nenter starting node: ";
        cin>>sk;
        cout<<" enter ending node: ";
        cin>>kk;
        cout<<" enter weight of this edge: ";
        cin>>vk;
        cout<<endl;
        graph.insertedge(sk,kk,vk);
    }
    graph.printgraph();
    cout<<endl;
    graph.print();


    int visited[numVertices] = {0};
    visited[0] = 1;
    int mincost=0;
    for (int k = 0; k < numVertices; k++) {
        int min = 1000; // Initialize min
        int row = -1, col = -1; // Initialize row and col
        for (int i = 0; i < numVertices; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < numVertices; j++) {
                    if (graph.getWeight(j, k) != 0 && visited[k] == 0) {
                        if (graph.getWeight(j, k) < min) {
                            min = graph.getWeight(j, k);
                            row = j;
                            col = k;
                            
                        }
                        
                    }
                }
            }
        }
        
        // Do something with row and col
        mincost+=min;
        visited[col]=1;
        
    }
    mincost-=1000;
    cout<<"total cost of MST is:"<<mincost<<endl;


        return 0;
}
