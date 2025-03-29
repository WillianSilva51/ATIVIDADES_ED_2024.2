#include "Circle.h"

Circle::Circle() : m_center(Point(0, 0)), m_radius(1) {}

Circle::Circle(Point &p, double radius) : m_center(p), m_radius(radius) {}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}

void Circle::setCenter(Point &p)
{
    m_center = p;
}

Point &Circle::getCenter()
{
    return m_center;
}

double Circle::getRadius()
{
    return m_radius;
}

double Circle::area()
{
    return M_PI * pow(m_radius, 2);
}

bool Circle::contains(Point &p)
{
    return m_center.distance(p) <= m_radius;
}