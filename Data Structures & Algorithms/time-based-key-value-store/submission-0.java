class TimeMap {
    //   Key            <Version, Value>     
    Map<String, TreeMap<Integer, String>> hm;
    public TimeMap() {
        hm = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        hm.computeIfAbsent(key, x -> new TreeMap<>()).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        Integer version = (hm.containsKey(key)) ? hm.get(key).floorKey(timestamp) : null;
        return (version != null) ? hm.get(key).get(version) : "";
    }
}