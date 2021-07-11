#include <unistd.h>
#include "ProdConsGoldbachCalculator.hpp"
#include "GoldbachCalculator.hpp"
#include "GoldbachNumbersList.hpp"
#include "GoldbachWebApp.hpp"
#include <iostream>

ProdConsGoldbachCalculator::ProdConsGoldbachCalculator(
  Queue<GoldbachWork>* consumingQueue
  , const GoldbachWork& stopCondition,
  GoldbachWebApp *goldbachWebApp):
  Consumer<GoldbachWork>(consumingQueue, stopCondition)
  ,goldbachWebApp(goldbachWebApp){
}

void ProdConsGoldbachCalculator::consume(const GoldbachWork& goldbachWork) {
  GoldbachCalculator goldbachCalculator;
  GoldbachWork work(goldbachWork);
  GoldbachNumbersList *list = work.getGoldbachNumbersList();
  for (int64_t i = 0; i < list->getListSize(); ++i) {
    // Calcule los numeros de goldbach
    // Guardeme las respuestas en la lista
    goldbachCalculator.startGoldbach(list->getGoldbachNumber(i));
  }
  this->goldbachWebApp->injectHTML(&work);
}

int ProdConsGoldbachCalculator::run() {
  consumeForever();
  return EXIT_SUCCESS;
}