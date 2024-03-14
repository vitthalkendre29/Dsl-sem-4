#include<iostream>

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
                adjmatrix[i][j] = 1000 ;
            }
        }
    }

    void insertedge(int row, int col, int weight) {
        adjmatrix[row][col] = weight;
        if(row==col){
            adjmatrix[row][col]=0;
        }
        
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

    
     void print(){
        for (int i=1;i<=numvertices;i++){
            for (int j=1;j<=numvertices;j++){
               cout<< adjmatrix[i][j]<<"   ";
			}
            cout<<endl;
        }
    }

};

int main(){
    // cout<<"assign all the node to 1,2,3,... format and submit connecting edges and weight of corresponding edge:"<<endl;
    // int sk,kk,vk,mk,dk,k,i,j;
    // cout<<"\nenter number of vertices:";
    // cin>>mk;
    // // cout<<endl;
    // int numVertices = mk;
    // Graph graph(numVertices);
    // cout<<"\nenter number of Edges:";
    // cin>>dk;
    // cout<<endl;
    // cout<<"\nenter edges with weights"<<endl;
    // for (int i=0;i<dk;i++){
    //     cout<<"\nenter starting node: ";
    //     cin>>sk;
    //     cout<<" enter ending node: ";
    //     cin>>kk;
    //     cout<<" enter weight of this edge: ";
    //     cin>>vk;
    //     cout<<endl;
    //     graph.insertedge(sk,kk,vk);
    // }
    // graph.printgraph();
    // cout<<endl;
    // graph.print();
    int numVertices = 4;
    int mk;
    numVertices=mk;
    Graph graph(numVertices);
    graph.insertedge(1, 2, 3);
    graph.insertedge(1, 4, 7);
    graph.insertedge(4, 1, 2);
    graph.insertedge(2, 1, 8);
    graph.insertedge(2, 3, 2);
    graph.insertedge(3, 1, 5);
    graph.insertedge(3, 4, 1);
    
    

    graph.printgraph();
    graph.print();
    
    // for(int k=1;k<=mk;k++)
    //     {
    //         for(int i=1;i<=mk;i++)
    //             {
    //                 for(int j=1;j<=mk;j++)
    //                     {
    //                         graph.adjmatrix[i][j]=min(graph.adjmatrix[i][j],graph.adjmatrix[i][k]+graph.adjmatrix[k][j]);
    //                         cout<<graph.adjmatrix[i][j]<<endl;
    //                     }
    //             }
    //     }
    return 0;
}

