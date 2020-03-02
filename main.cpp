/* 
 * File:   main.cpp
 * Author: helmuth
 *
 * Created on 1 de marzo de 2020, 18:32
 */

#include <cstdlib>
#include "Queue.hpp"
#include "Queue.cpp"

using namespace std;

/*
 * 
 */
int main() {
    try{
        Queue<char> queue;
        queue.add('a');
        queue.add('b');
        queue.add('c');
        queue.add('d');
        queue.add('e');
       
        cout<<queue.peek() <<endl;
        
        while(!queue.isEmpty()){
            cout << queue.remove() <<" ";
        }
    }
    catch(string e){
        cout<<e<<endl;
    }
    
    return 0;
}

