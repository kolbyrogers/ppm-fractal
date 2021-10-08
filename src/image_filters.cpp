#include "ActionData.h"
#include "PPM.h"
#include "image_menu.h"

void plusEquals(ActionData &action_data)
{
    action_data.getInputImage1() += action_data.getInputImage2();
}
void minusEquals(ActionData &action_data)
{
    action_data.getInputImage1() -= action_data.getInputImage2();
}
void timesEquals(ActionData &action_data)
{
    action_data.getInputImage1() *= getDouble(action_data, "Factor? ");
}
void divideEquals(ActionData &action_data)
{
    action_data.getInputImage1() /= getDouble(action_data, "Factor? ");
}
void plus(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1() + action_data.getInputImage2();
}
void minus(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1() - action_data.getInputImage2();
}
void times(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1() * getDouble(action_data, "Factor? ");
}
void divide(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1() / getDouble(action_data, "Factor? ");
}

void grayFromRed(ActionData &action_data)
{
    PPM gray;
    action_data.getInputImage1().grayFromRed(gray);
    action_data.getOutputImage() = gray;
}
void grayFromGreen(ActionData &action_data)
{
    PPM gray;
    action_data.getInputImage1().grayFromGreen(gray);
    action_data.getOutputImage() = gray;
}
void grayFromBlue(ActionData &action_data)
{
    PPM gray;
    action_data.getInputImage1().grayFromBlue(gray);
    action_data.getOutputImage() = gray;
}
void grayFromLinearColorimetric(ActionData &action_data)
{
    PPM gray;
    action_data.getInputImage1().grayFromLinearColorimetric(gray);
    action_data.getOutputImage() = gray;
}
void orangeFilter(ActionData& action_data){
	PPM orange;
	action_data.getInputImage1().orangeFilter(orange);
	action_data.getOutputImage() = orange;
}
