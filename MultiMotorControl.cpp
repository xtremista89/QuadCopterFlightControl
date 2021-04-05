#include "MultiMotorControl.h"
#include "ThrottleControl.h"

using namespace std;

MultiMotorControl::MultiMotorControl(uint8_t motorsCount, uint8_t* pins, bool bidirectional)
{
    motors = new ThrottleControl*[motorsCount];
    for (int i = 0; i < motorsCount; i++)
    {
        motors[i] = new ThrottleControl(pins[i], bidirectional);
    }
}

ThrottleControl* MultiMotorControl::getMotor(uint8_t i)
{
    return motors[i];
}