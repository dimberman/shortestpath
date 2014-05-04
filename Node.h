//
//  Node.h
//  shortestpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//

#ifndef shortestpath_Node_h
#define shortestpath_Node_h


class Node{
public:
    Node(int w, int a, Node* n);
    int weight;
    int adjacent;
    int getWeight();
    int getAdjacent();
    Node * nextNode;
    int known;
};



#endif
