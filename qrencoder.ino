
int qrenc(const char*);

void setup()
{

  Serial.begin(115200);
  while(!Serial);
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println("Silicon Straits Saigon welcome");

  qrenc("Game start");
}

void loop(){}
