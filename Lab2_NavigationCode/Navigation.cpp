#include <iostream>
#include "Navigation.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


 bool Navigation::readNetwork(string _mapName){

   ifstream input(_mapName);
   string firstLine;
   string line;
   stringstream numConverter;
 
   vector<int> list_of_map_nums;
   

   // This is to figure out size of map by reading the first line of text file

   input >> firstLine;

   numConverter << firstLine;

   numConverter >> this->numNodes;

   int list[this->numNodes];

   int counter = 0;



     

      while(counter <= this->numNodes){
         

         getline(input,line);
         
         numConverter << line;

      if(counter > 0){  
         for (int j = 0; j < this->numNodes; ++j){
            numConverter >> list[j];

            //cout << list[j] << " ";


            list_of_map_nums.push_back(list[j]);
           
             //cout << list_of_map_nums.at(j) << " ";
            
         }

         cout << endl;
        
          this->map.push_back(list_of_map_nums);

          
      
            list_of_map_nums.clear();
         

      }
         

      counter++;

         numConverter.clear();

         // end of while loop
      }


   //    for (int i = 0; i < this->map.size(); i++) {
        
   //      for (int j = 0; j < this->map.size(); j++)

           
   //          cout << this->map[i][j] << " ";
   //      cout << endl;
   //  }

   


   

      
   

    return false;
 }

    // This function computes and returns the least-cost path from node indexed _startInd to node indexed as _endInd
    // for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
    // with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
    // and the back of the queue should be _endInd.
    // For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
    //      13, 9, 10, 7, 3, 2, 1
    // You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists

    queue<int> Navigation::computeShortestPath(int _startInd, int _endInd){ 
      //  PriorityQueue<Node> node_maps;
       
       
       // start of commented line recent
       priority_queue<Node, vector<Node>, Node> myPriorityQueue;
   
       queue<int> list;

      

      



       

       struct Node n1;

       struct Node current;

       int last = 0;

       n1.cost = 0;

       n1.path.push(_startInd);


       myPriorityQueue.push(n1);

       //end of commented line recent




       //cout << myPriorityQueue.top().path.front();


       // myPriorityQueue.top().path.back() != _endInd

     while(true ){

      if (myPriorityQueue.top().path.back() == _endInd){
         

          list = myPriorityQueue.top().path;
        
         break;
      }
      else {
         // current.cost = myPriorityQueue.top().cost;

         // current.path.push(priority_queue.top().path;

         current = myPriorityQueue.top();

         myPriorityQueue.pop();

         last = current.path.back();

         

         
         int i = last;
        
          for (int j = 0; j < this->map.size(); j++)
          {

             if(this->map[i][j] > 0 )
             { 
                struct Node nn;

                nn.cost = current.cost + this->map[i][j];

                nn.path = current.path;

                nn.path.push(j);

                


               myPriorityQueue.push(nn);

             }
           
            
          }

        

          
        
    
         







      

      






       } //end of else scope

        









      } //end of while loop


     
      
      


       return list;
    }



    // prints out to the console the path stored in _path
    
    void Navigation::printPath(queue<int> _path){
      
      while(!_path.empty()){
		cout << " " << _path.front();
		_path.pop();

      
	}

   cout << endl;

      return;

    }