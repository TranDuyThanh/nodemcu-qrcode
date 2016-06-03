
int qrenc(const char*);

void setup()
{

  Serial.begin(115200);
  while(!Serial);
  Serial.println();
  Serial.println();
  Serial.println();

  qrenc("https://moca.vn/moca/qr/scan/464937603788");
}

void loop(){}
