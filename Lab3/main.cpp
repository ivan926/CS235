#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
#include <string>


using namespace std;

void readFile(char *argv, vector<string>& words)
{
    
    ifstream input(argv);
    
    string line = "";
    ofstream output("Nephi_vector.txt");

    while(getline(input, line)){

        istringstream iss(line);
        string word = "";
        

        while(iss >> word){
        string nopunct = ""; 
            
            for (auto &c : word){
             
                if( isalpha(c) ){

                    nopunct+=c;


                }
            }

            words.push_back(nopunct);
        }

        





    }


    for (int i = 0; i < words.size(); i++){

        output << words.at(i) << " ";

    }

    input.close();

    output.close();


}


int main(int argc, char *argv[])
{
    // Sets
    set <string> strset;
    strset.insert("bug");
    strset.insert("horse");
    strset.insert("horse");
    set<string>::iterator findit;
    findit = strset.find("horse");
    cout << "Found horse "<< *findit<<endl;
    for (set<string>::iterator it = strset.begin(); it != strset.end(); ++it) 
    
    cout << ' ' << *it;

    
    cout << endl; 

    
    


    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
           
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    
                    nopunct +=c;

                    

                }

                
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    ofstream output("Nephi_set.txt");

    
  for (set<string>::iterator i = unique.begin(); i != unique.end(); i++){


    output << *i << " ";


       

   }
   output.close();

   in.close();
   


    vector<string> words;

    readFile(argv[1],words);

   

    

    //part THREE
    //output.open("Nephi_map.txt");
//    map<string,string> wordmap;

//     string last = "";
//     for (vector<string>::iterator it = words.begin(); it!= words.end(); it++) {

        
        
//         wordmap[last] = *it;
//         last = *it;
        
        
//     }

    

//     for (map<string,string>::iterator it = wordmap.begin(); it!= wordmap.end(); it++) {

        
            
            
//             output << (*it).first << "," << (*it).second << endl;

            
            

        
//     }

//part 4
    
    // string state = "";
    // for(int i = 0; i < 100; i++){
    // cout << wordmap[state] << " ";
    // state = wordmap[state];
    // }
    // cout << endl;

//part 5
    
    // cout << endl;
    // string state = "";
    // map<string, vector<string> > wordmap;
    
    // for(vector<string>::iterator it = words.begin(); it !=words.end(); it++) {
    // wordmap[state].push_back(*it);
    
    // state = *it;


    
    // } 

    
    // printing out example for part five 
    //  for (int i = 0; i < wordmap["Nephi"].size(); i++){
    //         cout << wordmap["Nephi"].at(i) << ", ";
    //     }  

   

//part 2 of part FIVE
    
    
    
    // srand(time(NULL)); // this line initializes the random number generated
    //                 // so you dont get the same thing every time
    // state = "";
    // for (int i = 0; i < 100; i++) {
    
    
    
    
    
    // int ind = rand() % wordmap[state].size();
    // cout << wordmap[state][ind] << " ";
    // state = wordmap[state][ind];
    
    // }
    // cout << endl;

//part six
  const int M = 2;
  
 map<list<string>, vector<string> > wordmap2;
  list<string> state;
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
                        
  for (vector<string>::iterator it= words.begin(); it!= words.end(); it++) {
    wordmap2[state].push_back(*it);
    state.push_back(*it);
    state.pop_front();
  }


  

//part (2) two of six
  srand(time(NULL)); // this line initializes the random number generated

  state.clear();
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap2[state].size();
    cout << wordmap2[state][ind]<<" ";
    state.push_back(wordmap2[state][ind]);
    state.pop_front();
  }



   
    // map<string, vector<string> > wordmap2;
    // string state = "";
    // for(vector<string>::iterator it = words.begin(); it != words.end(); it++) {
    // wordmap2[state].push_back(*it);
    // state = *it;
    // }

    // ofstream oput("Hellothere.txt");

    // for(map<string, vector<string> >::iterator it = wordmap2.begin(); it != wordmap2.end(); it++) {
    //     int i = 0;
        
    //     if ( (*it).first == "Nephi"){

            
    //        cout << wordmap2[(*it).first].at(i) << endl;

    //     }
        
    //     i++;
    // }

    // cout << wordmap2.size();

//     srand(time(NULL)); // this line initializes the random number generated
//                    // so you dont get the same thing every time
//     state = "";
//     for (int i = 0; i < 100; i++) {
//     int ind = rand() % wordmap2[state].size();
//     cout << wordmap2[state][ind] << " ";
//     state = wordmap2[state][ind];
// }
// cout << endl;


//   map<list<string>, vector<string> > wordmap;
//   vector<string> state;
//   for (int i = 0; i < wordmap.size(); i++) {
//     state.push_back("");
//   }
                        
//   for (vector<string>::iterator it = words.begin(); it! = words.end(); it++) {
//     wordmap[state].push_back(*it);
//     state.push_back(*it);
    
//   }












//  map<vector<string>, vector<string> > wordmap2;
  
//   for (int i = 0; i < wordmap2.size(); i++) {
//     words.push_back("");
//   }
                        
//   for (vector<string>::iterator it=words.begin(); it!=words.end(); it++) {
//     wordmap2[words].push_back(*it);
//     words.push_back(*it);
//     words.erase(words.begin());
    
//   }













   
   //prints contents of set out
    // for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it)
    //     cout << ' ' << *it;
    // cout << endl;



    // pairs
    // pair <string,int> mypair;
    // mypair.first = "Hello";
    // mypair.second = 8;
    // cout << mypair.first<<" "<<mypair.second<<endl;
    // set <pair <string, int>> pairset;
    // pairset.insert(mypair);
    // set<pair <string, int>>::iterator findpair;
    // findpair = pairset.find(mypair);
    // cout << "found First "<<findpair->first<<" second "<<findpair->second<<endl;



    //     // maps
    // map <string, int> wordcount;
    // wordcount["foo"] = 5;
    // cout << "wordcount for foo "<<wordcount["foo"]<<endl;
    // wordcount.insert(mypair);
    // cout << "wordcount for Hello "<<wordcount["Hello"]<<endl;



    //  wordcount.clear();
    // for(auto s:tokens) {
    //     wordcount[s]++;
    // }
    // for (map<string,int>::iterator it=wordcount.begin(); it!=wordcount.end(); ++it)
    //     cout << it->first<<' ' << it->second<<endl;
    // cout << endl;


}