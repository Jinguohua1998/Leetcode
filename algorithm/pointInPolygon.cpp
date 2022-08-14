
#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
};
//判断点是否在闭合区域内
bool IsPointInPolygon(Point p, vector<Point> points)
{
//vector<Point> points:表示闭合区域由这些点围成
	double minX = points[ 0 ].x;
	double maxX = points[ 0 ].x;
	double minY = points[ 0 ].y;
	double maxY = points[ 0 ].y;
	for ( unsigned int i = 1 ; i < points.size() ; i++ )
	{
		Point q = points[ i ];
		minX = min( q.x, minX );
		maxX = max( q.x, maxX );
		minY = min( q.y, minY );
		maxY = max( q.y, maxY );
	}
 
	if ( p.x < minX || p.x > maxX || p.y < minY || p.y > maxY )
	{
		return false;
	}
 
	bool inside = false;
	for ( unsigned int i = 0, j = points.size() - 1 ; i < points.size() ; j = i++ )
	{
		if ( ( points[ i ].y > p.y ) != ( points[ j ].y > p.y ) &&
			p.x < ( points[ j ].x - points[ i ].x ) * ( p.y - points[ i ].y ) 
            / ( points[ j ].y - points[ i ].y ) + points[ i ].x )
		{
			inside = !inside;
		}
	}
 
	return inside;
}