#include <rdm6300.h>
#define RDM_RX 10 //Pino RX do controlador para o TX do Leitor
const int relay = 8; //Relé para a tranca (PROERD É UM PROBLEMA, AS DROGAS SÃO A SOLUÇÃO)
const int buzzer = 12;
Rdm6300 rdm6300;
long int reader = rdm6300.get_tag_id(); //Endereço de memória para UID sendo lido.
long int UID = 3901833; //Tag permitida, valores em Hexadecimal.

void setup ()
{
  Serial.begin (9600);
  rdm6300.begin(RDM_RX);
  pinMode (relay, OUTPUT);
  Serial.println ("\nAproxime Cartão ou Chaveiro:\n");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop ()
{
  digitalWrite (relay, LOW); //Relé desativado em estado alto
    if (rdm6300.get_new_tag_id())
  {
    Serial.println (rdm6300.get_tag_id());
    delay(50);
    Serial.println (reader);
    if (reader == 3901833)
    {
      digitalWrite (relay, HIGH);
      delay(500);
      tone (buzzer, 440);
      delay(1000);
      noTone(buzzer);
    }
    else
    {
      digitalWrite (LED_BUILTIN, HIGH);
    }  
  }


}
int writer ()
{
  
}
