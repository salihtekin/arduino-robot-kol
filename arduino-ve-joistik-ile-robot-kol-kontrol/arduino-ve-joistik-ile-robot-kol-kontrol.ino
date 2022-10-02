#include <Servo.h>

Servo motor1SagSolHareket, motor2YukariAssagiHareket  // Motorların hareket edecekleri konumlara göre isimlendirme yapıldı

int joyXPin  = A0;                                     // joyistik x ekseni için arduino üzerinde bağlandığı analog giriş değeri.
int joyYPin  = A2;                                     // joyistik Y ekseni için arduino üzerinde bağlandığı analog giriş değeri.
int butonPin = 2;

// Aşşağıdaki değişkenler robot kolun ilk durumunu sıfıra çekmek için yapıldı.
int xPozisyonu  = 0;
int yPozisyonu  = 0;
int butonDurumu = 0;

void setup() {

  Serial.begin(9600);
  pinMode(joyXPin, INPUT);
  pinMode(joyYPin, INPUT);
  pinMode(butonPin, INPUT_PULLUP);
  motor1SagSolHareket.attach(9);
  motor2YukariAssagiHareket.attach(10);
}

void loop() {
  if (xPozisyonu >= 0 && xPozisyonu <= 1023)  // SAG/SOL
  {
    MotorSagSolHareket();

  } else if (yPozisyonu1 >= 0 && yPozisyonu1 <= 1023)  // asagı/yukarı
  {
    MotorYukariAssagiHareket();
  }
}

void MotorSagSolHareket() {
  int servoMotor1 = xPozisyonu;                     // Gelen veriyi yeni bir değşken tanımlayarak servo açsını yazdırır.Diğer değişkende herhangi bir değişikilik yapmamak için bu tarz bir işlem yaptım.
  servoMotor1     = map(servoMotor1, 0, 1023, 0, 180);
  motor1SagSolHareket.write(servoMotor1);           // Tanımlanan değişken servonun açısal değeri olarak yazıldı.
  delay(10);                                        // Hareketin çok hızlı olamamsı için yazdım.Çok hızlı olursa deley değerini test ederek değiştirirsiniz.
}

void MotorYukariAssagiHareket() {

  int servoMotor2 = yPozisyonu;  
  servoMotor2     = map(servoMotor2, 0, 1023, 0, 180);
  ileri.write(servoMotor2); 
  delay(10);          
}

//Bu kod test edilemeden yazıldı o yüzden hatalar olabilir.Hatalarını kontrol edip geri dönüş yaparsınız.
//SALİH TEKİN-------------------------------------------------------------------------------------------