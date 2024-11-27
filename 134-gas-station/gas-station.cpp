class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int max = gas.size();

        if (max == 1) {
            return gas[0] < cost[0] ? -1 : 0;
        }

        bool gassemua = true;
        bool costsama = true;
        int firstgas = gas[0];
        int firstcost = cost[0];
        for (int i = 1; i < 20; i++) {
            if (gas[i] != firstgas) {
                gassemua = false; break;
            }
            if (cost[i] != firstcost) {
                costsama = false; break;
            }
        }

        if (gassemua && costsama) {
            if (firstgas == firstcost) {
                return firstgas == 0 ? gas.size() - 1 : -1;
            } else {
                return gas.size() - 1;
            }
        }

        for (int i = 0; i < max; i++) {
            // Initiate for every loop
            bool possible = true;               // awalnya mungkin
            int tank = gas[i];                  // kita isi dulu sama nilai di station
            int nextStation = (i + 1) % max;    // next station target
            int currentStation = i;             // station sekarang
            bool rotated = false;

            while (!rotated || currentStation != i) {     // selama next station nya blom i (balik)
                // Check if it is possible to go to next station
                if (tank < cost[currentStation]) {
                    possible = false; break;
                }

                // Calculate the current tank
                tank = tank - cost[currentStation] + gas[nextStation];
                
                // Re-adjust curr
                currentStation++; nextStation++;
                if (currentStation == max - 1) nextStation = 0;
                if (currentStation == max) {
                    currentStation = 0; rotated = true;
                }
            }

            if (possible && currentStation == i) return currentStation;
        }
        
        return -1;
    }
};