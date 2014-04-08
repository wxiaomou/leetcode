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
        int n = points.size();
        int ret = 0;
        unordered_map<float, int> _map;
        for (int i = 0; i < n; i++) {
            _map.clear();
            int same = 0, tmp = 1;
            for (int j = i + 1; j < n; j++) {
                double k = std::numeric_limits<double>::infinity();
                if (points[j].x != points[i].x) {
                    k = (float) (points[j].y - points[i].y) / (points[j].x - points[i].x); // if x diff then can compute the slop O.W. k shoud be infinity;
                } else if (points[j].y == points[i].y) {
                    same++;
                    continue;
                }
                if (_map.count(k) == 0) {
                    tmp = max(2, tmp);
                    _map[k] = 2;
                } else {
                    tmp = max(++_map[k], tmp);
                }
            }
            ret = max(ret, tmp + same);
        }
        return ret;
    }
/*for j start w/ i + 1, each time we treat ipoints[i] as the left point of the line, because slop is consist nomatter points[i]->points[j] or reverse it's not a 向量
  所以只要线上的一个点出现过这条线就已经计算过了，j就没必要在从0开始了 (points[j].y - points[i].y) / (points[j].x - points[i].x) ＝＝ (points[i].y - points[j].y) / (points[i].x - points[j].x)
  a, b, c, d 当a出现过时此条线已经计算过了， 到b的时候就不用考虑a了*/

  
//---------------------------------------------------------------//
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