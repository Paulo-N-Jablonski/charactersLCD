#include <LiquidCrystal.h>

// Configuração dos pinos do LCD com as entradas fornecidas
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Arrays com mensagens
const char* mensagensAleatorias[] = {"Msg 1 Aleatoria", "Msg 2 Aleatoria", "Msg 3 Aleatoria"};
const char* mensagensFixas[] = {"Complemento 1", "Complemento 2", "Complemento 3"};
int totalMensagens = 3;

// Variáveis para o temporizador
unsigned long tempoAnterior = 0;
const long intervalo = 3000; // Intervalo maior para testes

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial para debug
  lcd.begin(16, 2);    // Inicializa o LCD 16x2

  // Mensagem de teste inicial para validar o LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Teste LCD");
  delay(2000); // Aguarda 2 segundos para a mensagem inicial
}

void loop() {
  unsigned long tempoAtual = millis();

  // Verifica se o tempo de exibição de mensagem já passou
  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // Seleciona uma mensagem aleatória
    int indice = random(totalMensagens);
    
    Serial.print("Exibindo mensagem: ");
    Serial.println(mensagensAleatorias[indice]); // Imprime no Serial para debug

    // Exibe a mensagem aleatória na linha superior
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(mensagensAleatorias[indice]);
    
    // Exibe a mensagem complementar fixa na linha inferior
    lcd.setCursor(0, 1);
    lcd.print(mensagensFixas[indice]);
  }
}
