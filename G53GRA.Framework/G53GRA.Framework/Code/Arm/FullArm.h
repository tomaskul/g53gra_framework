//
// Created by ghost on 08/03/19.
//

#ifndef G53GRA_FRAMEWORK_FULLARM_H
#define G53GRA_FRAMEWORK_FULLARM_H

#include <Interface/DisplayableObject.h>

class FullArm :
	public DisplayableObject
{
public:
	FullArm(double arm_girth, bool isLeft);
	~FullArm() {};

	void Display();

private:
	void DrawFullArm();

	void DrawForearm();
	void DrawUpperarm();

	const double SHOULDER_OFFSET = 9;
	const double ARM_BEND_ANGLE = 70;
	const double ARM_WIDTH_HEIGHT = 5;

	double m_arm_girth;
	bool m_is_left;
};

#endif