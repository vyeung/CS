import java.util.*;
import java.io.*;

// This Vertex class allows us to pair vertex IDs and distance values so they
// can be plunked into a minheap.
class Vertex implements Comparable<Vertex>
{
	int id, dist;

	Vertex(int id, int dist)
	{
		this.id = id;
		this.dist = dist;
	}

	public int compareTo(Vertex v)
	{
		return this.dist - v.dist;
	}

	public String toString()
	{
		return "Vertex " + (char)(this.id + 'A') + ": " + this.dist;
	}
}

public class WeightedGraph
{
	static final int oo = Integer.MAX_VALUE;
	private int [][] matrix;

	// Initialize 'matrix' from input file.
	public WeightedGraph(String filename) throws Exception
	{
		Scanner in = new Scanner(new File(filename));
		int N = in.nextInt();
		
		matrix = new int[N][N];
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				matrix[i][j] = in.nextInt();
	}

	// Prints the length of the shortest path from 'source' to each other vertex
	// in the graph. Assumes non-negative edge weights.
	void Dijkstra(int source)
	{
		int [] dist = new int[matrix.length];
		boolean [] visited = new boolean[matrix.length];
		int visitedVertices = 0;

		// Java's PriorityQueue container is essentially a minheap.
		PriorityQueue<Vertex> heapyheap = new PriorityQueue<Vertex>();

		Arrays.fill(dist, oo);
		dist[source] = 0;

		for (int i = 0; i < matrix.length; i++)
			heapyheap.add(new Vertex(i, dist[i]));

		while (!heapyheap.isEmpty() && visitedVertices < matrix.length)
		{
			// Find the vertex with the smallest distance associated with it.
			Vertex v = heapyheap.remove();
			if (visited[v.id]) continue;

			visited[v.id] = true;
			System.out.println(v);

			for (int i = 0; i < matrix.length; i++)
			{
				if (matrix[v.id][i] > 0 && !visited[i] && dist[v.id] + matrix[v.id][i] < dist[i])
				{
					dist[i] = dist[v.id] + matrix[v.id][i];
					heapyheap.add(new Vertex(i, dist[i]));
				}
			}
		}
	}

	public static void main(String [] args) throws Exception
	{
		WeightedGraph graph = new WeightedGraph("dijkstra-graph.txt");
		graph.Dijkstra(0);
	}
}
