package Coursework;

import java.io.*;
import java.util.*;

import javax.lang.model.util.Elements;

public class Spell {
	

	public static void main(String[] args) throws java.io.IOException
	{
		//Declarations
		FileWordRead dict,file;
		HashDictionary dictionary,misspell;
		long startTime, finishTime;

		

		startTime = System.currentTimeMillis(); //Start Timer for Performance Test
		try
		{
			dict  = new FileWordRead(new BufferedInputStream(new FileInputStream(args[0])));
			file  = new FileWordRead(new BufferedInputStream(new FileInputStream(args[1])));
			// To read from specific files, comment the 2 lines above and 
			// un-comment 2 lines below 
			//dict  = new FileWordRead(new BufferedInputStream(new FileInputStream("/Users/Thomas/Desktop/d5.txt")));
			//file  = new FileWordRead(new BufferedInputStream(new FileInputStream("/Users/Thomas/Desktop/checkText.txt")));
			StringHashCode hc = new StringHashCode(); //Create new StringHashCode for creating HashCodes

			double lF = 0.75; //Load Factor

			dictionary = new HashDictionary(hc,lF); 

			//Take in Input and add to Dictionary, When Input isn't available, close the File
			while(dict.hasNextWord()) 
			{
				dictionary.insert(dict.nextWord());

			}

			Iterator<String> fullDictionary = dictionary.elements();
			int abc = 0;
			while(file.hasNextWord()) //For Every word in the File
			{
				abc++;
				String word = file.nextWord();
				ArrayList<String> corrections = new ArrayList<String>();
				if(!(checkWord(word,dictionary))) //If the Word is not in the Dictionary
				{
					corrections.add(word);
				}
				for(int i=0;i<corrections.size();i++){
					misspell = new HashDictionary(hc,lF); //Create New HashDictionary
					misspell = runChanges(word,dictionary); //Run Alterations on it as we know it's Misspelled
					Iterator<String> itr = misspell.elements(); //Create an Iterator to print the Suggestions
					System.out.println("Mispelled - "+ word); //Print the Mis-spelled Word
					while(itr.hasNext())
					{

						System.out.println("Suggestion:- "+ itr.next() ); //

					}
					System.out.println("----------------------------------------------");
				}

			}
		}
		catch (IOException e)
		{
			// catches exceptions from file I/O errors
			System.out.println("Your file name is wrong, please check it");
			System.exit(0);
		}  
		finishTime = System.currentTimeMillis();
		long totalTime = finishTime - startTime;
		System.out.println("This took :- "+ totalTime +" Milliseconds");





	}


	// function is used to check whether a word is used via iteration of 'FullDictionary'
	private static boolean checkWord(String checkWord,HashDictionary dictionary)
	{
		boolean exists = false;
				
		if(dictionary.find(checkWord)){
			exists = true;
		}
		return exists;
	}

	private static HashDictionary runChanges(String word,HashDictionary dictionary)
	{
		HashDictionary corrections = new HashDictionary(new StringHashCode(),0.5);//stores a dictionary of suggested correct words
		Iterator<String> fullDictionary = dictionary.elements();
		int length = word.length();
		String alpha [] = new String[26];//creates an array for each letter of the alphabet and initialises it to hold 26 String variables/
		alpha[0] = "a";//Puts the letters into the array.
		alpha[1] = "b";
		alpha[2] = "c";
		alpha[3] = "d";
		alpha[4] = "e";
		alpha[5] = "f";
		alpha[6] = "g";
		alpha[7] = "h";
		alpha[8] = "i";
		alpha[9] = "j";
		alpha[10] = "k";
		alpha[11] = "l";
		alpha[12] = "m";
		alpha[13] = "n";
		alpha[14] = "o";
		alpha[15] = "p";
		alpha[16] = "q";
		alpha[17] = "r";
		alpha[18] = "s";
		alpha[19] = "t";
		alpha[20] = "u";
		alpha[21] = "v";
		alpha[22] = "w";
		alpha[23] = "x";
		alpha[24] = "y";
		alpha[25] = "z";

		//Substitute a letter to try and correct word(Letter Substitution)
		for(int i = 0;i < length;i++)
		{
			for(int a = 0;a < 26;a++)
			{
				char letter = alpha[a].charAt(0);
				StringBuffer temp = new StringBuffer(word);
				temp.setCharAt(i,letter);
				String correction = temp.toString();
				if(dictionary.find(correction))
				{
					corrections.insert(correction);
				}
			}
		}

		//Removes a letter to try and correct word(Letter Omission)
		fullDictionary = dictionary.elements();
		for(int i = 0;i < length-1;i++)
		{
			StringBuffer manipulation = new StringBuffer(word);
			manipulation.deleteCharAt(i);
			String correction = manipulation.toString();
			if(dictionary.find(correction))
			{
				corrections.insert(correction);
			}
		}

		//Inserts a letter to try and correct word(Letter Insertion)
		fullDictionary = dictionary.elements();
		for(int i = 0;i < length+1;i++)
		{
			for(int a = 0;a < 26;a++)
			{
				String letter = alpha[a];
				StringBuffer man = new StringBuffer(word);
				man.insert(i,letter);//inserts the letter into the i-th position
				String correction = man.toString();//takes the String Buffer man, and turns it into a string.
				if(dictionary.find(correction))//checks the dictionary to find the corrected word
				{
					corrections.insert(correction);//if the corrected word exists, add it.
				}
			}
		}

		//Letter Reversal
		fullDictionary = dictionary.elements();
		for(int i = 0;i < length-1;i++)
		{
			int j = i + 1; //set j to the letter following i.
			String correction = "";
			correction = word.substring(0,i) + word.charAt(j) + word.charAt(i) + word.substring(i+2);

			if(dictionary.find(correction))//checks the dictionary to check if the manipulated word exists.
			{
				corrections.insert(correction);//if the manipulated word does exist, insert the word.
			}

		}

		return corrections;

	}	
}




