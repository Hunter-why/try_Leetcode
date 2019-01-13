// Method : total minus overlap
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (C-A) * (D-B) + (G-E) * (H-F);
        if (A >= G || E >= C || B >= H || F >= D)
            return total;
        return total - (min(C, G)-max(A, E)) * (min(D, H) - max(B, F));
        
        // or let max judge if there exits overlap area
        //return total - max((min(C, G)-max(A, E)), 0) * max((min(D, H) - max(B, F)), 0); 
    }
};