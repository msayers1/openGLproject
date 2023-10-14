// Ellipse.cpp

#include "Ellipse.hpp"
#include <cmath>
//	User headers
#include "glPlatform.h"


const int numCirclePts = 24;

float angleStep = 2.f*M_PI/numCirclePts;



Ellipse::Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
                float r, float g, float b, std::vector<std::vector<float>>& circlePts)
// Ellipse::Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
//                 float r, float g, float b)
    : _centerX(centerX),
      _centerY(centerY),
      _angle(angle),
      _radiusX(radiusX),
      _radiusY(radiusY),
      _red(r),
      _green(g),
      _blue(b),
	  _genCirclePts(circlePts)
{
    float angleStep = 2.f*M_PI/numCirclePts;
	// for (int k=0; k<numCirclePts; k++)
	// {
	// 	float theta = k*angleStep;
	// 	_genCirclePts[k][0] = cosf(theta);
	// 	_genCirclePts[k][1] = sinf(theta);
	// }

}


void Ellipse::draw() const {
    //	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(_centerX, _centerY, 0.f);
	
    // apply the rotation
    glRotatef(_angle, 0.f, 0.f, 1.f);

	//	apply the radius as a scale
	glScalef(_radiusX, _radiusY, 1.f);
	
	glColor3f(_red, _green, _blue);
	glBegin(GL_POLYGON);
			for (int k=0; k<_genCirclePts.size(); k++)
				glVertex2f(_genCirclePts[k][0],
						   _genCirclePts[k][1]);
	glEnd();
	
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}   