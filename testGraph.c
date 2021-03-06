/*
 * Tests for functions in Graph.h
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

Graph mkTestGraph(int graphNum);

int main (int argc, char * argv[]) {
  printf("Blackbox tests...\n");

  printf("Test 1: newGraph...");
  //empty graph
  Graph g1a = mkTestGraph(0);
  destroyGraph(g1a);
  //single graph
  Graph g1b = mkTestGraph(1);
  destroyGraph(g1b);
  printf("Passed!\n");

  printf("Test 1a: mkEdge...");
  //zero cost edge
  Edge e1a = mkEdge(0, 1, 0);
  assert(e1a.v == 0);
  assert(e1a.w == 1);
  assert(e1a.weight == 0);
  Edge e1ar = mkEdge(1, 0, 0);
  assert(e1ar.v == 1);
  assert(e1ar.w == 0);
  assert(e1ar.weight == 0);
  //edge
  Edge e1b = mkEdge(1, 5, 10);
  assert(e1b.v == 1);
  assert(e1b.w == 5);
  assert(e1b.weight == 10);
  Edge e1br = mkEdge(5, 1, 10);
  assert(e1br.v == 5);
  assert(e1br.w == 1);
  assert(e1br.weight == 10);
  printf("Passed!\n");
  
  printf("Test 2: insertE...");
  //double graph
  Graph g2 = mkTestGraph(2);
  Edge e2 = mkEdge(0, 1, 12);
  insertE(g2, e2);
  assert(numE(g2) == 1);
  destroyGraph(g2);
  printf("Passed!\n");

  printf("Test 3: isAdjacent...");
  //double graph
  Graph g3a = mkTestGraph(2);
  Edge e3a = {0, 1, 12};
  insertE(g3a, e3a);
  assert(numV(g3a) == 2);
  assert(numE(g3a) == 1);
  assert(isAdjacent(g3a, 0, 1) == 1);
  assert(isAdjacent(g3a, 1, 0) == 1);
  destroyGraph(g3a);

  //graph
  Graph g3b = mkTestGraph(3);
  assert(isAdjacent(g3b, 0, 1) == 1);
  assert(isAdjacent(g3b, 0, 2) == 1);
  assert(isAdjacent(g3b, 0, 3) == 1);
  assert(isAdjacent(g3b, 0, 4) == 1);
  assert(isAdjacent(g3b, 1, 2) == 1);
  assert(isAdjacent(g3b, 2, 3) == 1);
  assert(isAdjacent(g3b, 3, 4) == 1);
  destroyGraph(g3b);
  printf("Passed!\n");

  printf("Test 4: adjacentVertices...");
  Graph g4a = mkTestGraph(2);
  Edge e4a = {0, 1, 12};
  insertE(g4a, e4a);
  Vertex adj4a[2]; //allocate space for max number of vertices
  assert(adjacentVertices(g4a, 0, adj4a) == 1);
  assert(adj4a[0] >= 0);
  assert(adjacentVertices(g4a, 1, adj4a) == 1);
  assert(adj4a[0] >= 0);
  destroyGraph(g4a);
  printf("Passed!\n");

  printf("Test 5: incidentEdges...");
  Graph g5 = mkTestGraph(2);
  Edge e5 = {0, 1, 12};
  insertE(g5, e5);
  Edge edges5[1]; //allocate space for max num of edges
  assert(incidentEdges(g5, 0, edges5) == 1);
  int v5 = edges5[0].v; int w5 = edges5[0].w;
  assert( (v5 == 0 && w5 == 1) || (v5 == 1 && w5 == 0) );
  assert(edges5[0].weight == 12);
  assert(incidentEdges(g5, 1, edges5) == 1);
  v5 = edges5[0].v; w5 = edges5[0].w;
  assert( (v5 == 0 && w5 == 1) || (v5 == 1 && w5 == 0) );
  assert(edges5[0].weight == 12);
  destroyGraph(g5);
  printf("Passed!\n");

  printf("Test 6: edges...");
  Graph g6 = mkTestGraph(2);
  Edge e6 = {0, 1, 12};
  insertE(g6, e6);
  Edge es6[1]; //allocate space for max num of edges
  assert(edges(es6, 1, g6) == 1);
  int v6 = es6[0].v; int w6 = es6[0].w;
  assert( (v6 == 0 && w6 == 1) || (v6 == 1 && w6 == 0) );
  assert(es6[0].weight == 12);
  destroyGraph(g6);
  printf("Passed!\n");

  printf("All Test Passed! You are a Beast!\n");
  
  return EXIT_SUCCESS;
}

Graph mkTestGraph(int graphNum) {
  Graph g = NULL;
  if (graphNum == 0) {
    g = newGraph(0);
    assert(numV(g) == 0);
    assert(numE(g) == 0);  
  } else if (graphNum == 1) {
    g = newGraph(1);
    assert(numV(g) == 1);
    assert(numE(g) == 0);
  } else if (graphNum == 2) {
    g = newGraph(2);
    assert(numV(g) == 2);
    assert(numE(g) == 0);
  } else if (graphNum == 3) {
    g = newGraph(5);
    Edge e301 = mkEdge(0, 1, 7);
    Edge e302 = mkEdge(0, 2, 6);
    Edge e303 = mkEdge(0, 3, 5);
    Edge e304 = mkEdge(0, 4, 4);
    Edge e312 = mkEdge(1, 2, 3);
    Edge e323 = mkEdge(2, 3, 2);
    Edge e334 = mkEdge(3, 4, 1);
    insertE(g, e301);
    insertE(g, e302);
    insertE(g, e303);
    insertE(g, e304);
    insertE(g, e312);
    insertE(g, e323);
    insertE(g, e334);
    assert(numV(g) == 5);
    assert(numE(g) == 7);   
  }
  return g;
}
