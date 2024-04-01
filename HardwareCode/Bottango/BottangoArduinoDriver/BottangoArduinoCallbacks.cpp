#include "BottangoArduinoCallbacks.h"
#include "src/AbstractEffector.h"
#include "src/Log.h"

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

namespace Callbacks
{
    SoftwareSerial mySoftwareSerial(9, 8); // RX, TX 
    DFRobotDFPlayerMini myDFPlayer;
    bool registered = false;

    void onThisControllerStarted()
    {
    }

    void onThisControllerStopped()
    {
    }

    void onEarlyLoop()
    {
    }

    void onLateLoop()
    {
    }
    // !! CALLBACKS !! //

    void onEffectorRegistered(AbstractEffector *effector)
    {
        char effectorIdentifier[9];
        effector->getIdentifier(effectorIdentifier, 9);

        if (strcmp(effectorIdentifier, "Seagulls") == 0)
        {
            registered = true;
            //Serial.begin(115200);
            mySoftwareSerial.begin(9600);
            Serial.begin(115200);
            Serial.println();
            Serial.println(F("DFRobot DFPlayer Mini"));
            Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
            Serial.println(F("DFPlayer Mini online."));
            if (!myDFPlayer.begin(mySoftwareSerial))
            { //Use softwareSerial to communicate with mp3.
                Serial.println(F("Unable to begin:"));
                Serial.println(F("1.Please recheck the connection!"));
                Serial.println(F("2.Please insert the SD card!"));
                // while (true);
            }
            Serial.println(F("DFPlayer Mini online."));
            myDFPlayer.volume(30); //Set volume value. From 0 to 30
            Serial.println(F("Passed volume"));
        }
    }

    void onEffectorDeregistered(AbstractEffector *effector)
    {
    }

    void effectorSignalOnLoop(AbstractEffector *effector, int signal)
    {
    }

    void onCurvedCustomEventMovementChanged(AbstractEffector *effector, float newMovement)
    {
    }

    void onOnOffCustomEventOnOffChanged(AbstractEffector *effector, bool on)
    {
    }

    void onTriggerCustomEventTriggered(AbstractEffector *effector)
    {
        char effectorIdentifier[9];
        effector->getIdentifier(effectorIdentifier, 9);

        if (strcmp(effectorIdentifier, "Seagulls") == 0)
        {
            Serial.println(F("About to play"));
            myDFPlayer.play(1); //play specific mp3 in SD:/MP3/0001.mp3; File Name(0~65535)
            Serial.println(F("After play mp3"));
        }
    }

    void onColorCustomEventColorChanged(AbstractEffector *effector, byte newRed, byte newGreen, byte newBlue)
    {
    }

    bool isStepperAutoHomeComplete(AbstractEffector *effector)
    {
        return false;
    }
} // namespace Callbacks
