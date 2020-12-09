// 18300229_Graphs.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include "Integrador.h"
using namespace std;

struct graphNode
{
	int nodeKey;
	graphNode* link;
	graphNode* following;
	graphNode()
	{
		nodeKey = 0;
		following = nullptr;
		link = nullptr;
	}
};

class graphListing
{
public:

	graphNode* beginning;
	graphNode* ending;

	void graphEnqueue(int nodeKey, graphNode* createD_List)
	{
		graphNode* cursor;
		graphNode* temp = new graphNode;
		temp->nodeKey = nodeKey;
		ending = temp;
		if (!beginning)
			beginning = temp;
		else
		{
			cursor = beginning;
			while (cursor->following != nullptr)
				cursor = cursor->following;
			cursor->following = temp;
		}
		temp->link = createD_List;
	}

	graphNode* graphDequeue()
	{
		graphNode* aux = beginning;
		if (beginning)
		{
			beginning = beginning->following;
			if (beginning)
			{
				ending = nullptr;
			}
			return aux;
		}
	}

	graphListing()
	{
		beginning = nullptr;
		ending = nullptr;
	}
};

graphNode* graphFind(graphNode* beginning, int nodeKey)
{
	graphNode* aux = beginning;

	while (aux)
	{
		if (aux->nodeKey == nodeKey)
			return aux;
		aux = aux->following;
	}

	return nullptr;
}

void graphPath(graphListing c_path, graphListing* c_route)
{
	graphNode* points = c_path.ending;
	graphListing temp;
	while (points)
	{
		temp.graphEnqueue(points->nodeKey, nullptr);
		points = points->link;
	}
	c_route->graphEnqueue(1, temp.beginning);
}

graphNode* graphSearch(graphListing list, int origin, int destiny)
{
	graphListing waitList,
		path,
		route;
	graphNode* temp,
		* derv;

	bool bigger = false;

	if (origin > destiny)
		bigger = true;

	waitList.graphEnqueue(origin, nullptr);

	while (1)
	{
		temp = waitList.graphDequeue();

		if (temp == nullptr || temp->nodeKey == 0)
			break;

		path.graphEnqueue(temp->nodeKey, temp->link);
		if (path.ending->nodeKey == destiny)
		{
			graphPath(path, &route);
		}

		derv = graphFind(list.beginning, temp->nodeKey);
		derv = derv->link;

		while (derv)
		{
			if (bigger == false)
			{
				if (derv->nodeKey > temp->nodeKey)
					waitList.graphEnqueue(derv->nodeKey, path.ending);
			}
			else
			{
				if (derv->nodeKey < temp->nodeKey)
					waitList.graphEnqueue(derv->nodeKey, path.ending);
			}
			derv = derv->following;
		}
	}
	return route.beginning;
}

void routeShow(graphNode* temp)
{
	while (temp)

	{
		cout << "[" << temp->nodeKey << "]" << " -> ";
		temp = temp->following;
	}

	cout << endl;
}

int graphs()
{
	graphListing userGraph;
	graphNode* routes,
		* aux,
		* routeAux;
	char choice = 0;
	int amount = 0,
		origin = 0,
		destination = 0;

	cout << "Graphs Algorithm" << endl;

	cout << "Enter amount of nodes: "; cin >> amount;
	cout << "Enter 'n' for no. " << endl;
	cout << "Enter 'y' for yes, " << endl << endl;

	for (int o = 1; o <= amount; o++)
	{
		cout << "Is node [" << o << "]" << endl;
		graphListing aux_temp;

		for (int i = 1; i <= amount; i++)
		{
			if (i != o)
			{
				cout << "linked with node [" << i << "]?" << endl;

				while (choice != 'y' and choice != 'n')
				{
					cout << ">Answer: ";
					cin >> choice;
				}

				if (choice == 'y')
					aux_temp.graphEnqueue(i, nullptr);

				choice = 0;
			}
		}
		userGraph.graphEnqueue(o, aux_temp.beginning);
		cout << endl;
	}
	system("cls");

	choice = 0;
	do
	{
		cout << "Set origin node: "; cin >> origin;
	} while (!graphFind(userGraph.beginning, origin));

	do
	{
		cout << "Set destination node: ";
		cin >> destination;
	} while (!graphFind(userGraph.beginning, destination));

	cout << "Enter 'n' for no. " << endl;
	cout << "Enter 'y' for yes, " << endl << endl;

	routes = graphSearch(userGraph, origin, destination);

	while (routes)
	{
		routeAux = routes->link;
		routeShow(routeAux);
		routes = routes->following;
		cout << "See more routes?" << endl;
		while (choice != 'y' and choice != 'n')
		{
			cout << ">Answer: ";
			cin >> choice;
			cout << endl;
		}
		if (choice == 'n')
		{
			cout << "Thank you for using the program." << endl;
			return 0;
		}
	}
	cout << endl << "No more available routes." << endl;

	cout << "Thank you for using the program." << endl;
	return 0;
}