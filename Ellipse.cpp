// Ellipse.cpp

#include "Ellipse.hpp"
const int numCirclePts = 24;s

Ellipse::Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
                float r, float g, float b)
    : _centerX(centerX),
      _centerY(centerY),
      _angle(angle),
      _radiusX(radiusX),
      _radiusY(radiusY),
      _red(r),
      _green(g),
      _blue(b)
{
    
}

void Ellipse::draw() const {
    //	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(centerX, centerY, 0.f);
	
    // apply the rotation
    glRotatef(angle, 0.f, 0.f, 1.f);

	//	apply the radius as a scale
	glScalef(scaleX, scaleY, 1.f);
	
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
			for (int k=0; k<numCirclePts; k++)
				glVertex2f(circlePts[k][0],
						   circlePts[k][1]);
	glEnd();
	
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}   