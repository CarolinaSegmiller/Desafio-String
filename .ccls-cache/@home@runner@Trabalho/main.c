#include <stdio.h>
#include <string.h>

int main(void) {
  char text[1000] = "Quando trabalhar de casa e a melhor opcao, garanta que voce e sua empresa continuem conectados e produtivos durante o #TrabalhoRemoto. @jared_spataro, lider de Microsoft 365, compartilhou 3 passos para otimizar a produtividade com o #MicrosoftTeams. ", text2[1000];

  int qntHashtags = 0, qntMencoes = 0, qntA = 0, qntE = 0, qntI = 0, qntO = 0, qntU = 0;
  
  for (int i = 0; i < strlen(text); i++){
    if (text[i] == '@'){
      qntMencoes++;
    }
    else if (text[i] == '#'){
      qntHashtags++;
    }
    else if (text[i] == 'a' || text[i] == 'A'){
      qntA++;
    }
    else if (text[i] == 'e' || text[i] == 'E'){
      qntE++;
    }
    else if (text[i] == 'i' || text[i] == 'I'){
      qntI++;
    }
    else if (text[i] == 'o' || text[i] == 'O'){
      qntO++;
    }
    else if (text[i] == 'u' || text[i] == 'U'){
      qntU++;
    }
    if ((int)text[i] >= 48 && (int)text[i] <= 57){
      if (text[i - 1] == ' ' || text[i + 1] == ' '){
        text2[i] = '*';
      }
      else{
        text2[i] = '_';
      }
    }
    else{
      text2[i] = text[i];
    }
  }

  text2[strlen(text)]='\0';
  
  char hashtag[qntHashtags][50];
  int contadorhash = 0, posicaohash = 0;
  for (int m = 0; m < strlen(text); m++){
    if (text[m] == '#'){
      for (int n = m; n < strlen(text); n++){
        if((int)text[n] == 32){
          hashtag[contadorhash][posicaohash] = '\0';
          posicaohash =0;
          break;
        }
        else{
          hashtag[contadorhash][posicaohash] = text[n];
          posicaohash++;
        }
      }
      contadorhash++;
    }
  }
 

  
  printf("Existem %d menções e %d hashtags.", qntMencoes, qntHashtags);

  printf("\n\nA frequência das vogais é:\na(%d)  ", qntA);
  for (int i = 0; i < qntA; i++){
    printf("*");
  }
  
  printf("\ne(%d)  ", qntE);
  for (int i = 0; i < qntE; i++){
    printf("*");
  }

  printf("\ni(%d)  ", qntI);
  for (int i = 0; i < qntI; i++){
    printf("*");
  }

  printf("\no(%d)  ", qntO);
  for (int i = 0; i < qntO; i++){
    printf("*");
  }

  printf("\nu(%d)   ", qntU);
  for (int i = 0; i < qntU; i++){
    printf("*");
  }
  printf("\n\n\n");

  printf("%s", text2);

  printf("\n\n\n");

  for (int i = 0; i<qntHashtags; i++){
    for (int j = 0; j < strlen(hashtag[i]); j++){
    printf("%c", hashtag[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}