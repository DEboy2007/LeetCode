import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        // Make hashmap of roman numberal vs number
        HashMap<String, Integer> key = new HashMap<String, Integer>();
        key.put("I", 1);
        key.put("V", 5);
        key.put("X", 10);
        key.put("L", 50);
        key.put("C", 100);
        key.put("D", 500);
        key.put("M", 1000);

        HashMap<String, Integer> special = new HashMap<String, Integer>();
        special.put("IV", 4);
        special.put("IX", 9);
        special.put("XL", 40);
        special.put("XC", 90);
        special.put("CD", 400);
        special.put("CM", 900);
        
        int total = 0;
        // Iterate through string
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && !(special.get(s.substring(i, i+2)) == null)) {
                total += special.get(s.substring(i, i+2));
                i++;
            }
            else {
                total += key.get(s.substring(i, i+1));
            }
        }

        return total;
        
    }
}