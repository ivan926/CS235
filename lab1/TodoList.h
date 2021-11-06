#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "ToDoListInterface.h"

using namespace std;

class ToDoList{

       public:
        ToDoList() {
            cout << "In constructor";


        }

        virtual ~ToDoList(){

            cout << "Destructor activated" << endl;
        }

        

         virtual void add(string _duedate, string _task){
            cout << "Within add function" << endl;

         }

         virtual int remove(){
             cout << "Within remove function" << endl;

             return 0;
         }

         virtual void printTodoList(){
             cout << "Within print todo list function" << endl;
         }

         virtual void printDaysTasks(){
             cout << "Within day tasks function" << endl;
         }



};


 

#endif 
