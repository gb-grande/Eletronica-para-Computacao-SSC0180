//constantes
const int MAX_LVL = 100;
const int VELOCITY = 1000;
const int VELOCITY_DECREASE = 50;
//pinos dos leds

//pinos que acendem as luzes
const int LEDS[] = {2,3,4,5};
//pinos que recebem o input do botão
const int LEDS_IN[] = {10, 11, 12, 13};
const int LED_COUNT = 4;
//pinos das leds de certo ou errado
const int RIGHT_LED = 8;
const int WRONG_LED = 9;

int sequence[MAX_LVL];
int lvl = 0;
bool playerTurn = false;

//função de inicialização
void setup()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    //coloca os pinos no modo certo
    pinMode(LEDS[i], OUTPUT);
    pinMode(LEDS_IN[i], INPUT);
    //deixa o LED desligado por default
    digitalWrite(LEDS[i], LOW);
  }
  //coloca os pinos no modo certo
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(WRONG_LED, OUTPUT);
}
// chamada repetidamente ao enquanto o arduino está ligado
void loop()
{
  if (!playerTurn)
  {
    if (lvl == MAX_LVL)
    {
      quickFlash(RIGHT_LED);
      delay(200);
      return;
    }
    //garante que o numero gerado sera random
    randomSeed(millis());
    //preenche o proximo item da sequencia e continua o turno
    sequence[lvl] = LEDS[random(LED_COUNT)];
    lvl++;
    playSequence();
    playerTurn = true;
    return;
  }
  for (int i = 0; i < lvl; i++)
  {
  	int input;
    //enquanto nao for lido input, continuar esperando
    do{
      input = readInput();
    } while (input == -1);
    
    if (input != sequence[i])
    {
      wrongSequence();
      return;
    }
  }
  
  rightSequence();
  
}

//Acende e apaga um LED rapidamente
void quickFlash(int led)
{
	digitalWrite(led, HIGH);
  	delay(200);
  	digitalWrite(led, LOW);
}

void wrongSequence()
{
  for (int i = 0; i < 3; i++)
  {
    quickFlash(WRONG_LED);
    delay(100);
  }
  delay(300);
  //reinicia o jogo e começa a preencher do 0 o array das corretas
  lvl = 0;
  playerTurn = false;
}

void rightSequence()
{
  for (int i = 0; i < 2; i++)
  {
    quickFlash(RIGHT_LED);
    delay(100);
  }
  delay(300);
  playerTurn = false;
}

//funcao que pisca a sequencia a ser lembrada pelo usuario
void playSequence()
{
  for (int i = 0; i < lvl; i++){
  	digitalWrite(sequence[i], HIGH);
    //quanto maior o level, menor o delay, menos tempo para lembrar
    delay(VELOCITY - lvl*VELOCITY_DECREASE);
    digitalWrite(sequence[i], LOW);
    delay(200);
  }
}

//funcao que le o input do botao
int readInput()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
  	int read = digitalRead(LEDS_IN[i]);
    //se apertado = LOW
    if (read == LOW){
      quickFlash(LEDS[i]);
      return LEDS[i];
    }
  }
  return -1;
}
