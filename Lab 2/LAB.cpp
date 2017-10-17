#include <string>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct AdjListNode
{
    int dest; //destination int
    int weight;
    AdjListNode* next;
};
 

struct AdjList
{
    AdjListNode *front;
};
 

class theGraph
{
    private:

        int node;
        int weight;



        queue<int> theList;


        struct AdjList* array; //our Array

    public:
       
    	queue<int> q; //for BFS

		bool visited [] ;

        theGraph(int node) //size 
        {
            this->node = node;

            array = new AdjList [node]; //set size to Adjacent List

            for (int i = 0; i < node; ++i)

                array[i].front = NULL;
        }
       
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;

            newNode->dest = dest;
            newNode->next = NULL;

            return newNode;
        }
        
        void addEdge(int src, int dest, int weight)
        {
        //	this->weight = weight;

        	theList.push(weight);

        
            AdjListNode* newNode = newAdjListNode(dest);

            newNode->weight = weight;
            newNode->next = array[src].front;
            array[src].front = newNode;


            newNode = newAdjListNode(src);
            newNode->next = array[dest].front;
            array[dest].front = newNode;

        }
        
        void printGraph()
        {
            int v;

            for (v = 0; v < node; ++v)
            {
                AdjListNode* output = array[v].front;

               cout << "\n Vertex " << v <<  "\nFront to Edge " ;

                while (output)
                {
                    cout << "->----- "<< output->dest ;

                    output = output->next; 
                }

                cout<<endl;
            }
        }


 void BFS(int search){

bool *visited = new bool[node];
	
	for (int i = 0; i < node; ++i)
	{
		visited[i] = false;

		}

		list<int> theQ;

		visited[search] = true;

		theQ.push_back(search);


cout << "---------BFS Starting at " <<  search << " --------- \n" <<  endl;

		while(!theQ.empty()){

				search = theQ.front();

				cout << search << " " << "\n";

				theQ.pop_front();

				for ( int j = 0; j < node; ++j)
				{
					if (!visited[j])
					{
						visited[j] = true;
						theQ.push_back(j);
					}
				}
		}
 }



void prims(int theG[3][3]){

	 int parent[node]; 
     int key[node];   
     bool mstSet[node];  
 
     for (int i = 0; i < node; i++){

        key[i] = node;
        mstSet[i] = false;
        key[0] = 0;     
        parent[0] = -1; 
 
    }
     
     for (int count = 0; count < node ; count++)
     {
        int u = min(key, mstSet);  
        mstSet[u] = true;
 
        for (int v = 0; v < node; v++){

          if (theG[u][v] && mstSet[v] == false && theG[u][v] <  key[v]){

             parent[v]  = u, key[v] = theG[u][v];

         }
        }
     }

     printMST(parent, node, theG);
 
}


int min(int ourK[], bool backTrack[]){ //least val in graph

    int min = 10, min_index;

    for (int i = 0; i < node; i++)
    {
        if (backTrack[i] == false && ourK[i] <= min)
        {
            min = ourK[i],
            min_index = i;

        }
    }

    return min_index;
}

int printMST(int parent[], int n, int graph[3][3])  ///MST output
{
   printf("Weight\n");   

   for (int i = 1; i < node ; i++){

        cout << parent[i] << endl;
   }

}


///////////////DIJKSTRAS ////////////////

void dij(int G[3][3], int startPoint){ //PATH AND WEIGHT ERRORS ?????

    int visited[node]; //VISITED ARRAY

    bool unVisited[node]; //NOT VISITED 

    for (int i = 0; i < node; i++)
    {
         visited[i] = node; 

         unVisited[i] = false;

    }

        visited[startPoint]; //START 

        for (int j = 0; j < node - 1 ; j++)
        {
           int distanceBetween = min(visited,unVisited); //store distance

           unVisited[distanceBetween] = true; //TRAVERSE


           for (int k = 0; k < node; k++)
           {
               if (!unVisited[k] && G[j][k] && visited[distanceBetween] != 10
                && visited[distanceBetween] + G[distanceBetween][k] < visited[k])
               {
                   
                   visited[k] = visited[distanceBetween] + G[distanceBetween][k];
               }
           }
        }

        theD(visited,node); //ERROR with Visited List
}



int theD(int visited[], int k){

    printf("Vertex              Distance\n");
   for (int i = 0; i < node; i++){

      printf("%d \t\t %d\n", i, visited[i]); ///VISITED DATA not right

  }
}

};





int main(int argc, char const *argv[])
{
	
	theGraph ourGraph(7); //graph size set
	ourGraph.addEdge(0, 1, 8);
    ourGraph.addEdge(0, 3, 3);
    ourGraph.addEdge(1, 2, 15);
    ourGraph.addEdge(1, 3, 2);
    ourGraph.addEdge(1, 4, 1);
    ourGraph.addEdge(4, 2, 1);
    ourGraph.addEdge(3, 6, 1);
    ///SOURCES


    ourGraph.BFS(1); ///BFS
    ourGraph.BFS(3);


    cout << "----------------GRAPH OUTLINE----------------" << endl;
    ourGraph.printGraph(); 
                            //print out normal graph without 2d array 


   //////////////// GRAPH 2D ///////////////
    cout << "--------------PRIMS---------------" << endl;

    int myGraph[3][3] = {{0,2,3}, //GRAPH FOR PRIMS AND DIJK
                         {1,0,2}, 
                         {3,1,3}}
                         ;

    ourGraph.prims(myGraph);


    cout << "---------------DIJKSTRAS-----------------" << endl;

    ourGraph.dij(myGraph,3);


	

	return 0;
}




