/**
 * Definition for an interval.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myclass {
  bool operator() (const Interval i,const Interval j) { return (i.start < j.start);}
} myOp;

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (!n) return vector<Interval>();
        sort(intervals.begin(), intervals.end(), myOp);
        vector<Interval> ret(1, intervals[0]);
        for (int i = 1; i < n; ++i) {
            int k = ret.size() - 1;
            int end = ret[k].end;
            if (end < intervals[i].start) {
                ret.push_back(intervals[i]);
                continue;
            } else if (end >= intervals[i].end) {
                continue;
            } else {
                ret[k].end = intervals[i].end;
            }
        }
        return ret;
    }
};
//----------------------------------------------//
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
bool compare(Interval a, Interval b) {
	return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
			vector<Interval> res;
			if (intervals.empty())
				return res;
			sort(intervals.begin(), intervals.end(), compare);
			int left = intervals[0].start;
			int right = intervals[0].end;

			for (int i = 1; i < intervals.size(); ++i) {
				Interval tmp = intervals[i];
				if (tmp.start <= right )
					right = max(right, tmp.end);
				else {
					Interval a(left, right);
					res.push_back(a);
					left = tmp.start;
					right = tmp.end;
				}
			}
			Interval last(left, right);
			res.push_back(last);
			return res;
    }

};

int main(int argc, char **argv) {
	Interval a(1, 3);
	Interval b(0, 6);
	Interval c(8, 10);
	Interval d(15, 18);

	vector<Interval> test;
	test.push_back(a);
	test.push_back(b);
	test.push_back(c);
	test.push_back(d);

	Solution sol;
	test = sol.merge(test);
	for (int i = 0; i < test.size(); ++i) {
		cout << "[" << test[i].start << "," << test[i].end << "] ";
	}
}
