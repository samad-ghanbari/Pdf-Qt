#include <QApplication> // Not QCoreApplication
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QPagedPaintDevice>
#include <QPen>
#include <QFont>
#include <QColor>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Qt 5
//    QPainter *painter = new QPainter();

//    QPrinter *printer = new QPrinter(QPrinter::ScreenResolution);
//    printer->setOutputFormat(QPrinter::PdfFormat);
//    printer->setOrientation(QPrinter::Landscape);
//    printer->setPaperSize(QPrinter::A3);
//    printer->setOutputFileName("test.pdf");
//    printer->setCreator("Application");
//    printer->setDocName("Report");
//    printer->setPrintProgram("The Application");

//    if(painter->begin(printer)) // QPaintDevice : printer
//    {
//        painter->resetTransform();
//        QRect rect(10,10, painter->viewport().width()-20, 100);
//        painter->fillRect(rect, QColor(150, 200, 150));
//        painter->setPen(Qt::blue);
//        painter->setFont(QFont("arial",20));
//        painter->drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, QString("Qt 5.12"));
//        painter->drawRect(rect);
//        painter->drawLine(200,200, 400,400);
//        painter->drawEllipse(400,400, 200, 50);

//        rect = QRect(0,500, painter->viewport().width()-20, 200);
//        painter->fillRect(rect, Qt::yellow);
//        painter->save();
//        painter->setPen(Qt::red);
//        painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, "Text-Left");
//        painter->restore();
//        painter->drawText(rect, Qt::AlignRight | Qt::AlignVCenter, "Text-Right");

//        painter->translate(80, 80);
//        painter->drawText(20,20, "Samad Ghanbari");


//        painter->end();
//    }
//    else
//    {
//        qDebug() << "error";
//    }


    // Qt 6

    QPainter *painter = new QPainter();
    QPrinter *printer = new QPrinter(QPrinter::ScreenResolution);

    printer->setPageOrientation(QPageLayout::Landscape);
    printer->setPageSize(QPageSize::A3);
    printer->setDocName("Qt-6 Report");
    printer->setCreator("Samad Ghanbari");
    printer->setOutputFileName("Qt6.pdf");

    painter->begin(printer);

    QRect rec(0,0, painter->viewport().width(), 200);
    painter->fillRect(rec,Qt::darkGray);
    painter->drawText(rec, Qt::AlignVCenter, "Qt-6 text");

    painter->setPen(Qt::green);
    painter->drawEllipse(100,100,200,200);

    painter->end();



    return a.exec();
}
