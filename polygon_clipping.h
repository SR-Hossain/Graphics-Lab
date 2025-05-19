#include "custom.h"
#include <bits/stdc++.h>
using namespace std;


// Checks if point is inside the clipping edge (cross product test)
inline bool isInside(const Point& p, const Point& edgeStart, const Point& edgeEnd) {
    return (edgeEnd.x - edgeStart.x) * (p.y - edgeStart.y) > 
           (edgeEnd.y - edgeStart.y) * (p.x - edgeStart.x);
}

// Main clipping function - clips polygon against convex clipWindow
inline std::vector<Point> sutherlandHodgmanClip(
    const std::vector<Point>& inputPolygon,
    const std::vector<Point>& clipWindow) {
    
    std::vector<Point> output = inputPolygon;
    
    for (size_t i = 0; i < clipWindow.size(); i++) {
        const Point& edgeStart = clipWindow[i];
        const Point& edgeEnd = clipWindow[(i + 1) % clipWindow.size()];
        std::vector<Point> input = output;
        output.clear();
        
        if (input.empty()) break;
        
        Point prev = input.back();
        for (const Point& curr : input) {
            bool currInside = isInside(curr, edgeStart, edgeEnd);
            bool prevInside = isInside(prev, edgeStart, edgeEnd);
            
            if (currInside) {
                if (!prevInside) { // Entering the window
                    Point intersect;
                    float t = ((edgeStart.x - edgeEnd.x) * (prev.y - edgeStart.y) - 
                              (edgeStart.y - edgeEnd.y) * (prev.x - edgeStart.x)) /
                             ((edgeStart.y - edgeEnd.y) * (curr.x - prev.x) - 
                              (edgeStart.x - edgeEnd.x) * (curr.y - prev.y));
                    intersect.x = prev.x + t * (curr.x - prev.x);
                    intersect.y = prev.y + t * (curr.y - prev.y);
                    output.push_back(intersect);
                }
                output.push_back(curr);
            } 
            else if (prevInside) { // Exiting the window
                Point intersect;
                float t = ((edgeStart.x - edgeEnd.x) * (prev.y - edgeStart.y) - 
                          (edgeStart.y - edgeEnd.y) * (prev.x - edgeStart.x)) /
                         ((edgeStart.y - edgeEnd.y) * (curr.x - prev.x) - 
                          (edgeStart.x - edgeEnd.x) * (curr.y - prev.y));
                intersect.x = prev.x + t * (curr.x - prev.x);
                intersect.y = prev.y + t * (curr.y - prev.y);
                output.push_back(intersect);
            }
            prev = curr;
        }
    }
    return output;
}
