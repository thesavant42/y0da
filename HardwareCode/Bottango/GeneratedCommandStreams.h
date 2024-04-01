#ifndef GeneratedCommandStreams_h
#define GeneratedCommandStreams_h

#include "Arduino.h"
#include "src/BottangoCore.h"

namespace GeneratedCommandStreams
{
    //// GENERATED CODE. You probably don't need to change any of the below ////
    CommandStream *getSetupCommandStream();
    CommandStream *getCommandStream(byte streamID);
    void updatePlayStatus();

    extern CommandStream setupStream;
    extern CommandStream stream_DefaultAnimation;
    extern CommandStream stream_DefaultAnimation_loop;

} // namespace GeneratedCommandStreams

#endif
