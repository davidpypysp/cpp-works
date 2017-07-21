#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

struct Point {
    float x;
    float y;
    Point(float x, float y) : x(x), y(y) {
    }
};


struct Line {
    float slope;
    float intercept;
    bool infinite_slope = false;

    Line(Point a, Point b) {
        if(a.x == b.x) {
            infinite_slope = true;
            intercept = a.x;
        } 
        else {
            slope = (a.y - b.y) / (a.x - b.x);
            intercept = a.y - slope * a.x;
        }
    }

};


class C10_6 {
public:
    Line* FindBestLine(Point points[], int n) {
        unordered_map<Line, int> map;
        int max = 0;
        Line *result_line = nullptr;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                Line line(points[i], points[j]);
                if(map.find(line) == map.end()) {
                    map[line] = 1;
                }
                else {
                    map[line]++;
                }
                if(map[line] > max) {
                    max = map[line];
                    result_line = &line;
                }
            }
        }
        return result_line;
    }
};

