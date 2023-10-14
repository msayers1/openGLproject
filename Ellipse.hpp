// ELlipse.hpp

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <stdio.h>
#include <vector>
class Ellipse
{
    private:
            float _centerX, _centerY, _radiusX, _radiusY, _angle;
            float _red, _green, _blue;
            int _numCirclePts;
            const std::vector<std::vector<float>>& _genCirclePts;
    public:
        Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
                float r, float g, float b, std::vector<std::vector<float>>& circlePts);

        // Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
        //         float r, float g, float b);

        // Ellipse();

        void draw() const; //const on a function means that this function will not modify anything.  
};  

#endif // ELLIPSE_HPP