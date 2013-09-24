package Coursework;

import java.util.*;


public class HashDictionary implements Dictionary {

	private double loadFactor;
	private int tableSize;
	private int capacity;
	private int ops;
	private int probe;

	String [] array;

	StringHashCode hs;

	public HashDictionary () throws DictionaryException 
	{
		throw new DictionaryException("The hash");
	}//User should never use the HashDictionary without Parameters in the Constructor

	public HashDictionary (StringHashCode inputCode, double inputLoadFactor)
	{
		//Constructors for hashDictionary
		tableSize = 7;
		hs = inputCode;
		loadFactor = inputLoadFactor;
		array = new String[tableSize];

	}
	public void insert(String key)
	{
		ops++; //increment the operations no.
		int hashCode = genHashCode(key); //Get the hash code
		while(hashCode < 0)
		{
			hashCode = hashCode + tableSize; //If this is lower than 0, the tableSize is increased.
		}
		boolean notInserted = true;
		while(notInserted = true)
		{
			probe++;  //increment the probe no.
			if(array[hashCode] == null || array[hashCode].equals("-1")) 
			{//If the array has been empty or is empty.			{
				array[hashCode] = key; //Place it in the Key
				capacity++; //We've increased in Size
				float currentLF = capacity/tableSize;
				if(currentLF >= loadFactor) //checks the efficiency of the program, if it is not efficient, move on to rehash.
				{
					rehash(); //Rehash the table in order to increase efficiency.
				}
				return;
			}
			else
			{
				hashCode = hashCode + 1; //Move to the Next 
				if(hashCode >= tableSize)
				{
					hashCode= hashCode - tableSize; //Prevents the program from allowing Array Out of Bounds Errors
				}
			}

		}

	}

	public boolean find(String key)
	{
		ops++; //increment ops no.
		int hashCode = genHashCode(key); //Get a new hash number
		while(hashCode < 0)
		{
			hashCode = hashCode + tableSize; //Prevents out of bounds errors.
		}
		int avail = -1;
		boolean empty = false;
		while(hashCode < tableSize)
		{
			probe++; //increment probe no.
			if(array[hashCode] == null) //It's not been placed here or further up the table
			{
				return false;
			}
			else
			{
				if(array[hashCode].equals(key)) //checks that the key exists in the array.
				{
					return true;
				}
				else
				{
					hashCode++; //If it doesnt exist, try the next position on the table
					if(hashCode >= tableSize)
					{
						hashCode= hashCode - tableSize; //Prevents out of Bounds Errors
					}
				}
			}
		}
		return false;

	}

	@Override
	public Iterator<String> elements()
	{
		ArrayList<String> itList = new ArrayList<String>(tableSize); //I only do this for it's Iterator
		for(int i = 0;i < array.length;i++)
		{
			if(!(array[i] == null))//Checks if the position is empty.
			{                  
				if(!(array[i].equals("-1"))) //Checks it hasn't been occupied recently.
				{
					itList.add(array[i]); //adds the value to the iterator.
				}
			}
		}
		Iterator<String> iterator = itList.iterator(); //Creates the Iterator
		return iterator;
	}
	


	public void remove(String key) throws DictionaryException
	{
		ops++; //Increments operations no.
		int hashCode = genHashCode(key); //Gets a new hash key
		while(hashCode < 0)
		{
			hashCode = hashCode + tableSize; //Prevents out of Bounds Errors
		}
		boolean found = false;
		if(!(find(key))) //Not found the Key, so it can't exist, Throw a New Exception!!
		{
			String e = "Attempting to Delete a Non-Existant Entry";
			throw new DictionaryException(e);
		}
		while(hashCode < tableSize) 
		{
			probe++;

			if(array[hashCode].equals(key))//check if the key exists in the array
			{
				array[hashCode] = "-1";//in case we have other elements that rely on this key
				found = true;
				capacity--;
				return;
			}
			else
			{
				hashCode = hashCode + 1; //if not found, check the next position.
				if(hashCode >= tableSize)
				{
					hashCode= hashCode - tableSize; //to stop out of bounds
				}
			}
		}
	}

	public float averNumProbes()
	{
		return probe/ops; //Divides probes by ops in order to return the average number of probes.
	}

	private void rehash() 
	{
		//when this becomes inneficient, this method is run to increase the table size and rehash the values.
		tableSize = (tableSize*2)+1; //doubles the table size and adds 1.
		Iterator itr = elements(); //New Iterator of Elements

		capacity = 0; //Reset all our Statistics
		probe = 0;
		ops = 0;
		while(!isPrime(tableSize))//We want a prime number, so if it isn't prime we add two and try again
		{
			tableSize += 2;
		}
		array = new String[tableSize]; //Creating new array to take the new table size from the rehash(will be a prime number)
		while(itr.hasNext())
		{

			insert(itr.next().toString()); //adds all elements from the old inneficient array to the new array
		}
	}

	private boolean isPrime(int n) //Method checks if a Number is Prime or Not
	{

		if(n % 2 == 0)//if divisible by exactly 2, not prime.
		{
			return false;
		}
		for(int i=2;2*i<n;i++)//Test the next possible  prime number
		{
			if(n%i == 0)//if divisible by i(2), not prime, else we have found a prime number
			{
				return false;
			}
		}
		return true;
	}

	private int genHashCode(Object o) //This Method Brings the Key into the Ranges of the Table
	{
		int hc = 0;
		String key = o.toString();
		hc =  hs.giveCode(key);
		hc = hc % tableSize;
		while(hc >= tableSize)
		{
			hc = hc - tableSize;
		}
		return hc;
	}
}
