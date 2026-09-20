class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int minix = min(xCenter,x2);
        int miniy = min(yCenter,y2);
        int maxix = max(minix,x1);
        int maxiy = max(miniy,y1);
        return ((xCenter-maxix)*(xCenter-maxix) + (yCenter-maxiy)*(yCenter-maxiy)) <= (radius*radius);
    }
};