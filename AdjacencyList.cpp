//
//  AdjacencyList.cpp
//  shortestpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//

#include "AdjacencyList.h"


AdjacencyList::AdjacencyList(){
    head = new Node(-1,0,0);
}

void AdjacencyList::insert(int w, int a){
    Node * finder = head;
    if (finder->weight!=-1) {
        while (finder->nextNode!=0) {
            finder = finder->nextNode;
        }
        finder->nextNode = new Node(w,a,0);

    }
    else head = new Node(w,a,0);

}

Node * AdjacencyList::lookup(int key){
    Node * finder = head;
    if (finder!=0) {

    while (finder->nextNode!=0) {
        if (finder->adjacent == key) {
            return finder;
        }
        finder = finder->nextNode;

    }
    }
    return 0;
}


int AdjacencyList::totalCost(){
    Node * finder = head;
    if (finder!=0) {
        int sum =0;
        while (finder->nextNode!=0) {
            
            sum += finder->weight;
            finder = finder->nextNode;

        }
        return sum;
    }
    else return 0;
}

void AdjacencyList::printList(){
    Node * finder = head;
    if (finder!=0) {
    while (finder->nextNode!=0) {
        finder = finder->nextNode;
        std::cout<<" "<<finder->adjacent<<" ";
    }
    }
    std::cout<<std::endl;
    
}