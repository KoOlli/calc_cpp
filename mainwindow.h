#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "calculatorView.h"
#include "calculatorXView.h"
#include "graficsView.h"
#include "creditView.h"
#include "depositView.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
