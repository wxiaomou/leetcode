/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1 || isAllSame(points)) return points.size();
        int _max = 2;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                while (j < points.size() && points[i].x == points[j].x && points[i].y == points[j].y) j++;
                int count = 2;
                for (int k = 0; k < points.size(); k++) {
                    if (k != i && k != j && sameLine(points[i], points[j], points[k])) {
                        count++;
                        _max = max(_max, count);
                    }
                }
            }
        }
        return _max;
    }
    
    bool sameLine(Point a, Point b, Point c) {
        return (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x) == 0;
    }
    
    bool isAllSame(vector<Point> &points) {
        for (int i = 0; i < points.size(); i++) {
            if (points[i].x != points[0].x || 
                points[i].y != points[0].y)
                return false;
        }
        return true;
    }
};