# Graphs

## Key Terms
- Path - leads from node a to node b through the edges
- Length - number of edges ina  path
- Cycle - a path is a cycle if first node = last node
- Simple (path) - if each node appears at most once in the path
- Connected - if there is a path between two nodes
- Components - the connected parts of a graph (a graph with 3 components has 3 groups of connected nodes)
- Directed - edges are directed if they can only be traversed in 1 direction
    - Edges can also be assigned weights
    - Indegree - number of edges that end (come 'into' the node)
    - Outdegree - number of edges that start at node
- Neighbours / adjacent - if there is an edge between two nodes
- Degree - the number of neighbours a node has
    - Sum of degrees is 2m (m = number of edges), always even
- Regular - degree of every node is d
- Complete - degree of every node is n-1 (ie. all possible connections)
- Simple - if no edge starts and ends at the same node and no multiple edges between two nodes

### Colouring
- Colouring - each node assigned a colour such that no adjacent nodes have the same
- Bipartite - if possible to colour using two colours
    - This is the case if it does not contain a cycle with an odd number of edges

## Representation
### Adjacency list
- Each node is assigned an 'adjacency list' of nodes to which there is an edge from x
- Undirected graphs - edge added in both directions
- Weighted graphs - `cpp vector<pair<int, int>> adj[N]`
    - First int - node connected to, second int - weight

### Adjacency matrix
- 2D array to indicate which edges the graph contains
- int adj[N][N] - where adj[a][b] = 0 or 1 or the weight of the edge from node a to node b

### Edge list representation
- Contains all the edges of a graph in some order - `vector<pair<int, int>> edges`
    - pair (a, b) denotes that there is an edge from a to b
    - if weighted, can use a third int in `tuple<int, int, int>` representing the weight

## DFS
- Uses recursion
    - Generally, maintain an array of visited nodes
    - Turn value of visited[s] into true
    - Recurse on child nodes

## BFS
- Have a queue
    - When visiting a node, add childs to the queue
    - Process the next node in the queue

## Applications
### Check connectivity
- Start at arbitrary nodes and find out if we can reach all others

### Find cycles
- Find a node with a neighbour (other than the one just visited) has already been visited
- Graphs with no cycles have c-1 edges and c nodes

## Bipartiteness check
- Colour starting node blue, and all neighbours red, then all the red neighbours blue
- If you reach a contradiction - not bipartite, otherwise, it is

## Invariants
*using example of counting rooms*
1. Unvisited (white) - something we haven't reached
2. Frontier (grey) - this is in the queue
3. Fully explored (black) - already popped from queue, all 4 neighbours checked or enqueued