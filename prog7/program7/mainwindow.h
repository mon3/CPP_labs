#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <fstream>
#include <qwt/qwt.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_series_data.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_read_Button_clicked();

//    void on_dataTypeButton_pressed();

//    void on_dataTypeButton_released();

    void on_dataTypeButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    std::vector<double> x1, y1, x2, y2;
    double min_x1, min_y1, max_x1, max_y1, min_x2, min_y2, max_x2, max_y2;
    QGraphicsScene dataScene1;
    QGraphicsScene dataScene2;
    QwtPlot plot1 ;
    QwtPlot plot2 ;
    QwtPlotCurve *dane1;
    QwtPlotCurve *dane2;
    bool first_time_=false;

};

#endif // MAINWINDOW_H
