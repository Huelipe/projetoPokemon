#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * \brief Executa um Beep em uma frequencia durante um tempo
 *
 * \param frequency frequencia do beep em hz
 * \param time tempo em milisegundos
 *
 * Executa um Beep em uma frequencia durante um tempo
 */
 void Beep( float frequency, float time ){
  char comando[255];
  sprintf(comando, "play -nq -t alsa synth %f tri %f", time/1000, frequency);
  system(comando);

  //system("clear");
  return;
}// Beep

void Sleep(int time){
  usleep((time-100)*1000);
}// Sleep

int main() {
  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(293.66, 500); // D4
  Beep(349.23, 250); // F4
  Beep(293.66, 250); // D4
  Beep(220, 750); // Lá3

  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(293.66, 500); // D4
  Beep(349.23, 250); // F4
  Beep(293.66, 250); // D4
  Beep(220, 750); // Lá3

  Beep(293.66, 250); // D4
  Beep(392, 500); // G4
  Beep(349.23, 250); // F4
  Beep(293.66, 500); // D4

  Beep(146.83, 250); // D3
  Beep(196, 500); // G3
  Beep(174.61, 250); // F3
  Beep(146.83, 500); // D3
  Beep(110, 250); // A2
  Beep(146.83, 500); // D3

  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(293.66, 500); // D4
  Beep(349.23, 250); // F4
  Beep(293.66, 250); // D4
  Beep(220, 750); // Lá3

  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(220, 250); // Lá3
  Beep(293.66, 500); // D4
  Beep(349.23, 250); // F4
  Beep(293.66, 250); // D4
  Beep(220, 750); // Lá3

  return 0;
}// main