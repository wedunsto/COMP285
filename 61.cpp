#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

class Edge
{
public:
	char source_;
	char dest_;
	int weight_;

	Edge(char source, char dest, int weight) : source_(source), dest_(dest), weight_(weight) {}
};

class NodeDist
{
public:
	char node_;
	int dist_;
	char parent_;
	NodeDist(char node, int dist, char parent) : node_(node), dist_(dist), parent_(parent) {}
};

bool operator<(const NodeDist &e1, const NodeDist &e2)
{
	return e1.dist_ > e2.dist_;
}

class Graph
{

public:
	Graph(int num_nodes) { num_nodes_ = num_nodes; }
	std::map<char, std::list<Edge> > adj_list;
	int num_nodes_;

	void addEdge(Edge e)
	{
		adj_list[e.source_].push_back(e);
	}
	void printGraph()
	{
		std::map<char, std::list<Edge> >::iterator it = adj_list.begin();
		while (it != adj_list.end())
		{
			printEdgesOfVertex(it);
			it++;
		}
	}
	void printEdgesOfVertex(const std::map<char, std::list<Edge> >::iterator &it)
	{
		std::cout << it->first << "-->";
		for (std::_List_iterator<Edge> list_it = it->second.begin(); list_it != it->second.end(); ++list_it)
			std::cout << ' ' << list_it->dest_ << "{" << list_it->weight_ << "}";
		std::cout << std::endl;
	}

	void printEdge(Edge e)
	{
		std::cout << e.source_ << "-->" << e.dest_ << "{" << e.weight_ << "}" << std::endl;
	}

	void dijkstraFromA()
	{
		std::priority_queue<NodeDist> pq;
		std::set<char> visited;
		std::map<char, std::string> pathMap;
		std::map<char, int> pathCost;
		visited.insert('A');
		pathMap.insert({'A', "A"});
		pathCost.insert({'A', 0});
		//cout << "hi" << std::endl;
		addNodesToPq(pq, 'A', 0);
		std::string path;

		while (!pq.empty() && visited.size() < num_nodes_)
		{
			//cout << "hi";
			NodeDist nd = pq.top();
			//printEdge(e);
			pq.pop();
			if (visited.find(nd.node_) == visited.end())
			{
				pathMap.insert({nd.node_, pathMap[nd.parent_] + nd.node_});
				pathCost.insert({nd.node_, nd.dist_});
				addNodesToPq(pq, nd.node_, nd.dist_);
				visited.insert(nd.node_);
			}
		}
		writePathAndCost(pathMap, pathCost);
	}

	void writePathAndCost(std::map<char, std::string> &pathMap, std::map<char, int> &pathCost)
	{
		ofstream myfile;
		myfile.open("result.txt");
		for (int i = 1; i < num_nodes_; i++)
		{
			char dest = 'A' + i;
			myfile << "Shortest path from A to " << dest << " is: " << pathCost.find(dest)->second << std::endl;
			myfile << "Path taken: " << pathMap.find(dest)->second << std::endl;
		}
		myfile.close();
	}

	void addNodesToPq(std::priority_queue<NodeDist> &pq, char source, int sourceDist)
	{
		//cout << "hi";
		if (adj_list.find(source) != adj_list.end())
		{
			for (std::_List_iterator<Edge> list_it = adj_list.find(source)->second.begin(); list_it != adj_list.find(source)->second.end(); ++list_it)
			{

				pq.push(NodeDist(list_it->dest_, sourceDist + list_it->weight_, source));
			}
		}
	}
};

int main()
{
	ifstream myReadFile;
	myReadFile.open("graph.txt");
	std::string next_line;
	int num_nodes = 0;
	if (std::getline(myReadFile, next_line))
	{
		std::istringstream iss(next_line);
		iss >> num_nodes;
	}

	if (num_nodes == 0)
		return 0;

	char source = 'A';
	Graph g(num_nodes);
	while (std::getline(myReadFile, next_line))
	{
		std::istringstream iss(next_line);
		int temp;
		char dest = source;
		while (iss >> temp)
		{

			dest++;
			if (temp != 0)
			{
				g.addEdge(Edge(source, dest, temp));
				g.addEdge(Edge(dest, source, temp));
			}
		}
		source++;
	}

	myReadFile.close();
	g.printGraph();
	g.dijkstraFromA();
	return 0;
}
