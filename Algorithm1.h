//
//  Algorithm1.h
//  shrtpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//

#ifndef shrtpath_Algorithm1_h
#define shrtpath_Algorithm1_h


#include "AdjacencyList.h"
#include "Path.h"
using namespace std;
class Algorithm1{
public:
                 Algorithm1(AdjacencyList* a, int ** groups, int numGroups, int numvertices);
                 void runAlgo(AdjacencyList* a, int ** groups, int numGroups, int numvertices);
};

#endif
