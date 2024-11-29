int fsrPin = 0;     
int fsrReading;    
int fsrVoltage;     
unsigned long fsrResistance;  
unsigned long fsrConductance; 
float fsrForce;
void setup(void) {
  Serial.begin(9600);   
}

void loop(void) {
  fsrReading = analogRead(fsrPin);  
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

  // A leitura analógica varia de 0 a 1023, mapeando para 0V a 5V (5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  Serial.print("Voltage reading in mV = ");
  Serial.println(fsrVoltage);

  if (fsrVoltage == 0) {
    Serial.println("No pressure");
  } else {
    // Calculando a resistência do FSR
    fsrResistance = 5000 - fsrVoltage;// Subtrai a tensão medida de 5V
    fsrResistance *= 10000;// Multiplica pelo resistor de 10K
    fsrResistance /= fsrVoltage;// Divide pela tensão medida
    Serial.print("FSR resistance in ohms = ");
    Serial.println(fsrResistance);

    // Calculando a condutância (1 / resistência)
    fsrConductance = 1000000;           //microMhos 
    fsrConductance /= fsrResistance;
    Serial.print("Conductance in microMhos: ");
    Serial.println(fsrConductance);

    // Estimativa da força com base na condutância
    if (fsrConductance <= 1000) {
      fsrForce = (float)fsrConductance / 80.0;
    } else {
      fsrForce = (float)(fsrConductance - 1000) / 30.0;
    }

    //laço para arredondar o valor
    if (fsrForce < 1.0) {
      fsrForce = 1.0; 
    } else {
      fsrForce = round(fsrForce);  
    }

    
    Serial.print("Force in Newtons: ");
    Serial.print(fsrForce);  
    Serial.println(" N");
  }
  Serial.println("--------------------");
  delay(1000); 
}

