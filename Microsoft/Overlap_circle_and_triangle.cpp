class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        //finding a point lying in between center and square which may/maynot be the point of overlap
        int xn = max(x1, min(x2, xc));
        int yn = max(y1, min(y2, yc));
        //check if the distance between center and the point is less/equal to radius
        return (yn-yc)*(yn-yc)+(xn-xc)*(xn-xc) <= r*r;
    }
};