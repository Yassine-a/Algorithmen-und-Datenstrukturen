#include "Graph.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <queue>


std::priority_queue<GraphNode::edge *, std::vector<GraphNode::edge *>, GraphNode::edge> edgesQueue;



Graph::~Graph() {
    for (auto &_node : _nodes)
        delete _node;
}

bool Graph::init( std::string path) {
    std::ifstream file;
    file.open(path, std::ios_base::in);
    if (!file) {
        std::cout << "File is not avaiable or corrupt." << std::endl;
        return false;
    } else {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);

        iss >> _anzKnoten; //Erste Zeile Auslesen

		// Create and place the needed number of nodes
        for (int i = 0; i < _anzKnoten; i++) {
            GraphNode *newNode = new GraphNode{i};
            _nodes.push_back(newNode);
        }
		
		// Create the edges and connect them to the already created nodes
        while (std::getline(file, line)) {
            std::istringstream edgeLine{line};
            int startKnotenKey;
            int zielKnotenKey;
            int gewicht;
			//Read from the file and write to the var
            edgeLine >> startKnotenKey >> zielKnotenKey >> gewicht;
            GraphNode *startKnoten = GetNodeByKey(startKnotenKey);
            GraphNode *zielKnoten = GetNodeByKey(zielKnotenKey);
            // the way in
            GraphNode::edge edge{startKnoten, zielKnoten, gewicht};
            startKnoten->addEdge(edge);
			// the way back
            edge = {zielKnoten, startKnoten, gewicht}; // changed the order from B to A
            zielKnoten->addEdge(edge);
        }
        return true;
    }
}

bool Graph::printAll() {
    for (auto &_node : _nodes) {
        std::cout << std::setw(3) << _node->getKey() << std::setw(5);
        for (int j = 0; j < _node->getNumberOfEdges(); ++j) {
            std::cout << " -> " << std::setw(2) << _node->getEdge(j)->zielKnoten->getKey() << '{'
                      << std::setw(2) << _node->getEdge(j)->gewicht << '}';
        }
        std::cout << std::endl;
    }
    return true;
}

// can run on undirected or directed graph znd we ignore amy weights
bool Graph::depthSearchRek(int startKey) {
    setAllUnvisited();
    std::cout << "{ ";
    startDepthSearchRek(GetNodeByKey(startKey));
    std::cout << "}" << std::endl;
    return checkVisited();
}

// use the stairways
void Graph::startDepthSearchRek(GraphNode *node) {
    node->setVisited(true);
    std::cout << node->getKey() << ' ';
    for (int i = 0; i < node->getNumberOfEdges(); ++i) {
        if (!node->getEdge(i)->zielKnoten->getVisited())
            startDepthSearchRek(node->getEdge(i)->zielKnoten);
    }
}

bool Graph::breadthSearchIter(int startKey) {


    setAllUnvisited();

    std::queue<GraphNode *> nodesQueue;
    nodesQueue.push(GetNodeByKey(startKey));

    std::cout << "{ ";


    while (!nodesQueue.empty()) {

        GraphNode *frontNode = nodesQueue.front();

		if (!frontNode->getVisited())
			std::cout << frontNode->getKey() << ' ';

        frontNode->setVisited(true);
        nodesQueue.pop();

        for (int i = 0; i < frontNode->getNumberOfEdges(); ++i) {
            if (!frontNode->getEdge(i)->zielKnoten->getVisited())
                nodesQueue.push(frontNode->getEdge(i)->zielKnoten);
        }

    }
    std::cout << "}" << std::endl;
    return checkVisited();
}

// Ausgehend von er Knote
double Graph::prim(int startKey) {
    setAllUnvisited();
    double mstKosten = 0;


    GraphNode *startKnoten = GetNodeByKey(startKey);

	// Lade alle Nachbarn-Edges vom Startnode in die Warteschlange -> Results in the smallest edge will be sorted as the first element
	for (int i = 0; i < startKnoten->getNumberOfEdges(); ++i)
	{
		edgesQueue.push(startKnoten->getEdge(i));
	}
	
	startKnoten->setVisited(true);

    while (!edgesQueue.empty()) {
        GraphNode::edge *topEdge = edgesQueue.top();
        edgesQueue.pop();

        if (!topEdge->zielKnoten->getVisited()) {
            for (int i = 0; i < topEdge->zielKnoten->getNumberOfEdges(); ++i) {
                if (!topEdge->zielKnoten->getEdge(i)->zielKnoten->getVisited())
                    edgesQueue.push(topEdge->zielKnoten->getEdge(i));
            }
            topEdge->zielKnoten->setVisited(true);
            printEdge(topEdge);
            mstKosten += topEdge->gewicht;
        }
    }
    std::cout << "MST Costs : " << mstKosten << std::endl;
    return mstKosten;
}


// Sort the edges in pQ and connect the edges while making sure that there is no circle
double Graph::kruskal() {
    double mstKosten = 0;
    std::queue<GraphNode::edge *> mstEdges; // MST-Kanten


	// Pq Priority Queue , Sorted Kanten uber gewicht (klein ... gross)
    for (int i = 0; i < _anzKnoten; i++) {
        _nodes[i]->setComponent(i);
        for (int j = 0; j < _nodes[i]->getNumberOfEdges(); ++j)
            edgesQueue.push(_nodes[i]->getEdge(j));
    }



    while (!edgesQueue.empty() && mstEdges.size() < _anzKnoten - 1) {
		//take the smallest edge from the queue
        GraphNode::edge *topEdge = edgesQueue.top();
        edgesQueue.pop();
        GraphNode *v = topEdge->startKnoten;
        GraphNode *w = topEdge->zielKnoten;

		//make sure there will be no cycles, component variable will take care of that, so that at the end all _node.component will have the same # 
        if (v->getComponent() != w->getComponent()) {

            mstKosten += topEdge->gewicht;
            printEdge(topEdge);
            mstEdges.push(topEdge);

            int w_Component = w->getComponent();

            for (auto &_node : _nodes)
                if (_node->getComponent() == w_Component) 
                    _node->setComponent(v->getComponent()); // I got you
        }

    }
    std::cout << "MST Costs : " << mstKosten << std::endl;
    return mstKosten;
}


int Graph::getAnzKnoten() const {
    return _anzKnoten;
}

GraphNode *Graph::GetNodeByKey(int key) {
    for (auto &_node : _nodes)
        if (_node->getKey() == key) return _node;
    return nullptr;
}

void Graph::setAllUnvisited() {
    for (auto &_node : _nodes)
        _node->setVisited(false);
}

bool Graph::checkVisited() {
    for (auto &_node : _nodes)
        if (!_node->getVisited()) return false;
    return true;
}

bool Graph::testChildComponent(GraphNode *node) {
    return true;
}
