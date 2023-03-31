class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase()
                .replaceAll("[^a-z0-9_.\\-]", "")
                .replaceAll("(\\.)+", ".")
                .replaceAll("^\\.", "")
                .replaceAll("\\.$", "");

        if (new_id.isEmpty()) new_id = "aaa";

        while (new_id.length() < 3) new_id += new_id.charAt(new_id.length() - 1);

        if (new_id.length() > 15) new_id = new_id.substring(0, 15).replaceAll("\\.$", "");

        return new_id;
    }
}