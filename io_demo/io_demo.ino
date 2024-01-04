#define hc_sck 1
#define hc_pck 2
#define hc_in  0
#define hc_uit 3

#define io_cnt 8

//Voor het oude ontwerp
#define hc_ce  4


bool in[io_cnt] =  {false,false,false,false,false,false,false,false};
bool uit[io_cnt] = {false,true ,false,false,true ,false,false,false};

void setup() {
  pinMode(hc_sck, OUTPUT);
  pinMode(hc_pck, OUTPUT);
  pinMode(hc_in, INPUT);
  pinMode(hc_uit, OUTPUT);
  pinMode(hc_ce, OUTPUT);
}

void loop() {
    
}

void io() {

  // Paralelle klokslag geven
  digitalWrite(hc_pck, LOW);
  delay(10);
  digitalWrite(hc_pck, HIGH);

  digitalWrite(hc_ce, LOW); // Nodig in oude ontwerp

  // Nu het paralelle gedeelte geklokt heeft de data serieel uitsturen en uitlezen
  for (int i = 0 ; i < io_cnt ; i++) {

    // Seriele klok laag
    digitalWrite(hc_sck, LOW);
    
    // Gewenste data zenden
    digitalWrite(hc_uit, uit[i]);
    // Data ontvangen
    in[i] = digitalRead(hc_in);
    
    // Seriele klok hoog
    digitalWrite(hc_sck, HIGH);
  }

  // Paralelle klokslag geven
  digitalWrite(hc_pck, LOW);
  delay(10);
  digitalWrite(hc_pck, HIGH);

}
