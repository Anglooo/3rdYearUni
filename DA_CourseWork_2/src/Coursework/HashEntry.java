package Coursework;

public class HashEntry {
    private String unHashedKey;
    private String value;
    private int key;

    HashEntry(String UnHashedkey, String value) {
          this.unHashedKey = unHashedKey;
          this.value = value;
    }     

    public int getKey() {
          StringHashCode a = new StringHashCode();
          key = a.giveCode(unHashedKey);
          return key;
    }

    public String getValue() {
          return value;
    }
    
}
