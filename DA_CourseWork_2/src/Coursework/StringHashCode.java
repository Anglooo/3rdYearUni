package Coursework;

public class StringHashCode implements HashCode 
{
	
        public int giveCode(Object o)
	{
              char [] c;   //Create an Array of Characters
              String s = o.toString(); //Since o is an Object, we need to convert it to a String
              c = s.toCharArray(); //Turn our Key into a Char Array
              int length = c.length; //How long is the Word
              int hashCode = c[length - 1]; //Last Letter in the Sequence to start the HashCode off
              int i = length - 2; 
              while(i >= 0)
              {
                  hashCode = hashCode * 33 + c[i]; //Times the HashCode by 33 (Near Prime) and add the next Letter's code
                  i--;
              }
              return hashCode; 
	}
}