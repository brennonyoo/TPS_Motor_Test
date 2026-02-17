In VS Code, install the “PlatformIO IDE” extension

Plug the Teensy 4.1 into your computer through USB

Open VS Code

Go to File then "Open Folder" and select the project folder (the one that contains platformio.ini and the src/ folder).

Build the project
Click the “Build” button in the PlatformIO toolbar, OR press Ctrl + Alt + B.

Upload the project
Click the “Upload” button in the PlatformIO toolbar, OR press Ctrl + Alt + U

If the upload does not start or says it cannot find the device:

Press the small physical “Program” button on the Teensy once, then try uploading again.

(Optional) Open the serial monitor to view messages:
Click “Monitor” in PlatformIO, OR press Ctrl + Alt + M.
After upload completes, the Teensy will reboot automatically and the motor test loop should begin running (assuming the driver/motor is powered and wired correctly).
