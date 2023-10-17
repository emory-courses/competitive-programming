// @EXPECTED_RESULTS@: TIMELIMIT,RUN-ERROR
/*
   Solution in Java for Brexit
   a problem for BAPC2016
   author: Peter Kluit
   September 2016
   
   This solution is recursive and needs a large stack size. We have discovered
   that 8MB is not enough, but 16MB is enough.
   
   Regardless of the stack size, this program is too slow. The number of
   neighbouring leavers is recalculated every time a country is visited.
   
   The test data for this problem is ordered in such a way that this solution
   gets TIMELIMIT before a test case occurs that results in RUNTIME ERROR.
   
   For a recursive Java solution that is actually fast enough, please refer
   to the file Brexit_DFS.java (in the ACCEPTED directory).
 */


import java.util.*;
import java.io.*;


public class Brexit_PGK {
	public static void main (String [] args) {
		try {
			run();
		} catch (IOException iox) {
			// probably ignore this?
		}
	}
	
	private static void run() throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String line = input.readLine();
		Scanner ir = new Scanner(line);
		int countries = ir.nextInt();
		int pairs = ir.nextInt();
		int home = ir.nextInt();
		int leaving = ir.nextInt();
		Union union = new Union(countries, home, leaving);
		for (int k = 0; k < pairs; k++){
			line = input.readLine();
			String[] split_line = line.split(" ");
			int t1 = Integer.parseInt(split_line[0]);
			int t2 = Integer.parseInt(split_line[1]);
			union.addPair(t1, t2);
		}
		union.printSolution();
	}
}

class Union {
	Country [] country;
	int countries;
	int home;
	int leaving;
	
	public Union(int c, int h, int l) {
		Country.union = this;
		countries = c;
		home = h;
		leaving = l;
		country = new Country[countries + 1];
		for (int t = 0; t <= countries; t++) {
			country[t] = new Country();
		}
	}
	
	public void addPair(int t1, int t2) {
		country[t1].addPartner(t2);
		country[t2].addPartner(t1);
	}
	
	public void printSolution() {
		country[leaving].exit();

		if (country[home].exit) {
			System.out.println("leave");
		}
		else {
			System.out.println("stay");
		}
	}
}

class Country {
	static Union union;
	ArrayList<Integer> partners = new ArrayList<Integer>();

	boolean exit = false;

	public Country() {}

	public void addPartner(int t) {
		partners.add(t);
	}

	void exit() {
		exit = true;
		for (int p : partners) {
			Country partner = union.country[p];
			partner.visit();
		}
	}

	void visit() {
		if (exit)
			return;
		int leavers = 0;
		for (int p : partners) {
			Country partner = union.country[p];
			if (partner.exit)
				leavers++;
		}
		if (2 * leavers >= partners.size()) {
			exit = true;
			for (int p : partners) {
				Country partner = union.country[p];
				partner.visit();
			}
		}
	}

}
