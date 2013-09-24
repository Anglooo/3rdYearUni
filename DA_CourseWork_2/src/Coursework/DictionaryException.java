package Coursework;

public class DictionaryException extends Exception 
{
	public DictionaryException(String error)
	{
		System.out.println("Error: "+ error); //There has been an Error so I'm going to tell the User what it is.
	}
}

