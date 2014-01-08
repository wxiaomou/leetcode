#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        if (!n) return vector<Interval>(1, newInterval);
        int i = 0;
        while (i < n && intervals[i].start < newInterval.start) i++;
        if (!i)
            intervals.insert(intervals.begin(), newInterval);
        else if (i == n)
            intervals.push_back(newInterval);
        else 
            intervals.insert(intervals.begin() + i, newInterval);
            
        return merge(intervals);
    }
    
     vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (!n) return vector<Interval>();
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
	//-----------------------------------------------------------//
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
			vector<Interval> ret;
			int first = -1;
			int last = -1;
			bool inserted = false;

			intervals.push_back(newInterval);// if the interval is the last interval, if it not,this can ensure that we won't access some space that is null
			for (int i = 0; i < intervals.size(); ++i) {
				if (i == (intervals.size() - 1) && inserted) break;// avoid insert newInterval twice
				Interval tmp = intervals[i];
				if (!inserted && newInterval.start < tmp.start) {
						inserted = true;
						tmp = newInterval;
						i--;
				}

				if (first == -1) {
						first = tmp.start;
						last = tmp.end;
				} else if (tmp.start <= last) { // already ensure that tmp.start > first because line 24 in last round;
						last = max(tmp.end, last);
				}	else {
						Interval a(first, last);
						ret.push_back(a);
						first = tmp.start;
						last = tmp.end;
				}
				
			}
			Interval a(first, last);
			ret.push_back(a);

			return ret;
	}
};

int main(int argc, char **argv) {
	Solution sol;
	vector<Interval> intervals;
	Interval newInt(0, 9);
	Interval a1(1, 5);
	Interval a2(6, 8);
	intervals.push_back(a1);
	intervals.push_back(a2);

	vector<Interval> ret = sol.insert(intervals, newInt);

	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].start << " " << ret[i].end << endl;
	}
	cout << "---------------------------------" << endl;

	intervals.clear();

	Interval b1(1, 2);
	Interval b2(3, 5);
	Interval b3(6, 7);
	Interval b4(8, 10);
	Interval b5(12, 16);

	intervals.push_back(b1);
	intervals.push_back(b2);
	intervals.push_back(b3);
	intervals.push_back(b4);
	intervals.push_back(b5);
	
	Interval newInt1(4, 9);
 	ret = sol.insert(intervals, newInt1);

	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].start << " " << ret[i].end << endl;
	}



	return 1;
}
