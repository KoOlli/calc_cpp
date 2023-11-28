#include "calculatorView.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorView w;
    w.show();

//    w.setWindowIconText(":/img/icon.png");
    CalculatorXView win;
    GraficsView window;
    return a.exec();
}
