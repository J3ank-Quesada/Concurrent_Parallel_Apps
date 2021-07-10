#include <unistd.h>
#include "ProdConsGoldbachCalculator.hpp"
#include "GoldbachCalculator.hpp"
#include "GoldbachNumbersList.hpp"
#include "GoldbachWebApp.hpp"

ProdConsGoldbachCalculator::ProdConsGoldbachCalculator(
  Queue<GoldbachWork>* consumingQueue = nullptr
  , Queue<GoldbachWork>* producingQueue = nullptr
  , const GoldbachWork& stopCondition = GoldbachWork()):
  Consumer<GoldbachWork>(consumingQueue, stopCondition)
  , Producer<GoldbachWork>(producingQueue){

}

void ProdConsGoldbachCalculator::setIntancePointers
                    (GoldbachCalculator *goldbachCalculator,
                            GoldbachWebApp *goldbachWebApp){
  this->goldbachCalculator = goldbachCalculator;
  this->goldbachWebApp = goldbachWebApp;
}


void ProdConsGoldbachCalculator::consume(const GoldbachWork& goldbachWork) {
  
  GoldbachWork work = goldbachWork;
  GoldbachNumbersList *list = work.getGoldbachNumbersList();
  for (int64_t i = 0; i < list->getListSize(); ++i) {
    // Calcule los numeros de goldbach
    // Guardeme las respuestas en la lista
    goldbachCalculator->startGoldbach(list->getGoldbachNumber(i));
  }
  this->goldbachWebApp->injectHTML(&work);
}

int ProdConsGoldbachCalculator::run() {
  consumeForever();
  return EXIT_SUCCESS;
}