/*Chương trình điều khiển robot sumo 
//  Host: Trường Đại học Giao Thông Vận Tải - Phân hiệu tại TP. Hồ Chí Minh
//  Website: https://utc2.edu.vn/
//  Website tuyển sinh: http://tuyensinh.utc2.edu.vn/
//  Website bộ môn điện-điện tử: http://dept.utc2.edu.vn/bomondientu/

*/

// motor 1
int enA = 12; // băng xung
int in1 = 11;
int in2 = 10;
// motor 2
int enB = 9; // băng xung pinMode(h_truoc2, INPUT);
int in3 = 8;
int in4 = 7;

int h_truoc2 = A1; // hong ngoai truoc2
int h_truoc = A0;  // hong ngoai truoc 1
int h_sau = A2;    // hong ngoai sau

// bien luu khoang cach
int distancef1; // cam bien sieu am 1

int distancef2; // cam bien sieu am 2

// khai bao chan cho cam bien sieu am
const int trig_f1 = 6; // chan cho cam bien sieu am 1
const int echo_f1 = 5;

const int trig_f2 = 4; // chân trig của HC-SR04
const int echo_f2 = 3; // chan camr bien sieu am

int deger = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("**********************************");

  Serial.println("*         Welcome Screen         *");

  Serial.println("*                                *");

  Serial.println("*Chào mừng bạn đến với Robot Sumo*");

  Serial.println("*                GSA            *");

  Serial.println("*                                *");

  Serial.println("*            UTC-HCMC            *");

  Serial.println("**********************************");

  delay(3000); // dieu chinh thoi gian cho tai day
  // khai bao su dung cho cam bien sieu am
  pinMode(trig_f1, OUTPUT); //xuat tin hieu ra(output)
  pinMode(echo_f1, INPUT);  //nhan tin hieu vao(input)
  pinMode(trig_f2, OUTPUT);
  pinMode(echo_f2, INPUT);
  //khai bao su dung cam bien hong ngoai truoc sau
  pinMode(h_truoc, INPUT);
  pinMode(h_sau, INPUT);
  pinMode(h_truoc2, INPUT);

  // khai bao su dung cac chan dieu khien dong co
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop()
{
  int f1 = sr04sensor1(distancef1); // phai
  int f2 = sr04sensor2(distancef2); // sr04 trai
  {
    if (f1 < 60 && f2 < 60)
    {
      deger = 1; // neu khoang cach be hon 60cm thi thuc hien lenh 1
    }
    else if (f1 > 60 && f2 > 60)
    {
      deger = 6; // neu khoang cach lon hon 60cm thi thuc hien lenh 6
    }
  }
  int front = digitalRead(h_truoc); // gan bien
  int back = digitalRead(h_sau);
  int front1 = digitalRead(h_truoc2);
  Serial.print("Cảm biến hồng ngoại trước: ");
  Serial.print(front);
  Serial.println("");
  Serial.print("Cảm biến hồng ngoại trước 2: ");
  Serial.print(front1);
  Serial.println("");
  Serial.print("Cảm biến hồng ngoại sau: ");
  Serial.print(back);
  Serial.println("");

  {

    if (front == 0 && back == 1 && front1 == 1)
    {
      deger = 2;
    }
    else if (front == 1 && back == 1 && front1 == 0)
    {
      deger = 3;
    }
    else if (front == 1 && back == 0 && front1 == 1)
    {
      deger = 4;
    }
    else if (front == 0 && back == 1 && front1 == 0)
    {
      deger = 5;
    }
  }
  /*
     cảm bien hong ngoai trả về 2 giá trị là 0 vs 1. Dựa vào đó để xác dịnh robot dang trong hay ngoài sân . Nếu robot sắp ra ngoài sân thì thực hienj các lện tương ứng như trên.
  */
  switch (deger)
  {
  case 1:
    super_forward(); // chế đọ dùng để húc robot khác
    break;

  case 2:
    backward();

    break;
  case 3:
    backward();
    break;
  case 4:
    forward(); // tiến lên
    break;
  case 5:
    backward();
    break;
  case 6:
    xoaya(); // xoay vòng tròn để kiếm các robot khác
    break;

  default:
    xoaya();
  }
}

void backward() // các chế độ điều khiển động cơ
{
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  delay(250);
}
void forward()
{
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void super_forward()
{
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  analogWrite(enA, 255); // trái
  analogWrite(enB, 255); // phải
}
void xoaya()
{
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

int sr04sensor1(int distancef1) // thư vien cho cảm biến siêu âm.
{
  unsigned long duration; // biến đo thời gian

  /* Phát xung từ chân trig */
  digitalWrite(trig_f1, 0); // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig_f1, 1); // phát xung từ chân trig
  delayMicroseconds(5);     // xung có độ dài 5 microSeconds
  digitalWrite(trig_f1, 0); // tắt chân trig

  /* Tính toán thời gian */
  // Đo độ rộng xung HIGH ở chân echo.
  duration = pulseIn(echo_f1, HIGH);
  // Tính khoảng cách đến vật.
  distancef1 = int(duration / 2 / 29.412);

  /* In kết quả ra Serial Monitor */
  Serial.print("Cảm biến siêu âm 1: ");
  Serial.print(distancef1);
  Serial.println("cm");
  return (distancef1);
  delay(50);
}

int sr04sensor2(int distancef2)
{
  unsigned long duration; // biến đo thời gian

  /* Phát xung từ chân trig */
  digitalWrite(trig_f2, 0); // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig_f2, 1); // phát xung từ chân trig
  delayMicroseconds(5);     // xung có độ dài 5 microSeconds
  digitalWrite(trig_f2, 0); // tắt chân trig

  /* Tính toán thời gian */
  // Đo độ rộng xung HIGH ở chân echo.
  duration = pulseIn(echo_f2, HIGH);
  // Tính khoảng cách đến vật.
  distancef2 = int(duration / 2 / 29.412);

  /* In kết quả ra Serial Monitor */
  Serial.print("Cảm biến siêu âm 2: ");
  Serial.print(distancef2);
  Serial.println("cm");
  return (distancef2);
  delay(100);
}