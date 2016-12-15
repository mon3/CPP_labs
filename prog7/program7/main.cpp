#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QTextCodec>
#include <QMessageBox>
#include <qwt/qwt.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_series_data.h>
#include <qwt/qwt_point_3d.h>

#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Tworzenie okna programu
    MainWindow w;

    w.setWindowTitle ("Analiza"); // ustawia tytuł okna
    w.setFixedSize (900, 600); // rozmiar okna 800x800
    // (...) rysowanie na oknie

    w.show();

    return a.exec();
}
