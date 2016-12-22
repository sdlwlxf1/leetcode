#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point>& points) {
    if(points.size() <= 1)
        return points.size();
    unordered_map<int, int> kc;
    
    int max = 0;
    for(int j = 0; j < points.size(); j++)
    {
        Point &a = points[j];
        kc.clear();
        int plus = 1;
        for(int i = 0; i < points.size(); i++)
        {
            if(i == j)
                continue;
            Point &b = points[i];
            if(b.y == a.y && b.x == a.x) {
                plus++;
                if(plus > max)
                    max = plus;
            }
            else {
                int k = 1;
                if(b.x != a.x)
                    k = (b.y-a.y)*1000/(b.x-a.x);
                kc[k]++;
                if(kc[k]+plus > max)
                    max = kc[k]+plus;
            }
        }
    }
    
    return max;
}

//int main() {
//    vector<Point> points = {{1,1},{1,1},{2,2},{2,2}};
//    int ret = maxPoints(points);
//    return ret;
//}
