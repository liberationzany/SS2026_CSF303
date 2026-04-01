# Graph Algorithms Implementation Report

## 1. Overview
Implemented algorithms in separate source files:
- `floyd_warshall.cpp` (Floyd-Warshall shortest paths)
- `johnson.cpp` (Johnson all-pairs shortest paths)
- `baruvka.cpp` (Baruvka Minimum Spanning Tree)

Each program contains:
- Algorithm implementation
- Sample graph input
- Result output prints
- Brief final reflective note

---

## 2. Floyd-Warshall
- File: `floyd_warshall.cpp`
- Used for all-pairs shortest path on dense graphs with possible negative edge weights.
- Complexity: O(n^3).
- Behavior: computes distance matrix; sets self-distance 0; handles INF.

### Sample output
```
Floyd-Warshall result:
0 5 2 3
INF 0 3 4
INF INF 0 1
INF 1 -2 0
```

### Reflection
Floyd-Warshall uses dynamic programming with intermediate vertex relaxation (k-loop). It is simple and stable for small to medium graphs, but impractical for very large n due to cubic cost.

---

## 3. Johnson's Algorithm
- File: `johnson.cpp`
- Used for all-pairs shortest path on sparse graphs with negative edge weights (no negative cycles).
- Steps:
  1. Run Bellman-Ford via virtual source reweight to compute potential h[v].
  2. Reweight each edge w' = w + h[u] - h[v] (non-negative).
  3. Run Dijkstra from each source.
  4. Recover original distances.
- Complexity: O(n * (m log n)).

### Sample output
```
Johnson result:
0 5 2 4
INF 0 3 5
INF INF 0 2
INF 1 -2 0
```

### Reflection
Johnson is more efficient than Floyd-Warshall for sparse graphs, and its correctness relies on reweighting preserving shortest paths. Handles negative edges, and explicitly detects negative-weight cycles.

---

## 4. Baruvka's Algorithm
- File: `baruvka.cpp`
- Used for Minimum Spanning Tree on undirected weighted graph.
- Steps:
  1. Initialize each vertex as its own component in DSU.
  2. Repeatedly pick cheapest outgoing edge from each component.
  3. Merge components by selected edges until 1 component.
- Complexity: O(E log V) with union-by-rank/ path compression.

### Sample output
```
Baruvka MST cost: 19
Edges:
2 - 3
0 - 3
0 - 1
```

### Reflection
Baruvka is very parallel-friendly. It greedily contracts components in rounds and is conceptually related to Kruskal.

---

## 5. How to run
Compile each file and execute:
- `g++ -std=c++17 -O2 -o floyd_warshall floyd_warshall.cpp`
- `g++ -std=c++17 -O2 -o johnson johnson.cpp`
- `g++ -std=c++17 -O2 -o baruvka baruvka.cpp`

Then run:
- `.loyd_warshall.exe`
- `.\'johnson.exe`
- `.aruvka.exe`

---

## 6. Conclusion
All requested algorithms are implemented separately with tests and a final reflection. The report file documents behaviour, sample results, and chosen graph structures clearly.
