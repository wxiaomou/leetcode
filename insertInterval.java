/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> ret = new ArrayList<Interval>();
        for (Interval iter : intervals) {
            if (iter.end < newInterval.start) {
                ret.add(iter);
            } else if (iter.start > newInterval.end) {
                ret.add(newInterval);
                newInterval = iter;
            } else {
                Interval newInter = new Interval();
                newInter.start = Math.min(iter.start, newInterval.start);
                newInter.end = Math.max(iter.end, newInterval.end);
                newInterval = newInter;
            }
        }
        ret.add(newInterval);
        return ret;
    }
}
