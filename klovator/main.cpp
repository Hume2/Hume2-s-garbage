#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const char klmp[2][2] = {{'k','l'},{'m','p'}};
const int maxiter = 30;
const float krok = 0.02f;

const float cx = -0.5305897582265553;
const float cy = -0.6696589697267967;
//x0=-0.5305897582265553 y0=-0.6696589697267967 x1=-0.5287678066010182 y1=-0.6687164843740017 w⨯h=1301x673 0.9MP

char vyhodnot(float re, float im) {
  for (int i = maxiter; i; i--) {
    float re2 = re * re;
    float im2 = im * im;
    if ((re2 + im2) > 4) break;
    im = 2 * re * im + cy;
    re = re2 - im2 + cx;
  }
  return klmp[re > 0][im > 0];
}

int main(int argc, char** arg) {
  FILE* f = fopen("out.txt", "w");
  string s = "";
  for (float i = -1; i < 1; i += krok) {
    for (float j = -1; j < 1; j += krok/2) {
      s += vyhodnot(j, i);
    }
    //cout << s << endl;
    s = s + "\n";
    fputs(s.c_str(), f);
    s.clear();
  }
  fclose(f);
  return 0;
}
