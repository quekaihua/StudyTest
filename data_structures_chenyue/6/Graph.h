#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef int WeightType;
typedef int DataType;
#define MaxVertexNum 100

typedef struct Gnode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef int Graph;    //图
typedef float Edge;   //边
typedef float Vertex; //顶点

Graph Create();
Graph InsertVertex(Graph G, Edge e);
Graph InsertEdge(Graph G, Edge e);
void DFS(Graph G, Vertex v);  //从顶点V出发深度优先遍历图G
/* 
void DFS(Vertex v)
{
	visited[v] = true;
	for (v的每个邻接点w)
		if(!visited[w])
			DFS(w);
}
*/
void BFS(Graph G, Vertex v);  //从顶点V出发宽度优先遍历图G
/*
   void BFS(Vertex V)
   {
	   visited[V] = true;
	   Enqueue(V, Q);
	   while(!IsEmpty(Q)){
		   V = Dequeue(Q);
		   for(V的每个邻接点W)
		      if(!visited[W]){
				  visited[W] = true;
				  Enqueue(W, Q);
			  }
	   }
   }

   void ListComponents(Graph G)
   {
	   for (each V in G)
	      if (!visited[V])
		      DFS(V);
   }
 */
void ShortestPath(Graph G, Vertex v, int Dist[]); //计算图G中顶点V到任意定点的最短距离
void MST(Graph G); //图G的最小生成树

#endif