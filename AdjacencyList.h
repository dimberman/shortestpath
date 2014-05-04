//
//  AdjacencyList.h
//  shortestpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//

#ifndef shortestpath_AdjacencyList_h
#define shortestpath_AdjacencyList_h
#include "Node.h"
#include <iostream>

class AdjacencyList{
public:
    AdjacencyList();
    void insert(int w, int a);
    Node * lookup(int key);
    void printList();
    int totalCost();
    int distance;
    int path;
    bool known;
    Node * head;
    
    
};

#endif
