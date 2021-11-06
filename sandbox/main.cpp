#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


struct Node {
    int cost;
    queue<int> path;

    bool operator() (Node const& n1, Node const& n2) {
        return n1.cost > n2.cost;
    }
};

int main(){

priority_queue<Node, vector<Node>, Node> myPriorityQueue;


    struct Node n1;

    struct Node n2;

    struct Node n3;

    n1.cost = 0;

    myPriorityQueue.push(n1);

 

     



    







    
    

    

    // priority_queue<int> list;

    // list.push(1);
    // list.push(6);
    // list.push(5);

    
    // cout << list.top() << endl;

    // list.pop();

    // cout << list.top() << endl;

    









    return 0;
}

