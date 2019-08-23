#include <iostream>
#define vertex 4 
#define source 0

using namespace std;

struct node {
	int vno;
	int d;
	int pi;
	node(int v, int dv, int pin) : vno(v), d(dv), pi(pin) {}
};


int main() {

	int gr[vertex][vertex] = {{0,1,0,5}, {1,0,3,1}, {0,3,0,1 }, {5,1,1,0}};
	//int d[vertex], pi[vertex];

	init();
	auto comparator = [](const node & n1, const node & n2)->bool { return n1.d > n2.d; };
	std::priority_queue<node, vector<node>, comparator> q;
	for(int i=0; i< vertex; ++i) {
		if(i==0)
			q.push(node(i,0, -1));
		else
		q.push(node(i,INT_MAX, -1));
	}


	while(!q.empty()) {

		auto & vertex_min = q.front();
		
		for(int i=0; i < vertex; ++i) {
			if(vertex_min.vno != i && gr[vertex_min.vno][i] == 1) //adjacent vertex
				if(ob[i].d > vertex_min.d + gr[vertex_min.vno][i])
					ob[i].d = vertex_min.d + gr[vertex_min][i];
		}
		q.pop();


	} 




	return 0;
}