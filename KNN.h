#include "graph.h"
#include"node.h"

class knn{
	public:
	int k;
    int d[4];
    int r[4];
    void sort(int *a);
	void formatcluster(graph *a1,graph a);
	int distancefuc(graph b,graph a);
	void testKNNfuc(graph *a,graph v);
	void printstates();
};
