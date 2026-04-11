int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
 int dist[n];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Step 2: Relax edges k+1 times
    for (int i = 0; i <= k; i++) {

        int temp[n];

        // Copy current distances
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        // Relax all flights
        for (int j = 0; j < flightsSize; j++) {

            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if (dist[u] == INT_MAX)
                continue;

            if (dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }

        // Copy temp back to dist
        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    // Step 3: Return result
    if (dist[dst] == INT_MAX)
        return -1;

    return dist[dst];    
}