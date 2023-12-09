#include "LoRaWan_APP.h"
#include "Arduino.h"

/*
 * set LoraWan_RGB to 1,the RGB active in loraWan
 * RGB red means sending;
 * RGB green means received done;
 */
#ifndef LoraWan_RGB
#define LoraWan_RGB 0
#endif

#define RF_FREQUENCY                                915000000 // Hz

#define TX_OUTPUT_POWER                             14        // dBm

#define LORA_BANDWIDTH                              0         // [0: 125 kHz,
                                                              //  1: 250 kHz,
                                                              //  2: 500 kHz,
                                                              //  3: Reserved]
#define LORA_SPREADING_FACTOR                       7         // [SF7..SF12]
#define LORA_CODINGRATE                             1         // [1: 4/5,
                                                              //  2: 4/6,
                                                              //  3: 4/7,
                                                              //  4: 4/8]
#define LORA_PREAMBLE_LENGTH                        8         // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT                         0         // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false


#define RX_TIMEOUT_VALUE                            1000
#define BUFFER_SIZE                                 30 // Define the payload size here

char txpacket[BUFFER_SIZE];
char rxpacket[BUFFER_SIZE];

static RadioEvents_t RadioEvents;

int16_t txNumber;

int16_t rssi,rxSize;

bool lora_idle = true;
bool roverConnected = false;
bool allDataReceived = false;
void setup() {
    Serial.begin(115200);

    txNumber=0;
    rssi=0;
    //RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    Radio.Init( &RadioEvents );
    Radio.SetChannel( RF_FREQUENCY );
  
    Radio.SetRxConfig( MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
                                   LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
                                   LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
                                   0, true, 0, 0, LORA_IQ_INVERSION_ON, true );

   }


void loop()
{
  if (roverConnected) {
    sendResponse();
  } else if (allDataReceived) {
    sendConfirmationToRovers();
  }
  if(lora_idle)
  {
    turnOffRGB();
    lora_idle = false;
    Serial.println("into RX mode");
    Radio.Rx(0);
  }

  delay(5000);  // Adjust as needed
}

void sendConfirmationToRovers() {
  char confirmationData[] = "Data received";
  Radio.Send((uint8_t *)confirmationData, strlen(confirmationData));
}

void sendResponse() {
  char resp[] = "sshere";
  Radio.Send((uint8_t *)resp, strlen(resp));
}

void OnTxDone(void) {
  // Handle transmission completion if needed
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr) {
  rssi=rssi;
    rxSize=size;
    memcpy(rxpacket, payload, size );
    rxpacket[size]='\0';
    turnOnRGB(COLOR_RECEIVED,0);
    Radio.Sleep( );
    Serial.printf("\r\nreceived packet \"%s\" with rssi %d , length %d\r\n",rxpacket,rssi,rxSize);
    lora_idle = true;
  
  if (strcmp((char *)payload, "Anyone!")) {
    roverConnected = true;  // Reset the connection status for the next cycle
    
  } else if (strcmp((char *)payload, "Rover telemetry data")) {
    allDataReceived = true;
    
  } 
  Serial.printf("\r\nreceived packet \"%s\" with rssi %d, length %d\r\n", payload, rssi, size);
  
}
