class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        
        
        List<List<int[]>> graph = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for(int[] edge : edges) {
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
            graph.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{0, 0});
        
        int[] minTime = new int[n];
        Arrays.fill(minTime, Integer.MAX_VALUE);
        minTime[0] = 0;
        
        while(!pq.isEmpty()) {
            
            int[] top = pq.poll();
            
            int currentNodeTime = top[1], currentNode = top[0];
            
			//don't process the node when it is bound to give large times.
            if(currentNodeTime > minTime[currentNode]) {
                continue;
            }
            
            for(int[] neighbours : graph.get(currentNode)) {
                
                int neighbour = neighbours[0], time = neighbours[1];
                
                int neighbourTime = currentNodeTime + time;
                
                if(neighbourTime < disappear[neighbour] && neighbourTime < minTime[neighbour]) {
                    minTime[neighbour] = neighbourTime;
                    pq.offer(new int[]{neighbour, neighbourTime});
                }
            }
            
        }
        
        for(int i = 0; i < n; i++) {
            if(minTime[i] == Integer.MAX_VALUE) {
                minTime[i] = -1;
            }
        }
        
        return minTime;
    }
}