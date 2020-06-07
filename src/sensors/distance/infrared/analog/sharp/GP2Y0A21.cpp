#include "GP2Y0A21.hpp"

namespace
{
const auto kMinDistance = 12; // GP2Y0A21's minimum distance
const auto kMaxDistance = 78; // GP2Y0A21's maximum distance
} // namespace

GP2Y0A21::GP2Y0A21(Runtime& runtime, uint8_t pin)
    : InfraredAnalogSensor(runtime)
    , kPin{ pin }
    , mRuntime(runtime)
{
}

unsigned int GP2Y0A21::getDistance()
{
    auto analogReading = mRuntime.getAnalogPinState(kPin);
    // Formula source: Jeroen Doggen http://plat.is/v3x25
    auto result = static_cast<unsigned int>(1 / (0.0002391473 * analogReading - 0.0100251467));

    return (result >= kMinDistance) && (result <= kMaxDistance) ? result : 0;
}
