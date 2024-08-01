#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> neighbours;


};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=9;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        nodes[u].neighbours.push_back(v); //add neighbours in to the node u's list

        //select node v and push u into v's neighbour
        nodes[v].neighbours.push_back(u); //add neighbours in to the node v's list


    }

    void print(){
        //lets iterate through each node and print its neighbours
        for (int i = 1; i <n;i++) {
            //check node neighbours are empty not print enething and continue the loop
            if(nodes[i].neighbours.empty()){
                continue;   //continue the traverse 
            }
            else{
                cout<<"Neighbours of Node "<<i<<" : ";
                // traverse through the neighbours list
                for(int k:nodes[i].neighbours){

                    cout<<k<<" "; //print neighbour
                }
                cout<<"\n";  //goto new line
            }
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g ->addedge(5,6);
    g ->addedge(5,7);
    g ->addedge(5,8);
    g ->addedge(4,6);
    g ->addedge(4,7);
    g ->addedge(4,8);
    g ->addedge(2,6);
    g ->addedge(2,3);
    g ->addedge(1,2);
    g ->addedge(1,3);
    g ->addedge(1,4);
    g ->addedge(1,5);
    //print the graph adjaceny list
    g->print();
}

