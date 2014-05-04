//
//  Algorithm1.cpp
//  shrtpath
//
//  Created by Daniel Imberman on 4/19/14.
//  Copyright (c) 2014 Daniel Imberman. All rights reserved.
//
#include <math.h>
#include "Algorithm1.h"
#include <stdlib.h>
using namespace std;
int unvisited_groups_exist(int * groups, int numGroups);
Path * Djikstra(int destination, int * source, AdjacencyList graph[], int numvertices);
void clean_distances(AdjacencyList graph[], int numvertices);
bool lookup(int * source, int num);



Algorithm1::Algorithm1(AdjacencyList* a, int ** groups, int numGroups, int numvertices){
    runAlgo(a, groups, numGroups, numvertices);
}
void Algorithm1::runAlgo(AdjacencyList a[], int ** grp, int numGroups, int numvertices){
    int myGroup[numGroups];
    for (int i = 0; i<numGroups; i++) {
        myGroup[i] = 0;
    }
    myGroup[0] = 1;
    cout<<0<<std::endl;
    int tree [numvertices];
    int current = 0;
    tree[0] = 1;
    tree[1] = grp[0][1];
    
    Path * shortestOverall = new Path();

    while(unvisited_groups_exist(myGroup, numGroups)){
        shortestOverall->distance = 500000;
        int smallestGroup;
        for(int i = 0; i<numGroups; i++){
            if(myGroup[i]==0) {
                Path * shortestInGroup = new Path();
                shortestInGroup->distance = 500000;
                for (int j = 1; j<=grp[i][0]; j++) {
                    Path* tmp = Djikstra(grp[i][j], tree, a, numvertices);
                    if(tmp->distance==0){
                        int a;
//                        cout<<"distance became 0 at group: "<<i<<endl;
                    }
                    if (tmp->distance<shortestInGroup->distance) {
                        delete shortestInGroup;
                        shortestInGroup = tmp;
                    }
//                    if ((tmp->distance==shortestInGroup->distance) && tmp->head->index<shortestInGroup->head->index) {
//                        delete shortestInGroup;
//                        shortestInGroup = tmp;
//                    }
//                    
                    
                }
                int distance = shortestInGroup->distance;

                if (shortestInGroup->distance < shortestOverall->distance) {
                    shortestOverall = shortestInGroup;
                    smallestGroup = i;
                }
                else delete shortestInGroup;
                
                
                
                
            }
        }
        PathNode * p = shortestOverall->head;
        while (p!=0) {
//            for(int i = 1; i<=grp[smallestGroup][0]; i++){
//                if(lookup(grp[i], p->index))
//                    for (int j = 0; j<=grp[i][0]; j++) {
//                        tree[0]++;
//                        tree[tree[0]] = grp[i][j];
//                    }
//
//
//            }
//
            if(!lookup(tree, p->index)){
            tree[0]++;
            tree[tree[0]] = p->index;
            }
            p = p->next;
        }

        myGroup[smallestGroup]=1;
        cout<<smallestGroup<<endl;
    }
}





int unvisited_groups_exist(int * groups, int numGroups){
                           for(int i = 0; i<numGroups; i++){
                           if(groups[i]==0) return true;
                           }
                           return false;
}



int find_min(AdjacencyList graph[], int numvertices);
bool graph_finished(AdjacencyList graph[], int numvertices);
int vertex(AdjacencyList graph[], int numvertices, int distance);







Path* Djikstra(int destination, int * source, AdjacencyList graph[], int numvertices){
    clean_distances(graph, numvertices);
     graph[destination].distance = 0;
    while (!graph_finished(graph,numvertices)) {
        int dist = find_min(graph, numvertices);
        int vIndex = vertex(graph, numvertices, dist);
        AdjacencyList * myVertex = & graph[vIndex] ;
        myVertex->known = true;
        Node* edges  = myVertex->head;
        while (edges!=0) {
            AdjacencyList * dVert = &graph[edges->adjacent];
            if (!dVert->known) {
                if (myVertex->distance+edges->weight<dVert->distance) {
                    if (myVertex->distance+edges->weight==0) {
                        cout<<"there is a 0 weighted edge, this might be a problem"<<endl;
                    }
                    dVert->distance=myVertex->distance+edges->weight;
                    dVert->path = vIndex;
                }
            }
            edges=edges->nextNode;
        }
        
        
    }
    int dist = 50000;
    AdjacencyList ret;
    
    int ind;
    for (int j = 1; j<=source[0]; j++) {
        if (dist>graph[source[j]].distance) {
            dist=graph[source[j]].distance;
            if(graph[source[j]].distance==0){
//                cout<<"there is a 0 weighted path, this CANT be right from "<<source[j]<<" to "<<destination<<endl;

            }
//            cout<<"the distance of node "<<source[j]<<" is "<<dist<<endl;
            ret = graph[source[j]];
            ind = j;
        }
    }

//    cout<<"ending now"<<endl;
//    exit(0);
    Path * p = new Path();
    p->distance = dist;
    p->head = new PathNode(source[ind]);
    PathNode * pnode=p->head;
    if(!pnode){
        cout<<"pnode is null ya dingus"<<endl;
        exit(1);
    }
        while (pnode->index!=destination) {
            pnode->next = new PathNode(ret.path);
            ret = graph[ret.path];
            pnode = pnode->next;
    }
    return p;
    
    
}







void clean_distances(AdjacencyList graph[], int numvertices){
    for(int i = 0; i<= numvertices; i++){
        graph[i].distance=40000;
        graph[i].known = false;
    }
}


int find_min(AdjacencyList graph[], int numvertices){
    int dist = 40000;
    for(int i = 0; i<= numvertices; i++){
        if(graph[i].known==false){
        if (graph[i].distance<dist&&!(graph[i].known)) {
            dist = graph[i].distance;
        }
        }
    }
    return dist;
}

bool graph_finished(AdjacencyList graph[], int numvertices){
    for(int i = 0; i<= numvertices; i++){
        if(graph[i].known==false){
            return false;
        }
    }
    return true;
    
}


int vertex(AdjacencyList graph[], int numvertices, int distance){
    for(int i = 0; i<= numvertices; i++){
        if(graph[i].known==false){
            if (graph[i].distance==distance) {
                return i;
            }
        }
    }
    cout<<"you should not have gotten to the end of this function"<<endl;
    exit(1);
}


bool lookup(int * source, int num){
    for(int i = 1; i<=source[0];i++)
        if(source[i]==num)
            return true;
    return false;
}

