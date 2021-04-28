#include<stdio.h>
#include<stdlib.h>
#define int long long

int min(int a,int b){
	if(a<b) return a;
	return b;
}

typedef struct EDGE EDGE;
typedef struct VERTEX VERTEX;
typedef struct GRAPH GRAPH;
typedef struct QUEUE QUEUE;
typedef struct qnode qnode;

//=========================================

struct EDGE {
	int y,c,f;
	struct EDGE *next;
};

struct VERTEX {
	int x, n; 		// x--> id of vertex , n-->need of vertex
	struct EDGE *p;
};

struct GRAPH {
	int V,E;
	VERTEX *H;
};


// ==========================================
struct qnode{
	int data;
	struct qnode *next;
};

struct QUEUE{
	qnode *head, *tail;
};

// functions for Queue
QUEUE* make_queue(){
	QUEUE* temp = (QUEUE*)malloc(sizeof(QUEUE));
	temp->head = temp->tail = NULL;
	return temp;
}

int isempty(QUEUE* q){
	if(q->head == NULL && q->tail==NULL) return 1;
	else return 0;
}

void enqueue(QUEUE* q, int val){
	
	qnode *temp = (qnode*)malloc(sizeof(qnode));
	temp->next = NULL;
	temp->data = val;
	
	// if empty
	if(isempty(q)){
		// printf("Case1\n");
		q->head = temp;
		q->tail = temp;
	}
	else{
		// printf("Case2\n");
		q->tail->next = temp;
		q->tail = temp;
	}
}

int dequeue(QUEUE* q){
	if(isempty(q)){
		printf("[Empty queue error]\n");
		return -1;
	}
	else if(q->head == q->tail){
		int val = q->head->data;
		q->head = q->tail = NULL;
		return val;
	}
	else{
		int val = q->head->data;
		q->head = q->head->next;
		return val;
	}
}

//=======================================

int bfs(GRAPH *G, int s, int t, int *parent, int** residual){
	// printf("\nbfs called, V=%lld, E=%lld\n", G->V, G->E);
	int V = G->V;
	int *mrc     = (int*)malloc((1+V)*sizeof(int));
	int *level   = (int*)malloc((1+V)*sizeof(int));
	int *visited = (int*)malloc((1+V)*sizeof(int));

	for(int i=0;i<=V;i++){
		visited[i] = 0;
		parent[i] = -1;
		mrc[i] = -1;     // mrc[i] --> maximum residual capacity of shortest path from s to i
		level[i] = 999999999;
	}

	QUEUE* q = make_queue();
	enqueue(q, s);

	mrc[s] = 1e9;
	level[s] = 0;
	parent[s] = s;

	while(!isempty(q)){
		int cur = dequeue(q);
		// printf("cur = %lld\n", cur);
		EDGE* temp = G->H[cur].p;

		while(temp){
			int nbr = temp->y;

			// printf("nbr = %lld\n",nbr);
			// printf("residual = %lld, level(nbr) = %lld, level(cur) = %lld\n", residual[cur][nbr], level[nbr], level[cur]);
			// if not visited and has residual capacity > 0 and is in different level
			if( residual[cur][nbr] > 0 && level[nbr]>level[cur] ){

				if(level[nbr] == 999999999){
					level[nbr] = 1+level[cur]; 
				}
				int m = min(mrc[cur], residual[cur][nbr]);
				if(m > mrc[nbr]){
					mrc[nbr] = m;
					parent[nbr] = cur;
				}
				if(!visited[nbr]) {
					enqueue(q, nbr);
					visited[nbr] = 1;
				}
			}
			temp = temp->next;
		}
	}
	// printf("mrc[t] = %lld\n", mrc[t]);
	if(mrc[t]!=-1) return mrc[t];
	return 0;
}


// functions for the given assignment

