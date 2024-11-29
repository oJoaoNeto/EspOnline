const int pinSensor = A0; 
// Array com pontos específicos de tensão e força
float tensoes[] = {0.0,2.02, 2.9, 3.46,3.82, 3.91, 4.04,4.21, 4.32,4.36,4.41, 4.47}; 
float forcas[] = {0.0,0.35, 0.77, 1.53,2.58, 2.99, 3.78,5.23, 6.76,7.42,8.48, 10.0}; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int valorBruto = analogRead(pinSensor); // Lê o valor bruto do ADC
  float tensao = valorBruto * (5.0 / 1024.0); // Converte o valor bruto para tensão (5V)
  
  // Cálculo da força
  float forca = interpolarForca(tensao);

  // Exibe os valores de tensão e força no serial
  Serial.print(" | ");
  Serial.print(tensao, 2); // Exibe a tensão com 2 casas decimais
  Serial.print(" V |  ");
  Serial.print(forca, 2);  // Exibe a força com 2 casas decimais
  Serial.println(" N");

  delay(1000); 
}

// Função de interpolação linear
float interpolarForca(float tensao) {
  // Interpolação linear entre os pontos conhecidos
  for (int i = 0; i < 11; i++) { // Atualizado para corresponder ao tamanho do array
    if (tensao >= tensoes[i] && tensao < tensoes[i + 1]) {
      // A interpolação linear é dada pela fórmula:
      // f = f1 + (tensao - t1) * (f2 - f1) / (t2 - t1)
      return forcas[i] + (tensao - tensoes[i]) * (forcas[i + 1] - forcas[i]) / (tensoes[i + 1] - tensoes[i]);
    }
  }
}
