//
//  Node.cpp
//  shortestpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//

#include "Node.h"
Node::Node(int w, int a, Node* n){
    adjacent = a;
    weight= w;
    nextNode = n;
    known = 0;
}


