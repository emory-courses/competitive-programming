/*
   Solution in Java for Brexit
   a problem for BAPC2016
   author: Peter Kluit, Josse van Dobben de Bruyn
   October 2016
   
   This solution should not result in stack overflow, but rather run quickly
   and produce correct answers.
   
   Based on Brexit_PGK.java, which is too slow.
 */

import java.util.*;
import java.io.*;


public class Brexit_DFS {
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
	int partnersLeave = 0;

	boolean exit = false;

	public Country() {}

	public void addPartner(int t) {
		partners.add(t);
	}

	void exit() {
		exit = true;
		for (int p : partners) {
			Country partner = union.country[p];
			partner.partnersLeave++;
			if (2 * partner.partnersLeave >= partner.partners.size() && !partner.exit) {
				partner.exit();
			}
		}
	}

}
