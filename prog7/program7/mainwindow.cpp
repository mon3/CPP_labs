#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsWidget>

void read_data(std::vector<double>* x, std::vector<double>* y, bool choice)
{
    const char* plik;

          if(choice == 1)
          {
              std::cout<< "plik2 "<< std::endl;
              plik = "/media/monika03/Particles/CPP/szpcpp2016_program7_dane2.txt";

          }
          else
          {
              std::cout<< "plik1 "<< std::endl;

            plik = "/media/monika03/Particles/CPP/szpcpp2016_program7_dane1.txt";

          }
          std::ifstream file(plik);
          float dana_x, dana_y;
          while(file>>dana_x>>dana_y){
              (*x).push_back(dana_x);
              (*y).push_back(dana_y);
               std::cout<<dana_x<<" " << dana_y << std::endl;
          }

      file.close();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plot1.setFixedSize (650, 200);
    plot1.setAxisScale(QwtPlot::xBottom,0.0,0.1);
    plot1.setAxisScale(QwtPlot::yLeft,-10.0,10.0);

    plot2.setFixedSize (650, 200);
    plot2.setAxisScale(QwtPlot::xBottom,0.0,0.1);
    plot2.setAxisScale(QwtPlot::yLeft,-11.0,11.0);

    ui->plotq2->setScene(&dataScene1);


}

MainWindow::~MainWindow()
{
    delete dane1;
    delete dane2;
    delete ui;
}




void MainWindow::on_read_Button_clicked()
{
    if (x1.size()==0){
    read_data(&x1, &y1, 0);
    }

  if (x2.size()==0){
    read_data(&x2, &y2, 1);
}
//         for (double ai : x2) std::cout<<ai;


    auto minx1 = std::min_element( (x1).begin(), (x1).end() );
    auto maxx1 = std::max_element((x1).begin(),(x1).end() );
    auto miny1 = std::min_element( (y1).begin(), (y1).end() );
    auto maxy1 = std::max_element( (y1).begin(),(y1).end() );

    auto minx2 = std::min_element( (x2).begin(), (x2).end() );
    auto maxx2 = std::max_element( (x2).begin(), (x2).end() );
    auto miny2 = std::min_element( (y2).begin(), (y2).end() );
    auto maxy2 = std::max_element( (y2).begin(), (y2).end() );

    min_x1 = *minx1;
    min_x2 = *minx2;
    min_y1 = *miny1;
    min_y2 = *miny2;
    max_x1 = *maxx1;
    max_x2 = *maxx2;
    max_y1 = *maxy1;
    max_y2 = *maxy2;

//    std::cout << max_x1 << std::endl;

    // tworzenie curve dla dane 1

    if(dane1 == nullptr)
    {
        dane1 = new QwtPlotCurve("dane1");

            // Wprowadzenie punktów pomiarowych (dwie możliwości)
            (*dane1).setRawSamples(x1.data(), y1.data(), x1.size()); // oryginalne tablice
            (*dane1).setSamples (x1.data(), y1.data(), x1.size()); // twarde kopie danych
            // Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
            (*dane1).setStyle (QwtPlotCurve::Dots);
            // Ustawienie „pióra”: kolor, grubość:
            (*dane1).setPen (QPen (Qt::blue, 2));
        // ustawiamy skalę na osiach


            plot1.setAxisScale(0, *minx1, *maxx1);
            plot1.setAxisScale (1, *miny1, *maxy1);

            std::cout<< "minx1 = " << *minx1 << " maxx1 = " << *maxx1 << std::endl;
            std::cout<< "miny1 = " << *miny1 << " maxy1 = " << *maxy1 << std::endl;
            std::cout<< "minx2 = " << *minx2 << " maxx2 = " << *maxx2 << std::endl;
            std::cout<< "miny2 = " << *miny2 << " maxy2 = " << *maxy2 << std::endl;


            (*dane1).attach(&plot1);
//            dataScene1.addWidget(&plot1);

}
            // tworzenie curve dla dane2

    if(dane2 == nullptr)
    {
        dane2 = new QwtPlotCurve("dane2");

            // Wprowadzenie punktów pomiarowych (dwie możliwości)
            (*dane2).setRawSamples(x2.data(), y2.data(), x2.size()); // oryginalne tablice
            (*dane2).setSamples (x2.data(), y2.data(), x2.size()); // twarde kopie danych
            // Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
            (*dane2).setStyle (QwtPlotCurve::Dots);
            // Ustawienie „pióra”: kolor, grubość:
            (*dane2).setPen (QPen (Qt::green, 2));
            plot2.setAxisScale(QwtPlot::xBottom, min_x2, max_x2);
            plot2.setAxisScale(QwtPlot::yLeft, min_y2, max_y2);


            (*dane2).attach(&plot2);
//            dataScene2.addWidget(&plot2);

            dataScene1.addWidget(&plot1);
            dataScene1.addWidget(&plot2);

}


}

//void MainWindow::on_dataTypeButton_pressed()
//{
//    std::cout << "Wchodze data button! " << std::endl;
//    // pokaz dane surowe - 1
//    ui->plotq2->setScene(&dataScene1);
//    ui->plotq2->update();
//    ui->plotq2->show();
//}

//void MainWindow::on_dataTypeButton_released()
//{
//    std::cout << "Wchodze off data button! " << std::endl;

//    // pokaz wygladzone dane - 2
//     ui->plotq1->setScene(&dataScene2);
//     ui->plotq1->show();
//}

void MainWindow::on_dataTypeButton_toggled(bool checked)
{

    if (checked == 1)
    {
        if(dataScene1.hasFocus())
        {
        dataScene1.removeEventFilter(&plot2);
        dataScene1.clear();
        }
//        if(!first_time_)
//        ui->plotq2->setScene(&dataScene1);

        dataScene1.addWidget(&plot1);
//        dataScene2.addWidget(&plot2);
//        dataScene1.setActiveWindow((QGraphicsWidget*)(&plot1));
          first_time_ = true;
        std::cout << "raw data " << std::endl;
    }
    else if (checked == 0)
    {
        std::cout << "modified data " << std::endl;
        if(dataScene1.hasFocus())
        {
        dataScene1.removeEventFilter(&plot1);
        dataScene1.clear();
        }
//        std::cout << "before" << std::endl;

        dataScene1.addWidget(&plot2);

//        std::cout << "after " << std::endl;

//        ui->plotq2->setScene(&dataScene1);
//        dataScene1.setActiveWindow((QGraphicsWidget*)(&plot2));


    }

    ui->plotq2->update();
    ui->plotq2->show();
//    ui->plotq1->setScene(&dataScene2);
//    ui->plotq1->update();
//    ui->plotq1->show();

}
