//
//  main.cpp
//  shrtpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "AdjacencyList.h"
#include "Algorithm1.h"
#include <iterator>
using namespace std;

int main(int argc, const char * argv[])
{
    string line;
    getline(cin, line);
    istringstream buf(line);
    
    string word;
    int arguments[5];
    int i = 0;
    while (buf>>word) {
        if(i>3){
            cout<<"too many initial arguments"<<endl;
            exit(1);
        }
        arguments[i]= atoi(word.c_str());
//        cout<<arguments[i]<<endl;
        i++;
    }
    int numvertices = arguments[0];
    int numedges = arguments[1];
    int numgroups = arguments[2];
    int algorithm = arguments[3];
    
    
    AdjacencyList * graph = new AdjacencyList[numvertices+1]();
    int sourcenode;
    int destnode;
    int weight;
    for (i = 0; i<numedges; i++) {
        getline(cin, line);
        istringstream buf(line);
        int j = 0;
        while (buf>>word) {
            switch (j) {
                case 0:
                    sourcenode = atoi(word.c_str());
                    break;
                case 1:
                    destnode   = atoi(word.c_str());
                    break;
                case 2:
                    weight  = atoi(word.c_str());
                    break;
                default:
                    cout<<"error in input"<<endl;
                    exit(1);
                    break;
            }
            j++;
        }
        
        graph[sourcenode].insert(weight, destnode);
        graph[destnode].insert(weight, sourcenode);
        
        
    }
    
    
    
    
    
    
    
//    for (int a = 0; a<numvertices; a++) {
//        cout<<a<<" ";
//        graph[a].printList();
//    }
//    
    
    
    
    
    int ** groups = new int * [numgroups];
    for (i=0; i<numgroups; i++) {
        int * currentGroup;
        getline(cin, line);
        istringstream buf(line);
        int j = 0;
        while (buf>>word) {
            switch (j) {
                case 0:
                    currentGroup = new int [atoi(word.c_str())+1];
                    currentGroup[0] = atoi(word.c_str());
                    break;
                    
                default:
                    currentGroup[j] = atoi(word.c_str());
                    break;
            }
            j++;
        }
        groups[i] = currentGroup;
    }
    
    
//    for (i=0; i<numgroups; i++) {
//        for (int j = 0; j<=groups[i][0]; j++) {
//            cout<<(int)groups[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    
    
    
    Algorithm1(graph, groups, numgroups, numvertices);
    
    return 0;
}

