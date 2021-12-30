# K4t4sztrof4.io

hi
this is the user manual for our EMS(Electronic Measurements and Sensors) project, 3rd semester.
Our resources:
* https://developer.android.com/codelabs/build-your-first-android-app#0
<-- Android Studio Application basics
TO BE COMPLETED WITH BLUETOOTH CONNECTION, AND DISPLAY OF CHARACTERS + SOUND PLAY ON THE SECOND FRAGMENT!

* https://create.arduino.cc/projecthub/173799/a-glove-that-translate-sign-language-into-text-and-speech-c91b13
<-- Arduino code + project core:
COMMENTED OUT: THE CONSTRAIN COMMANDS, BC IT ALWAYS GAVE min/max, 0/1023 VALUES.
THE CALIBRATION PROCESS IS IN PROGRESS ALREADY, THE ARDUINO APP IS SET UP TO WRITE IN THE SERIAL MONITOR THE SENSORS' OUTPUTS.

TO BE ADJUSTED (hardware):
RIGHT CONNECTION OF THE STRECH SENSOR OF THE INDEX FINGER(THE ONE WE USE FOR POINTING).

EXCEL:
-fill out the values of the 10 tests in the case of all notes, then calculate min and max in case of the tested variables, and calibrate the device in the arduino code, meaning:
-update the if's at the end of the arduino project, using the min and max tested values.

NOTE: in case of the if's at the end of the arduino project, i completed with serial write, for testing, but by default, there was a printfun function used declared in the setup
-PRINT/TRANSMIT THE DESIRED STRING(Do, Re, Mi, ...) ON THE SCREEN/TO THE BLUETOOTH DEVICE CONTAINING THE ANDROID APPLICATION.

Password of the Bluetooth module: 1234  !!!!

Android studio - RUNNING THE APP:
use an emulator: https://developer.android.com/codelabs/build-your-first-android-app#2 (step 4!)
use a phone: https://developer.android.com/studio/run/device

