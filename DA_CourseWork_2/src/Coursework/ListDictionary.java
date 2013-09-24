package Coursework;

import java.util.*;

public class ListDictionary {
	LinkedList<String> dictionary = new LinkedList<String>();
	
	public ListDictionary() {
		
	}
	
	public void insert(String key){
		dictionary.addLast(key);
	}
	
	public boolean find(String key){
		if(dictionary.contains(key)){
			return true;
		}
		return false;
	}
	
	public Iterator elements() {
		Iterator it = dictionary.iterator();
		return it;
	}
	
	public void remove(String key) throws DictionaryException{
		dictionary.remove(key);
	}
}
