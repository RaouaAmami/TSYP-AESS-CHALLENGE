#include "LoRaWan_APP.h"
#include "Arduino.h"

#ifndef LoraWan_RGB
#define LoraWan_RGB 0
#endif

#define RF_FREQUENCY 915000000 // Hz
#define TX_OUTPUT_POWER 14     // dBm

#define LORA_BANDWIDTH 0       // [0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved]
#define LORA_SPREADING_FACTOR 7 // [SF7..SF12]
#define LORA_CODINGRATE 1       // [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
#define LORA_PREAMBLE_LENGTH 8   // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 0    // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false

#define RX_TIMEOUT_VALUE 1000
#define BUFFER_SIZE 30 // Define the payload size here

char txpacket[BUFFER_SIZE];
bool lora_idle = true;

static RadioEvents_t RadioEvents;


void OnTxDone(void);
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);

bool isConnected = false;
bool dataSent = false;


void setup() {
  Serial.begin(115200);

  RadioEvents.TxDone = OnTxDone;
  RadioEvents.TxTimeout = OnTxTimeout;
  Radio.Init(&RadioEvents);
  Radio.SetChannel(RF_FREQUENCY);
  Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                    LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                    LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                    true, 0, 0, LORA_IQ_INVERSION_ON, 3000);
  }

void loop() {
  checkConnexion();
  if (isConnected) {
    // Check for connected peers
    // If connected, send data
    sendTelemetry();
  } else if (dataSent) {
    goToSleep();
  }

  delay(5000);  // Adjust as needed
}

void sendTelemetry() {
  char telemetryData[] = "Rover telemetry data";
  Radio.Send((uint8_t *)telemetryData, strlen(telemetryData));
  dataSent = true;
}

void sendConfirmation() {
  char confirmationData[] = "Data sent successfully";
  Radio.Send((uint8_t *)confirmationData, strlen(confirmationData));
  dataSent = true;
}
void checkConnexion() {
  char checkconnexion[] = "Anyone!";
  Radio.Send((uint8_t *)checkconnexion, strlen(checkconnexion));
}

void goToSleep() {
  // Implement logic to put the rover into sleep mode
  // This may involve shutting down unnecessary components, setting sleep modes, etc.
  Serial.println("Going to sleep...");
  delay(1000);  // Allow time for serial messages to be transmitted
  // Implement sleep mode code here
}

void OnTxDone(void) {
  turnOffRGB();
  Serial.println("TX done......");
  lora_idle = true;
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr) {
  // Handle received data from the satellite
  
  if (strcmp((char *)payload, "sshere")) {
    isConnected = true;  // set the connection status for the next cycle
    dataSent = false;  // Reset dataSent flag for the next cycle
  } else if (strcmp((char *)payload, "Data received")) {
    isConnected = false;  // Reset the connection status for the next cycle
    dataSent = true;  // Reset dataSent flag for the next cycle
  }
}
void OnTxTimeout(void) {
  turnOffRGB();
  Radio.Sleep();
  Serial.println("TX Timeout......");
  lora_idle = true;
}
