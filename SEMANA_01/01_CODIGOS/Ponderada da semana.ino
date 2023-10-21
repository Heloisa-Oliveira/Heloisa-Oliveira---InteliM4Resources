void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1500); // Wait for 1000 millisecond(s)
}

// Assumindo que a corrente máxima suportada pelo led é de 20mA,
// e considerando que a voltagem fornecida pela placa de Arduíno
// Uno R3 é de 3,3 V, temos que:

// Lei de Ohm:
// U = r . i
// 3,3 = r . 0,02
// r = 3,3 / 0,02
// r = 165 Ohms


// Como o próprio led possui uma resitência por volta de 68 Ohms,
// a resistência necessária para o resistor é de 97 Ohms no mínimo.