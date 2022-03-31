#include <bits/stdc++.h>
using namespace std;

vector<int> caminho;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
int printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Nao encontrado\n";
        return 0;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // distance from source is in distance array
    //cout << "Distancia do caminho mais curto: "
         //<< dist[dest];

    // printing path from source to destination

    caminho=path;
    return 1;
}

vector<int> horas(int s, int c, int cam){
    vector<int> a;
    int dif=((c/100-s/100)*60+(c%100-s%100))/(cam);
    int aux=s;
    a.insert(a.begin(),s);
    for(int i=0;i<cam-1;i++){
        for(int j=0;j<dif;j++){
            aux++;
            if(aux%100==60){
                aux=aux-60+100;
            }
        }
        a.insert(a.begin(),aux);
    }
    a.insert(a.begin(),c);
    return a;
}


/*
void Graph::bfs(int v, int c)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados
	int aux=0;
	int cont=1;

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Comeca: " << lookup_station[v] << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visita " << cont << ": " << lookup_station[*it] << " ...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
				if(*it == c){
                    aux=1;
                    break;
				}
			}
		}
        cont++;
		// verifica se a fila NÃO está vazia
		if(!fila.empty() && aux==0)
		{
			v = fila.front(); // obtém o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

void Graph::proc(int v)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados
	int cont=0;

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Comeca: " << lookup_station[v] << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visita " << cont << ": " << lookup_station[*it] << " ...\n";
				cont++;
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
			}
		}

		// verifica se a fila NÃO está vazia
		if(!fila.empty())
		{
			v = fila.front(); // obtém o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

/*
// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);

    return 0;
}

/*

// Grafos - BFS (busca em largura)

#include <iostream>
#include <list>
#include <queue> // fila para usar na BFS

using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj;
	list<int> *peso; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2, int p); // adiciona uma aresta no grafo

	// faz uma BFS a partir de um vértice
	void bfs(int v, int c);
	int proc(int v,int c);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
	peso = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2, int p)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
	peso[v1].push_back(p);
}

void Grafo::bfs(int v,int c)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados
	int aux=0;
	int cont=1;

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << lookup_station[v] << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visita " << cont << ": " << lookup_station[*it] << " ...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
				if(*it == c){
                    aux=1;
                    break;
				}
			}
		}
        cont++;
		// verifica se a fila NÃO está vazia
		if(!fila.empty() && aux==0)
		{
			v = fila.front(); // obtém o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

int Grafo::proc(int v,int c)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
				if(*it == c){
                    break;
				}
			}
		}

		// verifica se a fila NÃO está vazia
		if(!fila.empty())
		{
			v = fila.front(); // obtém o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

/*
int main()
{
	int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);

	return 0;
}



// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << lookup_station[path[i]] << " - ";
        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}



*/