GRAPH* ReadGraph(char *fname){
	int n,m;
	// vertices are 1,2,...n

	// FILE *fptr;
	// fptr = fopen(fname, "r");

	// if(fptr==NULL){
	// 	printf("Wrong filename given\n");
	// 	exit(1);
	// }

	scanf("%lld%lld",&n,&m);

	GRAPH *input_graph = (GRAPH*)malloc(1*sizeof(GRAPH));
	input_graph->V = n;
	input_graph->E = m;
	input_graph->H = (VERTEX*)malloc((n+1)*sizeof(VERTEX));

	for(int i=1;i<=n;i++){
		// input_graph->H[i] gives access to the actual structure VERTEX
		// scanf("%lld", &(input_graph->H[i].n));
		input_graph->H[i].x = i;
		input_graph->H[i].p = NULL;
	}

	// last[i] -----> the pointer to last EDGE node in adjacency list of vertex i
	EDGE* last[1+n];
	for(int i=1;i<=n;i++) last[i] = NULL;

	for(int i=0;i<m;i++){
		int x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);

		// allocate a new EDGE and insert it in the adj list of vertex x
		EDGE* temp = (EDGE*)malloc(sizeof(EDGE));
		temp->y = y;
		temp->c = c;
		temp->f = 0;
		temp->next = NULL;

		if(last[x]==NULL){
			input_graph->H[x].p = temp;
			last[x] = temp;
		}
		else{
			last[x]->next = temp;
			last[x] = temp;
		}
	}

	return input_graph;
}

void PrintGraph(GRAPH G){
	for(int i=1;i<=G.V;i++){
		printf("%lld-> ", i);
		EDGE *temp = G.H[i].p;
		while(temp != NULL){
			if(temp->next == NULL) 
				printf("(%lld,%lld,%lld)",temp->y, temp->c, temp->f);
			else
				printf("(%lld,%lld,%lld)-> ",temp->y, temp->c, temp->f);
			temp = temp->next;
		}
		printf("\n");
	}
}

int ComputeMaxFlow(GRAPH *G, int s, int t){
	int maxflow=0, aug=0, V = G->V;
	int *parent = (int*) malloc(V*sizeof(int));
	
	int **residual = (int**) malloc((V+1)*sizeof(int*));
	for(int i=0;i<=V;i++){
		residual[i] = (int*)malloc((V+1)*sizeof(int));
		for(int j=0;j<=V;j++) residual[i][j] = 0;
	}

	// printf("\n\nComputeMaxFlow called\n");
	// printf("s=%lld, t=%lld\n", s, t);
	// printf("V=%lld, E=%lld\n", G->V, G->E);
	

	// initialise residual matrix from the graph
	for(int i=1;i<=V;i++){
		VERTEX u = G->H[i];
		EDGE* temp = u.p;
		while(temp){
			// printf("[ i=%lld, u.x=%lld]\n", i, u.x); 	
			residual[u.x][temp->y] += temp->c;
			temp = temp->next;
		}
	}

	// for(int i=0;i<=V;i++){
	// 	for(int j=0;j<=V;j++){
	// 		printf("%lld ", residual[i][j]);
	// 	}
	// 	printf("\n");
	// }



	while(aug = bfs(G,s,t,parent,residual)){
		// printf("aug = %lld\n", aug);
		// here aug is the residual capacity of an augmenting path from s to t
		maxflow += aug;
		int cur = t;
		// printf("path : %lld, ", t);

		while(cur != s){
			int prev = parent[cur];
			// printf("%lld, ", prev);
			// update the residual capacity in the matrix
			residual[prev][cur] -= aug;
			residual[cur][prev] += aug;
			cur = prev;
		}
		// printf("\n");
	}


	// now no more augmenting paths are found
	// copy back the data from matrix to GRAPH

	for(int i=1;i<=V;i++){
		VERTEX u = G->H[i];
		EDGE *temp = u.p;
		while(temp){
			temp->f = temp->c - residual[u.x][temp->y];
			temp = temp->next;
		}
	}

	return maxflow;
}


signed main(){

	char *S = (char*) malloc(20*sizeof(char));
	// printf("Enter the input filename : ");
	// scanf("%s",S);

	GRAPH *my_graph = ReadGraph(S);
	// printf("The input graph is :-\n");
	// PrintGraph(*my_graph);

	int s=1,t=my_graph->V;
	// printf("\nEnter the id's for source verticex : ");
	// scanf("%lld",&s);
	// printf("Enter the id's for sink verticex : ");
	// scanf("%lld",&t);

	int f = ComputeMaxFlow(my_graph, s, t);
	printf("%lld\n", f);
	// printf("\nAfter computing max flow the graph is :-\n");
	// PrintGraph(*my_graph);
	// printf("Max flow : %lld\n",f);



	return 0;
}