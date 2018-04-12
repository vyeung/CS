import java.util.*;

public class BloomFilter<AnyType> {

	// Use an array of hash tables (an array of arrays) as the basis for the 
	// bloom filter
	boolean [][] hash_tables;
	
	// The constructor expects an array of integers telling us how large each of
	// the hash tables should be.
	BloomFilter(int [] capacities) {
		// Create an array of 'capacities.length' hash tables.
		hash_tables = new boolean[capacities.length][];
																	
		// Create the hash tables (boolean arrays) with the desired lengths.
		for (int i = 0; i < capacities.length; i++)
			hash_tables[i] = new boolean[capacities[i]];
	}
	
	public void add(AnyType o) {
		// Every object has a hashCode() method.
		int hval = o.hashCode();
		
		// Hash functions are susceptible to integer overflow, and so they may
		// return negative results. Hash value should to be positive.
		if (hval < 0) hval = hval - Integer.MIN_VALUE;
		
		// Hash the value into each of the hash tables.
		for (int i = 0; i < hash_tables.length; i++)
			hash_tables[i][hval % hash_tables[i].length] = true;
	}
	
	public boolean contains(AnyType o) {
		// Every object has a hashCode() method.
		int hval = o.hashCode();

		// Hash functions are susceptible to integer overflow, and so they may
		// return negative results. Hash value should to be positive.
		if (hval < 0) hval = hval - Integer.MIN_VALUE;
		
		// If the object does not collide with 'true' values in each hash table,
		// then it cannot have been inserted into the Bloom filter, and we
		// return false.
		for (int i = 0; i < hash_tables.length; i++)
			if (hash_tables[i][hval % hash_tables[i].length] == false)
				return false;
		
		// If we get here, then this value was *probably* inserted into the 
		// Bloom filter.
		return true;
	}

	// Calculate the expected false positive rate of the Bloom filter 
	public double expectedFalsePositiveRate() {

		double rate = 1.0;

		for (int i = 0; i < hash_tables.length; i++) {
			int count = 0;

			for (int j = 0; j < hash_tables[i].length; j++)
				if (hash_tables[i][j])
					count++;

			rate *= (double)count / hash_tables[i].length;
		}

		return rate * 100.0;
	}

	public static void main(String [] args) {

		// The sizes of the respective hash tables. 
		int [] capacities = {11, 13, 17, 19, 23};
		
		// Some names to insert
		String [] names = {"Joe", "Anna", "Rob", "Bran", "Danny"};
		
		// Primary data structures are a Bloom filter and hash set.
		BloomFilter<String> bloomyBloom = new BloomFilter<String>(capacities);
		HashSet<String> hashyHash = new HashSet<String>();
		
		// Insert the names into the Bloom filter. Also, store them in a HashSet
		for (String s : names) {
			bloomyBloom.add(s);
			hashyHash.add(s);
		}
		
		// Verify that these names made it into the Bloom filter correctly.
		for (String s : names)
			if (bloomyBloom.contains(s))
				System.out.println("Found name: " + s);
		
		// Create a ton of random strings and see whether they appear
		// in the Bloom filter!
		int n = 100000, false_positives = 0;
		char [] word = new char[4];
		
		for (int i = 0; i < n; i++) {
			// Generate a random array of characters. Capitalize the first char.
			for (int j = 0; j < word.length; j++)
				word[j] = (char)((int)(Math.random() * 26) + ((j == 0) ? 'A' : 'a'));
		
			// Convert array of random chars to a string.
			String str = new String(word);

			// Count how many randomly generated strings appear to be in the Bloom filter, but are not present in the original array (false positives).
			if (bloomyBloom.contains(str) && !hashyHash.contains(str))
				false_positives++;
		}
		
		System.out.print("False positive rate: ");
		System.out.print((double)false_positives / (double)n * 100.0 + "%\n");

		System.out.print("Expected false positive rate: ");
		System.out.print(bloomyBloom.expectedFalsePositiveRate() + "%\n");
	}
}


