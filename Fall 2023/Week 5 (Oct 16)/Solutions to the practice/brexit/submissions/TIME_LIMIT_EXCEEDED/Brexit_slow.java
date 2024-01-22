import java.io.*;
import java.util.*;
import java.math.*;

public class Brexit_slow {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public Brexit_slow() {}

	public static void main(String[] args) throws Exception {
		new Brexit_slow().doProblem();
	}

	public static void out(Object o, boolean newline) {
		if (newline) System.out.println(o.toString());
		else System.out.print(o.toString());
		System.out.flush();
	}

	public static void out(Object o) {
		out(o, true);
	}

	public void doProblem() throws Exception {
		solve();
	}

	public void solve() throws Exception {
		while(true) {
			graph g = read_graph();
			if (g == null) return;
			boolean leave = magic(g, false);
			if (leave) out("leave");
			else out("stay");
		}
	}

    int k, t, x, l;
    public boolean magic(graph g) {
        return this.magic(g, false);
    }

    public boolean magic(graph g, boolean verbose) {
        ArrayDeque queue = new ArrayDeque<vertex>();
        HashMap<Integer, vertex> visited = new HashMap<Integer, vertex>();
        queue.add(g.vertexmap.get(l));

        while (queue.size() > 0) {
            vertex v = (vertex)queue.remove();
            visited.put(v.id, v);
            if (verbose) out("Pop " + v.id);
            for (edge e : v.edges) {
                if (e.v1.id == v.id) {
                    e.v2.edges.remove(e);
                    if (verbose) out("Leave? " + e.v2.id + ": " + e.v2.leave() + ", want " + e.v2.original + "/" + e.v2.edges.size());
                    if (v.id != e.v2.id && e.v2.leave() && !visited.containsKey(e.v2.id) && !queue.contains(e.v2)) {
                        queue.add(e.v2);
                    }
                }
                else {
                    e.v1.edges.remove(e);
                    if (verbose) out("Leave? " + e.v1.id + ": " + e.v1.leave() + ", want " + e.v1.original + "/" + e.v1.edges.size());
                    if (e.v1.leave() && !visited.containsKey(e.v1.id) && !queue.contains(e.v1)) {
                        queue.add(e.v1);
                    }
                }
            }
        }

        return visited.containsKey(x);
    }

	public graph read_graph() throws Exception {
		graph gr = new graph();
		String input = in.readLine();
		if (input == null) return null;
		String[] k_t_x_l = input.split(" ");
		k = Integer.parseInt(k_t_x_l[0]);
		t = Integer.parseInt(k_t_x_l[1]);
		x = Integer.parseInt(k_t_x_l[2]);
		l = Integer.parseInt(k_t_x_l[3]);

		HashMap<Integer, vertex> vertexset = new HashMap<Integer, vertex>();
		for (int i = 0; i < t; i++) {
			input = in.readLine();
			String[] a_b = input.split(" ");
			int a = Integer.parseInt(a_b[0]);
			int b = Integer.parseInt(a_b[1]);
			vertex v1, v2;
			if (!vertexset.containsKey(a)) {
				v1 = new vertex(a);
				vertexset.put(a, v1);
				gr.vertices.add(v1);
                gr.vertexmap.put(v1.id, v1);
			}
			else v1 = vertexset.get(a);
			if (!vertexset.containsKey(b)) {
				v2 = new vertex(b);
				vertexset.put(b, v2);
				gr.vertices.add(v2);
                gr.vertexmap.put(v2.id, v2);
			}
			else v2 = vertexset.get(b);

			edge e = new edge(v1, v2, i);
			v1.edges.add(e);
			v2.edges.add(e);
			gr.edges.add(e);
            gr.edgemap.put(e.id, e);
            ++v1.original;
            ++v2.original;
		} 

		return gr;
	}

    public class graph {
        public ArrayList<edge> edges;
        public ArrayList<vertex> vertices;
        public HashMap<Integer, edge> edgemap;
        public HashMap<Integer, vertex> vertexmap;

        public graph() {
            this.vertices = new ArrayList<vertex>();
            this.edges = new ArrayList<edge>();
            this.edgemap = new HashMap<Integer, edge>();
            this.vertexmap = new HashMap<Integer, vertex>();
        }

        public graph(ArrayList<vertex> vertices, ArrayList<edge> edges) {
            this.vertices = vertices;
            this.edges = edges;
        }
		public String toString() {
			String result = "";
			for (edge e : this.edges) {
				result += e.toString();
				result += '\n';
			}
			return result;
		}
    }
    
    public class vertex {
        public int id;
        public ArrayList<edge> edges;
        public vertex parent;
        public edge parent_edge;
        public int original;
        public int current;

        public vertex(int id) {
            this.id = id;
            this.edges = new ArrayList<edge>();
            this.parent = null;
            this.parent_edge = null;
            this.original = 0;
            this.current = this.original;
        }
        public boolean leave() {
            return this.edges.size() <= original / 2;
        }
        public boolean Equals(Object o) {
            vertex v = (vertex)o;
            return this.id == v.id;
        }
        public String toString() {
            return "(" + this.id + ")";
        }
        @Override
        public int hashCode() {
            return this.id;
        }
    }

    public class edge {
        public vertex v1, v2;
        public char result;
		public int id;
        public edge(vertex v1, vertex v2, int id) {
            this.v1 = v1;
            this.v2 = v2;
			this.id = id;
        }
        public boolean connected(vertex v) {
            return this.v1.id == v.id || this.v2.id == v.id;
        }
        public String toString() {
            return "[" + this.v1.id + " - " + this.v2.id + "]";
        }
        public boolean Equals(Object o) {
            edge e = (edge)o;
            return this.v1.id == e.v1.id && this.v2.id == e.v2.id;
        }
        @Override
        public int hashCode() {
			return id;
        }
    }
}
