Rover and Satellite Communication System
Overview
This project demonstrates a communication system between multiple rovers,drones and a satellite using LoRa technology. The code includes implementations for both rovers and the satellite to enable data exchange. Rovers can communicate with each other and with the satellite.

Prerequisites
Hardware

Seamuing Lora Modul SX1262
Software

Arduino IDE installed.
LoRaWAN_APP library installed in the Arduino IDE.
Setting Up the Environment
Install Arduino IDE

Download and install the Arduino IDE if not already installed.

Install CELLCube-board HTCC-AB01 Core:

Open the Arduino IDE.
Go to "File" -> "Preferences."
In the "Additional Boards Manager URLs" field, enter the URL for the CELLCube-board HTCC-AB01 board package.
The URL might look something like: https://example.com/package_cellcube_index.json
Click "OK" to close the Preferences window.
Install Board Package:

Go to "Tools" -> "Board" -> "Boards Manager..."
Search for "CELLCube" or the name of the package associated with the CELLCube-board HTCC-AB01.
Click on the entry and click the "Install" button.
Select CELLCube-board HTCC-AB01:

After installation, go to "Tools" -> "Board" and select the CELLCube-board HTCC-AB01 from the list.



Set the appropriate frequency in the LORA_BAND variable in both rover and satellite code. (e.g., 915000000 Hz)
Upload Code

Connect each rover and satellite to the computer using USB.
Open the respective Arduino sketches (sender.ino for rovers and drones, satellite.ino for the satellite) in the Arduino IDE.
Verify and upload the code to each board.
Monitor Serial Output

Open the Serial Monitor in the Arduino IDE for each rover and the satellite.
View debug messages to monitor the communication.
Interact with Rovers

Rovers will send telemetry data to the satellite periodically.
Once all data is received, the satellite will send a confirmation message back.
Adjust Delays

Modify delay values in the code according to your project requirements.
Additional Notes
Customize the code to fit the specific needs of your project.
Implement security measures and error checking for robust communication.
Consider power-saving strategies for rover sleep modes.