#define left 7
#define center 10
#define right 8

//motor one
#define ENA 6
#define IN1 2 // left motor (back)
#define IN2 3 // left motor (front)

//motor two
#define ENB 9
#define IN3 4 // right motor (front)
#define IN4 5 // right motor (back)

int Speed = 100; // speed of this robot

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, 100);//150
  analogWrite(ENB, 100);//123
}

void loop() {
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);

  Serial.print(rightV);
  Serial.print(centerV);
  Serial.print(leftV);
  Serial.println("X");


  if (leftV == 0 && centerV == 1 && rightV == 0) {
    carforward();
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnright();
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnleft();
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnright();
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnleft();
  }
}

void carforward() {
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}